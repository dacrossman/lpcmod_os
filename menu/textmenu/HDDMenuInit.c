/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "include/boot.h"
#include "BootIde.h"
#include "TextMenu.h"
#include "HDDMenuActions.h"

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
            if((tsaHarddiskInfo[i].m_securitySettings &0x0004)==0x0004) {
                //This drive is locked - produce an unlock menu
                itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
                memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
                sprintf(itemPtr->szCaption,"Unlock HDD (hd%c)",i ? 'b':'a');
                itemPtr->functionPtr= UnlockHDD;
                    itemPtr->functionDataPtr = malloc(sizeof(int));
                            *(int*)itemPtr->functionDataPtr = i;
                TextMenuAddItem(menuPtr, itemPtr);
            }
            else {
                //This drive is unlocked - produce an lock menu
                itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
                memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
                sprintf(itemPtr->szCaption,"Lock HDD (hd%c)",i ? 'b':'a');
                itemPtr->functionPtr= LockHDD;
                    itemPtr->functionDataPtr = malloc(sizeof(int));
                            *(int*)itemPtr->functionDataPtr = i;
                TextMenuAddItem(menuPtr, itemPtr);
            }
    
            //Add a 'display password' menu
            itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
            memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
            sprintf(itemPtr->szCaption,"Display HDD password (hd%c)",i ? 'b':'a');
            itemPtr->functionPtr= DisplayHDDPassword;
                itemPtr->functionDataPtr = malloc(sizeof(int));
                           *(int*)itemPtr->functionDataPtr = i;
            TextMenuAddItem(menuPtr, itemPtr);
        
        }
    }
    return menuPtr;
}
