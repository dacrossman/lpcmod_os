#include "lpcmod_v1.h"
#include "include/config.h"
#include "TextMenu.h"
#include "FlashMenuActions.h"
#include "boot.h"

TEXTMENU* BankSelectInit(void);


TEXTMENU *BankSelectMenuInit(void) {
    
    TEXTMENUITEM *itemPtr;
    TEXTMENU *menuPtr;
    

    menuPtr = (TEXTMENU*)malloc(sizeof(TEXTMENU));
    memset(menuPtr,0x00,sizeof(TEXTMENU));
    strcpy(menuPtr->szCaption, "Select flash bank");
    
    //No entry in this menu will have a configurable parameter.
    //Set first character to NULL to indicate no string is to be shown.
    itemPtr->szParameter[0]=0;


    //Bank0 (512KB)
    itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
    memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
    strcpy(itemPtr->szCaption, "Bank0 (512KB)");
    itemPtr->szParameter[0]=0;
    itemPtr->szParameter[1] = BNK512;
    itemPtr->functionPtr=DrawChildTextMenu;
    itemPtr->functionDataPtr = (void *)BankSelectInit();
    TextMenuAddItem(menuPtr, itemPtr);

    //Bank1 (256KB)
    itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
    memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
    strcpy(itemPtr->szCaption, "Bank1 (256KB)");
    itemPtr->szParameter[0]=0;
    itemPtr->szParameter[1] = BNK256;
    itemPtr->functionPtr=DrawChildTextMenu;
    itemPtr->functionDataPtr = (void *)BankSelectInit();
    TextMenuAddItem(menuPtr, itemPtr);

    //Bank2 (OS)
    itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
    memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
    strcpy(itemPtr->szCaption, "Bank2 (OS)");
    itemPtr->szParameter[0]=0;
    itemPtr->szParameter[1] = BNKOS;
    itemPtr->functionPtr=DrawChildTextMenu;
    itemPtr->functionDataPtr = (void *)BankSelectInit();
    TextMenuAddItem(menuPtr, itemPtr);
    
    return menuPtr;
}

TEXTMENU* BankSelectInit(void) {
    TEXTMENUITEM *itemPtr;
    TEXTMENU *menuPtr;
    int i=0;
    
    //No entry in this menu will have a configurable parameter.
    //Set first character to NULL to indicate no string is to be shown.
    itemPtr->szParameter[0]=0;

    menuPtr = (TEXTMENU*)malloc(sizeof(TEXTMENU));
    memset(menuPtr,0x00,sizeof(TEXTMENU));
    if(fHasHardware == SYSCON_ID_V1){
        if(hiddenTextParam == BNKOS)
            strcpy(menuPtr->szCaption, "Flash menu : OS bank");
        else if(hiddenTextParam == BNK256)
            strcpy(menuPtr->szCaption, "Flash menu : 256KB bank");
        else if(hiddenTextParam == BNK512)
            strcpy(menuPtr->szCaption, "Flash menu : 512KB bank");
        else
            strcpy(menuPtr->szCaption, "UNKNOWN BANK. GO BACK!");

        switchBank(hiddenTextParam);
    }
    else {
        strcpy(menuPtr->szCaption, "Flash menu : Unknown device");
    }
    
#ifdef LWIP
    itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
    memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
       sprintf(itemPtr->szCaption,"Net Flash");
    itemPtr->functionPtr= enableNetflash;
    itemPtr->functionDataPtr= NULL;
    TextMenuAddItem(menuPtr, itemPtr);

    itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
    memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
       sprintf(itemPtr->szCaption,"Web Update");
    itemPtr->functionPtr= enableWebupdate;
    itemPtr->functionDataPtr= NULL;
    TextMenuAddItem(menuPtr, itemPtr);
#endif

    for (i=0; i<2; ++i) {
        if (tsaHarddiskInfo[i].m_fDriveExists && tsaHarddiskInfo[i].m_fAtapi) {
             char *driveName=malloc(sizeof(char)*32);
            itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
            memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
            sprintf(itemPtr->szCaption,"CD Flash (image.bin)");// (hd%c)",i ? 'b':'a');
            itemPtr->functionPtr= FlashBiosFromCD;
            itemPtr->functionDataPtr = malloc(sizeof(int));
            *(int*)itemPtr->functionDataPtr = i;
            TextMenuAddItem(menuPtr, itemPtr);
        }
    }

    itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
    memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
      sprintf(itemPtr->szCaption,"HDD Flash");
    itemPtr->functionPtr=DrawChildTextMenu;
    itemPtr->functionDataPtr = (void *)HDDFlashMenuInit();
    TextMenuAddItem(menuPtr, itemPtr);


/*
    itemPtr = (TEXTMENUITEM*)malloc(sizeof(TEXTMENUITEM));
    memset(itemPtr,0x00,sizeof(TEXTMENUITEM));
    strcpy(itemPtr->szCaption, "Selected bank");
    itemPtr->functionPtr=DrawChildTextMenu;
    itemPtr->functionDataPtr = (void *)FlashMenuInit();
    TextMenuAddItem(menuPtr, itemPtr);*/
//    if(fHasHardware == SYSCON_ID_V1){
//    	DrawChildTextMenu(menuPtr);
//    }
    return menuPtr;
}

