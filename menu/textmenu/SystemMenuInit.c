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
#include "SystemMenuActions.h"

TEXTMENU *SystemMenuInit(void) {
	TEXTMENUITEM *itemPtr;
	TEXTMENU *menuPtr;

	//I know, I know... There are multiple definitions of these in the code. I don't care. It's not like they are going to change much.
	//String enum for DVD_ZONE
	char *DVDregiontext[9] = {
		"Region Clear",
		"USA (1)",
		"Europe (2)",
		"India (3)",
		"Australia (4)",
		"USSR (5)",
		"China (6)",
		"Free (7)",
		"Airlines (8)"
	};
	char *Gameregiontext[5] = {
		"Unknown/Error",
		"NTSC-U",
		"NTSC-J",
		"n/a",
		"PAL"
	};

	menuPtr = (TEXTMENU*)malloc(sizeof(TEXTMENU));
	memset(menuPtr,0x00,sizeof(TEXTMENU));
	strcpy(menuPtr->szCaption, "System settings");

	//LED SETTINGS MENU
	itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
	memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
	sprintf(itemPtr->szCaption,"LED");
	itemPtr->functionPtr=DrawChildTextMenu;
	itemPtr->functionDataPtr = (void *)LEDMenuInit();
	TextMenuAddItem(menuPtr, itemPtr);
	
	//FAN SPEED
	itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
	memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
	sprintf(itemPtr->szCaption,"Fan speed : %d%%", LPCmodSettings.OSsettings.fanSpeed);
	itemPtr->functionPtr=NULL;
	itemPtr->functionDataPtr = NULL;
	itemPtr->functionLeftPtr=decrementFanSpeed;
	itemPtr->functionLeftDataPtr = itemPtr->szCaption;
	itemPtr->functionRightPtr=incrementFanSpeed;
	itemPtr->functionRightDataPtr = itemPtr->szCaption;
	TextMenuAddItem(menuPtr, itemPtr);

	//VIDEO STANDARD SETTINGS MENU
	itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
	memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
	strcpy(itemPtr->szCaption, "Video standard");
	itemPtr->functionPtr=DrawChildTextMenu;
	itemPtr->functionDataPtr = (void *)VideoMenuInit();
	TextMenuAddItem(menuPtr, itemPtr);

	//VIDEO FORMAT SETTINGS MENU
	itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
	memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
	strcpy(itemPtr->szCaption, "Video format");
	itemPtr->functionPtr= NULL;
	itemPtr->functionDataPtr = NULL;
	TextMenuAddItem(menuPtr, itemPtr);

	//DVD REGION SETTINGS MENU
	itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
	memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
	sprintf(itemPtr->szCaption, "DVD region : %s",DVDregiontext[eeprom.DVDPlaybackKitZone[0]]);
	itemPtr->functionPtr= NULL;
	itemPtr->functionDataPtr = NULL;
	itemPtr->functionLeftPtr=decrementDVDRegion;
	itemPtr->functionLeftDataPtr = itemPtr->szCaption;
	itemPtr->functionRightPtr=incrementDVDRegion;
	itemPtr->functionRightDataPtr = itemPtr->szCaption;
	TextMenuAddItem(menuPtr, itemPtr);

	//GAME REGION SETTINGS MENU
	itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
	memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
	sprintf(itemPtr->szCaption, "Game region : %s",Gameregiontext[getGameRegionValue()]);
	itemPtr->functionPtr= NULL;
	itemPtr->functionDataPtr = NULL;
	itemPtr->functionLeftPtr=decrementGameRegion;
	itemPtr->functionLeftDataPtr = itemPtr->szCaption;
	itemPtr->functionRightPtr=incrementGameRegion;
	itemPtr->functionRightDataPtr = itemPtr->szCaption;
	TextMenuAddItem(menuPtr, itemPtr);

	return menuPtr;
}