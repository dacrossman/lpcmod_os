/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "boot.h"
#include "BootIde.h"
#include "TextMenu.h"
#include "HDDMenuActions.h"

TEXTMENU *LargeHDDMenuInit(void);

TEXTMENU *HDDMenuInit(void) {
    TEXTMENUITEM *itemPtr;
    TEXTMENU *menuPtr;
    int i=0;

    menuPtr = (TEXTMENU*)malloc(sizeof(TEXTMENU));
    memset(menuPtr,0x00,sizeof(TEXTMENU));
    strcpy(menuPtr->szCaption, "HDD Menu");

    //No entry in this menu will have a configurable parameter.
    //Set first character to NULL to indicate no string is to be shown.
    itemPtr->szParameter[0]=0;

    for (i=0; i<2; ++i) {
        if (tsaHarddiskInfo[i].m_fDriveExists && !tsaHarddiskInfo[i].m_fAtapi) {
            //If it's not ATAPI, it must be IDE
            //This drive is locked - produce an unlock menu
            itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
            memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
            if((tsaHarddiskInfo[i].m_securitySettings &0x0004)==0x0004) {
                sprintf(itemPtr->szCaption,"Unlock HDD : ");
            }
            else {
                sprintf(itemPtr->szCaption,"Lock HDD : ");
            }
            sprintf(itemPtr->szParameter, "%s",i ? "slave":"master");
            itemPtr->functionPtr= AssertLockUnlock;
            itemPtr->functionDataPtr = itemPtr;
            TextMenuAddItem(menuPtr, itemPtr);
    
            //Add a 'display password' menu
            itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
            memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
            sprintf(itemPtr->szCaption,"Display HDD password : ");
            sprintf(itemPtr->szParameter, "%s",i ? "slave":"master");
            itemPtr->functionPtr= DisplayHDDPassword;
            itemPtr->functionDataPtr = malloc(sizeof(int));
                *(int*)itemPtr->functionDataPtr = i;
            TextMenuAddItem(menuPtr, itemPtr);

            //Add a 'display HDD info' menu
            itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
            memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
            sprintf(itemPtr->szCaption,"Display HDD info : ");
            sprintf(itemPtr->szParameter, "%s",i ? "slave":"master");
            itemPtr->functionPtr= DisplayHDDInfo;
            itemPtr->functionDataPtr = malloc(sizeof(int));
                *(int*)itemPtr->functionDataPtr = i;
            TextMenuAddItem(menuPtr, itemPtr);

            //FORMAT C: drive
            itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
            memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
            sprintf(itemPtr->szCaption,"Format C drive : ");
            sprintf(itemPtr->szParameter, "%s",i ? "slave":"master");
            itemPtr->functionPtr= FormatDriveC;
            itemPtr->functionDataPtr = malloc(sizeof(int));
                *(int*)itemPtr->functionDataPtr = i;
            TextMenuAddItem(menuPtr, itemPtr);

            //FORMAT E: drive
            itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
            memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
            sprintf(itemPtr->szCaption,"Format E drive : ");
            sprintf(itemPtr->szParameter, "%s",i ? "slave":"master");
            itemPtr->functionPtr= FormatDriveE;
            itemPtr->functionDataPtr = malloc(sizeof(int));
                *(int*)itemPtr->functionDataPtr = i;
            TextMenuAddItem(menuPtr, itemPtr);

            //FORMAT X:, Y: and Z: drives.
            itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
            memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
            sprintf(itemPtr->szCaption,"Format cache drives : ");
            sprintf(itemPtr->szParameter, "%s",i ? "slave":"master");
            itemPtr->functionPtr= FormatCacheDrives;
            itemPtr->functionDataPtr = malloc(sizeof(int));
                *(int*)itemPtr->functionDataPtr = i;
            TextMenuAddItem(menuPtr, itemPtr);

            //If there's enough sectors to make F and/or G drive(s).
            if(tsaHarddiskInfo[i].m_dwCountSectorsTotal >= (SECTOR_EXTEND + SECTORS_SYSTEM)){
                //Format Larger drives option menu.
                itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
                memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
                sprintf(itemPtr->szCaption,"Large HDD format options : ");
                sprintf(itemPtr->szParameter, "%s",i ? "slave":"master");
                itemPtr->functionPtr= DrawChildTextMenu;
                itemPtr->functionDataPtr = (void *)LargeHDDMenuInit();
                TextMenuAddItem(menuPtr, itemPtr);
            }
        
        }
    }

    return menuPtr;
}

TEXTMENU *LargeHDDMenuInit(void) {
    TEXTMENUITEM *itemPtr;
    TEXTMENU *menuPtr;
    int i=0, nDriveIndex = 0;

    if(hiddenTextParam == 'l')
        nDriveIndex = 1;                                //Slave HDD.

    //Amount of free sectors after standard partitions
    u32 nExtendSectors = tsaHarddiskInfo[nDriveIndex].m_dwCountSectorsTotal - SECTOR_EXTEND;

    menuPtr = (TEXTMENU*)malloc(sizeof(TEXTMENU));
    memset(menuPtr,0x00,sizeof(TEXTMENU));
    sprintf(menuPtr->szCaption, "Large HDD format options : %s", nDriveIndex ? "slave":"master");

    //No entry in this menu will have a configurable parameter.
    //Set first character to NULL to indicate no string is to be shown.
    itemPtr->szParameter[0]=0;

    //If lbacount >= minimum amount per partition.
    if(nExtendSectors > (SECTORS_SYSTEM + SECTORS_SYSTEM)){
        itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
        memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
        sprintf(itemPtr->szCaption,"F:, G: Split evenly");
        itemPtr->functionPtr= FormatDriveFG;
        itemPtr->functionDataPtr = malloc(sizeof(u8));
            *(u8 *)itemPtr->functionDataPtr = nDriveIndex | F_GEQUAL;
        TextMenuAddItem(menuPtr, itemPtr);
    }

    //If lbacount is high enough to max out a F: partition and still have enough left to create a G partition
    if(nExtendSectors > (LBASIZE_1024GB + SECTORS_SYSTEM)){
        itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
        memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
        sprintf(itemPtr->szCaption,"Max F:, G: takes the rest");
        itemPtr->functionPtr= FormatDriveFG;
        itemPtr->functionDataPtr = malloc(sizeof(u8));
            *(u8 *)itemPtr->functionDataPtr = nDriveIndex | FMAX_G;
        TextMenuAddItem(menuPtr, itemPtr);
    }

    //if lbacount is high enough to create G: partition but not too high to waste space because G: would be maxed out.
    if((nExtendSectors > (LBASIZE_137GB + SECTORS_SYSTEM)) && ((nExtendSectors - LBASIZE_137GB) < LBASIZE_1024GB)){
        itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
        memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
        sprintf(itemPtr->szCaption,"F: = 120GB, G: takes the rest");
        itemPtr->functionPtr= FormatDriveFG;
        itemPtr->functionDataPtr = malloc(sizeof(u8));
            *(u8 *)itemPtr->functionDataPtr = nDriveIndex | F137_G;
        TextMenuAddItem(menuPtr, itemPtr);
    }

    //If lbacount is not too high to waste space because F: can't get bigger.
    if(nExtendSectors < LBASIZE_1024GB){
        itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
        memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
        sprintf(itemPtr->szCaption,"F: take all, no G:");
        itemPtr->functionPtr= FormatDriveFG;
        itemPtr->functionDataPtr = malloc(sizeof(u8));
            *(u8 *)itemPtr->functionDataPtr = nDriveIndex | F_NOG;
        TextMenuAddItem(menuPtr, itemPtr);
    }


    return menuPtr;
}
