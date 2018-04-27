/*
 * DebuggerLogger.c
 *
 *  Created on: Apr 22, 2018
 *      Author: cromwelldev
 */

#include "DebugLogger.h"
#include "FatFSAccessor.h"
#include "lib/time/timeManagement.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "lwip/debug.h" /* lwip */
#include "BootLPCMod.h"

#define MaxBuffSize 1024

#define LogRotationDepth 5

#define logFilename "xblast.log"
static const char* const ActiveLogFileLocation = "MASTER_X:" PathSep logFilename;

static unsigned char initDone = 0;
static FIL activeLogHandle; /* _FS_LOCK has an extra slot to account for this file which isn't handled in FatFsAccessor */

#define SizeOfTempBuffer 8 * 1024   /* 8KB */
/* Should be dynamic to free once useless but MMU isn't up at that time */
static char tempBufBeforeHDDInit[SizeOfTempBuffer];
static unsigned int cursorInBuf = 0;

static void processTempBuf(void);
static void stringFormat(const char* const debugFlag, unsigned char logLevel, const char* const functionName, const char* const buffer, const va_list* vargs);
static void writeString(const char* const string, unsigned char writeToLogFile);
static void put(unsigned char writeToFile, const char* const string);
static unsigned char assertWriteToFile(const char* const szDebugFlag);
static const char* const getLogLevelString(unsigned char logLevel);

void debugLoggerInit(void)
{
    activeLogHandle.obj.fs = NULL;
    if(0 == logRotate())
    {
        processTempBuf();
        initDone = 1;
    }
}

unsigned char logRotate(void)
{
    signed char i = LogRotationDepth;
    char fullPath[50];
    char newName[50];
    FRESULT result;

    //TODO: disable interrupt?

    if(NULL != activeLogHandle.obj.fs)
    {
        f_close(&activeLogHandle);
    }

    sprintf(newName, "%s.%u", ActiveLogFileLocation, i);
    XBlastLogger(DEBUG_LOGGER, DBG_LVL_DEBUG, "Erase file: %s.", newName);
    f_unlink(newName);

    while(0 <= --i)
    {
        sprintf(fullPath, "%s.%u", ActiveLogFileLocation, i);
        XBlastLogger(DEBUG_LOGGER, DBG_LVL_DEBUG, "Rename:%s -> %s.", fullPath, newName);
        f_rename(fullPath, newName);
        strcpy(newName, fullPath);
    }

    XBlastLogger(DEBUG_LOGGER, DBG_LVL_DEBUG, "Rename:%s -> %s.", ActiveLogFileLocation, fullPath);
    f_rename(ActiveLogFileLocation, fullPath);

    result = f_open(&activeLogHandle, ActiveLogFileLocation, FA_OPEN_APPEND | FA_WRITE);
    XBlastLogger(DEBUG_LOGGER, DBG_LVL_DEBUG, "Open:%s.", ActiveLogFileLocation);
    if(FR_OK != result)
    {
        XBlastLogger(DEBUG_LOGGER, DBG_LVL_ERROR, "Couldn't open log file.");
        return 1;
    }

    return 0;
}

void printTextLogger(const char* const debugFlag, unsigned char logLevel, const char* const functionName, const char* const buffer, ...)
{
    va_list vl;

    va_start(vl,buffer);
    stringFormat(debugFlag, logLevel, functionName, buffer, &vl);
    va_end(vl);
}


//TODO: replace with macro to eliminate va_args handling?
void lwipXBlastPrint(const char* const category, unsigned char lwipDbgLevel, const char* const functionName, const char* const message, ...)
{
    char* string;
    unsigned char convertedLogLevel = DBG_LVL_FATAL;

    /* Remove DBG_ON flag */
    lwipDbgLevel &= ~(unsigned char)(LWIP_DBG_ON);

    if(lwipDbgLevel & LWIP_DBG_HALT)
    {
        convertedLogLevel = DBG_LVL_FATAL;
    }
    else if(lwipDbgLevel & LWIP_DBG_TRACE)
    {
        convertedLogLevel = DBG_LVL_TRACE;
    }
    else if((lwipDbgLevel & LWIP_DBG_STATE) || (lwipDbgLevel & LWIP_DBG_FRESH))
    {
        convertedLogLevel = DBG_LVL_DEBUG;
    }
    else
    {
        switch(lwipDbgLevel & LWIP_DBG_MASK_LEVEL)
        {
        case LWIP_DBG_LEVEL_ALL:
            convertedLogLevel = DBG_LVL_INFO;
            break;
        case LWIP_DBG_LEVEL_WARNING:
            convertedLogLevel = DBG_LVL_WARN;
            break;
        case LWIP_DBG_LEVEL_SERIOUS:
            convertedLogLevel = DBG_LVL_ERROR;
            break;
        case LWIP_DBG_LEVEL_SEVERE:
            convertedLogLevel = DBG_LVL_FATAL;
            break;
        }
    }
    va_list vargs;
    va_start(vargs, message);
    stringFormat(category, convertedLogLevel, functionName, message, &vargs);
    va_end(vargs);
}

static void processTempBuf(void)
{
    int writeCount;
    XBlastLogger(DEBUG_LOGGER, DBG_LVL_INFO, "Dumping temp log buffer.");
    writeCount = f_puts(tempBufBeforeHDDInit, &activeLogHandle);
    XBlastLogger(DEBUG_LOGGER, DBG_LVL_DEBUG, "puts writeCount:%u", writeCount);
    //free(tempBufBeforeHDDInit);
}

static void stringFormat(const char* const debugFlag, unsigned char logLevel, const char* const functionName, const char* const buffer, const va_list* vargs)
{
    FRESULT result;
    char tempBuf[1024];
    unsigned char writeToLogfile;

    writeToLogfile = assertWriteToFile(debugFlag);
    sprintf(tempBuf, "[%s][%s][%s] ", getLogLevelString(logLevel), debugFlag, functionName);
    writeString(tempBuf, writeToLogfile);
    vsprintf(tempBuf,buffer, *vargs);
    writeString(tempBuf, writeToLogfile);

    if('\n' != tempBuf[strlen(tempBuf) - 1])
    {
        writeString("\n", writeToLogfile);
    }

    if(initDone && writeToLogfile)
    {
        result = f_sync(&activeLogHandle);
        XBlastLogger(DEBUG_LOGGER, DBG_LVL_DEBUG, "Sync log to drive. result:%u", result);
    }
#ifdef SPITRACE
    else
    {
        //If you miss characters, add delay function here (wait_us()). A couple microseconds should give enough time for the Arduino to catchup.
        wait_us_blocking(50);
    }
#endif
}

static void writeString(const char* const string, unsigned char writeToLogFile)
{
    FRESULT result;
    /* write to SPI debugger, if applicable */
#ifdef SPITRACE
    printTextSPI(string);
#endif
    /* Write to log file*/
    put(writeToLogFile, string);
}

static void put(unsigned char writeToFile, const char* const string)
{
    FRESULT result;
    unsigned short len = strlen(string);
    unsigned char delayOnSPI = 0;

    if(initDone && writeToFile)
    {
        XBlastLogger(DEBUG_LOGGER, DBG_LVL_DEBUG, "WriteToLog:\"%s\"", string);
        result = f_puts(string, &activeLogHandle);
        XBlastLogger(DEBUG_LOGGER, DBG_LVL_DEBUG, "puts result:%u", result);
    }
    else if(0 == initDone)
    {
#if 0
        if(NULL == tempBufBeforeHDDInit)
        {
            tempBufBeforeHDDInit = malloc(SizeOfTempBuffer * sizeof(char));
            XBlastLogger(DEBUG_LOGGER, DBG_LVL_INFO, "Allocate temp log buffer while HDD init. %u bytes.", SizeOfTempBuffer * sizeof(char));
            cursorInBuf = 0;
        }
#endif
        if((SizeOfTempBuffer * sizeof(char)) > cursorInBuf + len)
        {
            strcpy(tempBufBeforeHDDInit + cursorInBuf, string);
            cursorInBuf += len;
        }
    }
}

static unsigned char assertWriteToFile(const char* const szDebugFlag)
{
    /* List of Debug categories that must not trigger Logfile writes */
#define ForbiddenListLength 3
    char* forbiddenList[ForbiddenListLength] =
    {
        STRINGIFY(DEBUG_CORE_FATFS),
        STRINGIFY(DEBUG_IDE_DRIVER),
        STRINGIFY(DEBUG_LOGGER)
    };
    unsigned char i;

    if(0 == initDone)
    {
        return 0;
    }

    if(NULL == activeLogHandle.obj.fs)
    {
        return 0;
    }

    for(i = 0; i < ForbiddenListLength; i++)
    {
        if(0 == strcmp(szDebugFlag, forbiddenList[i]))
        {
            return 0;
        }
    }

    return 1;
}

static const char* const getLogLevelString(unsigned char logLevel)
{
    switch(logLevel)
    {
    case DBG_LVL_FATAL:
        return "FATAL";
    case DBG_LVL_ERROR:
        return "ERROR";
    case DBG_LVL_WARN:
        return "WARN";
    case DBG_LVL_INFO:
        return "INFO";
    case DBG_LVL_DEBUG:
        return "DEBUG";
    case DBG_LVL_TRACE:
        return "TRACE";
    }

    return "\0";
}