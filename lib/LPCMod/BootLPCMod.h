/*
 *
 *
 */

#ifndef _BootLPCMod_H_
#define _BootLPCMod_H_

#include "VideoInitialization.h"

#define HDD4780_DEFAULT_NBLINES    4
#define HDD4780_DEFAULT_LINELGTH    20
#define DEFAULT_FANSPEED    20

#define NBTXTPARAMS 31
#define MINPARAMLENGTH 7
#define IPTEXTPARAMGROUP 14
#define TEXTPARAMGROUP (IPTEXTPARAMGROUP + 5)
#define SPECIALPARAMGROUP (TEXTPARAMGROUP + 8)
extern char *xblastcfgstrings[NBTXTPARAMS];
extern unsigned char *settingsPtrArray[IPTEXTPARAMGROUP];
extern unsigned char *IPsettingsPtrArray[TEXTPARAMGROUP-IPTEXTPARAMGROUP];
extern char *textSettingsPtrArray[SPECIALPARAMGROUP - TEXTPARAMGROUP];
extern unsigned char *specialCasePtrArray[4];

void initialLPCModOSBoot(_LPCmodSettings *LPCmodSettings);

u16 LPCMod_HW_rev(void);

void LPCMod_ReadIO(struct _GenPurposeIOs *GPIOstruct);

void LPCMod_LCDBankString(char * string, u8 bankID);

int LPCMod_ReadCFGFromHDD(_LPCmodSettings *LPCmodSettings);
int LPCMod_SaveCFGToHDD(void);

#endif // _BootLPCMod_H_
