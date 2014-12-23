/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#include "FlashMenuActions.h"

#include "include/boot.h"
#include "include/lpcmod_v1.h"
#include "BootIde.h"
#include "TextMenu.h"
#include "boot.h"
#include "memory_layout.h"
#include "BootFATX.h"
#include "Gentoox.h"

extern void cromwellError (void);
extern void dots (void);

void FlashBiosFromHDD (void *fname) {
#ifdef FLASH
    int res;
    u8 * fileBuf;
    FATXFILEINFO fileinfo;
    FATXPartition *partition;

    partition = OpenFATXPartition (0, SECTOR_SYSTEM, SYSTEM_SIZE);
    fileBuf = (u8 *) malloc (1024 * 1024);  //1MB buffer(max BIOS size)
    memset (fileBuf, 0x00, 1024 * 1024);   //Fill with 0.
    
    //res = LoadFATXFilefixed(partition, fname, &fileinfo, (char*)0x100000);
    res = LoadFATXFile(partition, fname, &fileinfo);
    if (!res) {
        printk ("\n\n\n\n\n           Loading BIOS failed");
        dots ();
        cromwellError ();
        while (1)
            ;
    }
    memcpy(fileBuf, fileinfo.buffer, fileinfo.fileSize);
    free(fileinfo.buffer);
    fileinfo.buffer = fileBuf;
    FlashFileFromBuffer(fileinfo.buffer, fileinfo.fileSize, 1); //1 to display confirmDialog
    free(fileinfo.buffer);
    CloseFATXPartition (partition);
    
    return;
#endif
}

void FlashBiosFromCD (void *cdromId) {
#ifdef FLASH
    memcpy ((void*) FB_START, videosavepage, FB_SIZE);
    BootLoadFlashCD (*(int *) cdromId);
#endif
}

void enableNetflash (void *whatever) {
#ifdef FLASH

    //Save current frameBuffer
    //u8 currentFrameBuffer = malloc(FB_SIZE);
    //memcpy(currentFrameBuffer,(void*)FB_START,FB_SIZE);

    memcpy ((void*) FB_START, videosavepage, FB_SIZE);
    //videosavepage contains data set at the beginning of IconMenu() function.
    //Cheap way to get a blank screen with only Header text data.
    VIDEO_ATTR = 0xffef37;
    printk ("\n\n\n\n\n\n\n");
    VIDEO_ATTR = 0xffc8c8c8;
    //initialiseNetwork ();
    //netFlash ();
    etherboot();
    //Restore FrameBuffer for Menu display
    //memcpy((void*)FB_START,currentFrameBuffer,FB_SIZE);
    //free(currentFrameBuffer);
#endif
}

void enableWebupdate (void *whatever) {
#ifdef FLASH
    memcpy ((void*) FB_START, videosavepage, FB_SIZE);
    VIDEO_ATTR = 0xffef37;
    printk ("\n\n\n\n\n\n");
    VIDEO_ATTR = 0xffc8c8c8;
    //initialiseNetwork ();
    //webUpdate ();
#endif
}

//Use this function only for in OS operations.
void switchOSBank (u8 bank) {
    currentFlashBank = bank;
    xF70ELPCRegister = bank;
    WriteToIO (XBLAST_CONTROL, bank);    // switch to proper bank
                                         //Send OSBNKCTRLBIT when toggling a bank other than BNKOS.
}

//Use this function only when you're about to boot into another bank.
void switchBootBank (u8 bank) {
    u8 resultBank = bank;
    //currentFlashBank = NOBNKID;         //We won't be coming back from this!
    if(bank > BOOTFROMTSOP)       //We're asked to boot from XBlast's flash
        resultBank |= A19controlModBoot;  //Apply custom A19 control (if need be).
    WriteToIO (XBLAST_CONTROL, resultBank); // switch to proper bank from booting register
}

void FlashFooter (void) {
    VIDEO_ATTR = 0xffc8c8c8;
    printk ("\n\n           Press Button 'A' to continue.");
    //if(fHasHardware == SYSCON_ID_V1)
    //    switchBank(BNKOS);
    while ((risefall_xpad_BUTTON (TRIGGER_XPAD_KEY_A) != 1))
        wait_ms (10);
    initialSetLED (LPCmodSettings.OSsettings.LEDColor);
}
