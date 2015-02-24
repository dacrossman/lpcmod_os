/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#include "EepromEditMenuActions.h"
#include "ToolsMenuActions.h"
#include "BootFATX.h"
#include "lpcmod_v1.h"

void displayEditEEPROMBuffer(void *ignored){
    int i;
    u8 decryptedConfounder[8];
    u8 decryptedGameRegion[4];
    u8 decryptedWholeBuffer[0x30];
    u8 version;
    char serialString[13];
    char *Gameregiontext[5] = {
        "Unknown/Error",
        "NTSC-U",
        "NTSC-J",
        "n/a",
        "PAL"
    };
    version = decryptEEPROMData((u8 *)editeeprom, decryptedWholeBuffer);
    ToolHeader("Modified EEPROM buffer content");
    printk("\n\n           EEPROM version: %u", version);
    if(version < 9 || version > 12){
        printk(" (corrupted!)");
    }
    printk("\n           Decrypted Confounder:");
    for(i = 0; i < 8; i++){
        printk(" %02X", decryptedWholeBuffer[20+i]);
    }
/*
    printk("\n           Encrypted HDDKey:");
    for(i = 0; i < 16; i++){
        printk(" %02X", editeeprom->HDDKkey[i]);
    }
*/
    printk("\n           Decrypted HDDKey:");
    for(i = 0; i < 16; i++){
        printk(" %02X", decryptedWholeBuffer[28+i]);
    }
    printk("\n           Decrypted GameRegion:");
    for(i = 0; i < 4; i++){
        printk(" %02X", decryptedWholeBuffer[44+i]);
    }
    printk(" (%s)", Gameregiontext[(decryptedWholeBuffer[44] <= 4)? decryptedWholeBuffer[44] : 0]);  //Hopefully, everything we need is in first byte.
    printk("\n           MAC address: %02X:%02X:%02X:%02X:%02X:%02X",
    editeeprom->MACAddress[0], editeeprom->MACAddress[1], editeeprom->MACAddress[2],
    editeeprom->MACAddress[3], editeeprom->MACAddress[4], editeeprom->MACAddress[5]);
    memcpy(serialString, editeeprom->SerialNumber, 12);
    serialString[12]='\0';
    printk("\n           Serial Number: %s", serialString);
    printk("\n           Online Key:");
    for(i = 0; i < 16; i++){
        printk(" %02X", editeeprom->OnlineKey[i]);
    }
    UIFooter();
}


void LastResortRecovery(void *ignored){
    const char *xbox_mb_rev[8] = {
        "DevKit",
        "DebugKit",
        "1.0",
        "1.1",
        "1.2/1.3",
        "1.4/1.5",
        "1.6/1.6b",
        "Unknown"
    };
    
//Generic 1.0 revision eeprom image. Thanks bunnie!
    const u8 EEPROMimg10[] = {
        0x47, 0x83, 0xa2, 0x7d, 0x6a, 0x69, 0x10, 0x8b, 0x2d, 0xb2, 0xe8, 0x90, 0xe1, 0x60, 0xde, 0xed,
        0x02, 0xc2, 0xaa, 0x79, 0x21, 0x47, 0xcd, 0xb0, 0xb7, 0xa8, 0x7a, 0x77, 0x44, 0x9c, 0x5e, 0x6e,
        0xd0, 0xf5, 0xf9, 0xe6, 0x94, 0x68, 0x39, 0xe0, 0xca, 0xa5, 0xd2, 0xe5, 0xfa, 0x02, 0xb9, 0xb7,
        0x9d, 0x19, 0xe6, 0xed, 0x36, 0x30, 0x35, 0x33, 0x37, 0x39, 0x35, 0x32, 0x31, 0x39, 0x30, 0x32,
        0x00, 0x50, 0xf2, 0x41, 0x9e, 0x5f, 0x00, 0x00, 0x2d, 0xaa, 0x6c, 0x23, 0x99, 0x80, 0x11, 0x47,
        0x33, 0xc3, 0xc7, 0x1a, 0x2b, 0xa5, 0x06, 0xb3, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x75, 0x61, 0x57, 0xfb, 0x2c, 0x01, 0x00, 0x00, 0x45, 0x53, 0x54, 0x00, 0x45, 0x44, 0x54, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x05, 0x00, 0x02, 0x04, 0x01, 0x00, 0x02,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc4, 0xff, 0xff, 0xff,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

//Generic 1.1 revision eeprom image. Credits to the guy(s) who made flashBios unauthorized builds.
    const u8 EEPROMimg11[] = {
        0xa1, 0xdb, 0x72, 0x43, 0x5c, 0x91, 0x5a, 0x76, 0xc5, 0xfb, 0xe7, 0xe5, 0x42, 0x25, 0x38, 0x51,
        0x02, 0x68, 0x24, 0xc5, 0x80, 0x58, 0x3f, 0x83, 0xa4, 0xb5, 0x14, 0x9e, 0xc7, 0xbb, 0x18, 0x3a,
        0xb3, 0x52, 0x39, 0x6d, 0xd7, 0xc4, 0x74, 0xb9, 0x03, 0x29, 0x3a, 0xa7, 0x8a, 0x09, 0x11, 0xeb,
        0xf8, 0x31, 0x33, 0x20, 0x34, 0x33, 0x31, 0x39, 0x31, 0x32, 0x31, 0x33, 0x32, 0x38, 0x30, 0x36,
        0x00, 0x0d, 0x3a, 0x00, 0x0f, 0x42, 0x00, 0x00, 0x93, 0x37, 0xb1, 0x05, 0x3a, 0xa6, 0x42, 0xa5,
        0x2c, 0xc8, 0x47, 0x0b, 0x67, 0x3a, 0x84, 0x86, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x75, 0x61, 0x57, 0xfb, 0x2c, 0x01, 0x00, 0x00, 0x45, 0x53, 0x54, 0x00, 0x45, 0x44, 0x54, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x05, 0x00, 0x02, 0x04, 0x01, 0x00, 0x02,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc4, 0xff, 0xff, 0xff,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

//Generic 1.2/1.3 revision eeprom image. Credits to the guy(s) who made flashBios unauthorized builds.
    const u8 EEPROMimg12[] = {
        0x8f, 0x1a, 0xbb, 0x35, 0x79, 0x0f, 0xfc, 0x16, 0xb8, 0xf2, 0x03, 0xbd, 0x0a, 0x26, 0xe4, 0x55,
        0x4f, 0x56, 0xec, 0x36, 0x7e, 0xf3, 0x4c, 0x9d, 0x92, 0x90, 0xb9, 0x8f, 0x42, 0x43, 0x05, 0x22,
        0xce, 0x47, 0xc7, 0xcb, 0x1b, 0x01, 0xd7, 0xfa, 0x36, 0x5a, 0x80, 0x1f, 0x42, 0xa6, 0xb4, 0xb4,
        0x11, 0x70, 0x31, 0x4d, 0x33, 0x34, 0x33, 0x30, 0x35, 0x39, 0x34, 0x33, 0x32, 0x39, 0x30, 0x36,
        0x00, 0x0d, 0x3a, 0x00, 0x59, 0x3e, 0x00, 0x00, 0x3c, 0xd5, 0xa7, 0x8a, 0xae, 0xfb, 0xc3, 0x00,
        0x4f, 0xeb, 0x6e, 0x2d, 0xc1, 0xe0, 0xe1, 0x5f, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x75, 0x61, 0x57, 0xfb, 0x2c, 0x01, 0x00, 0x00, 0x45, 0x53, 0x54, 0x00, 0x45, 0x44, 0x54, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x05, 0x00, 0x02, 0x04, 0x01, 0x00, 0x02,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc4, 0xff, 0xff, 0xff,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

//Generic 1.4/1.5 revision eeprom image. Credits to the guy(s) who made flashBios unauthorized builds.
    const u8 EEPROMimg14[] = {
        0xa2, 0xfe, 0x3b, 0x0a, 0xfc, 0xa8, 0x2e, 0x20, 0xce, 0x56, 0x2b, 0xa1, 0x26, 0xe3, 0x4f, 0x0d,
        0x9b, 0xb3, 0xce, 0xb5, 0xc5, 0xa8, 0x7a, 0x22, 0xee, 0xbc, 0x9c, 0x05, 0x5e, 0xec, 0x37, 0x82,
        0x42, 0x2b, 0xc2, 0x48, 0x62, 0xe8, 0x5e, 0x0d, 0xfe, 0x36, 0x4a, 0xfb, 0xe2, 0x3e, 0xb1, 0x89,
        0x4b, 0x24, 0x2b, 0x13, 0x33, 0x31, 0x32, 0x39, 0x36, 0x39, 0x35, 0x33, 0x33, 0x31, 0x30, 0x35,
        0x00, 0x50, 0xf2, 0xf7, 0xf5, 0xda, 0x00, 0x00, 0x98, 0x8f, 0x52, 0xf2, 0xa2, 0x68, 0x15, 0x0b,
        0x81, 0x7b, 0xb1, 0x52, 0x66, 0xa0, 0xf0, 0x02, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x3d, 0x61, 0x57, 0xfb, 0x68, 0x01, 0x00, 0x00, 0x43, 0x53, 0x54, 0x00, 0x43, 0x44, 0x54, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x05, 0x00, 0x02, 0x04, 0x01, 0x00, 0x02,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc4, 0xff, 0xff, 0xff,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

//Generic 1.6/1.6b revision eeprom image. Credits to the guy(s) who made flashBios unauthorized builds.
    const u8 EEPROMimg16[] = {
        0x0a, 0x3e, 0xd2, 0x7c, 0xb4, 0x8e, 0x6f, 0x94, 0x76, 0x43, 0x70, 0x12, 0x21, 0x32, 0x33, 0x6d,
        0x8a, 0xd3, 0x5d, 0x76, 0x17, 0x85, 0xde, 0xe2, 0x8a, 0xc6, 0x26, 0xd0, 0x3c, 0x7c, 0x43, 0x41,
        0xf6, 0x98, 0xe8, 0xd6, 0xfd, 0xf9, 0x75, 0xe2, 0x77, 0x53, 0x7d, 0xe5, 0xea, 0xb0, 0x29, 0x2e,
        0x19, 0xb9, 0x49, 0x57, 0x36, 0x30, 0x36, 0x30, 0x32, 0x35, 0x32, 0x34, 0x32, 0x32, 0x30, 0x35,
        0x00, 0x0d, 0x3a, 0x5e, 0xb9, 0x86, 0x00, 0x00, 0x0c, 0x32, 0x50, 0x3b, 0x51, 0x04, 0x0e, 0x72,
        0xea, 0xf5, 0x00, 0x20, 0x4a, 0xee, 0x43, 0xe3, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x6b, 0x61, 0x57, 0xfb, 0x2c, 0x01, 0x00, 0x00, 0x45, 0x53, 0x54, 0x00, 0x45, 0x44, 0x54, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x05, 0x00, 0x02, 0x04, 0x01, 0x00, 0x02,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc4, 0xff, 0xff, 0xff,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x68, 0xaa, 0xdd, 0x02, 0x46, 0x45, 0x8f, 0x8f, 0x78, 0x56, 0xbb, 0x69, 0x01, 0x04, 0x46, 0x45,
        0x8f, 0x8f, 0x78, 0x56, 0xbb, 0x69, 0x01, 0x04, 0x46, 0x45, 0x8f, 0x8f, 0x78, 0x56, 0xbb, 0x69,
        0x12, 0x03, 0x46, 0x45, 0x8f, 0x8f, 0x78, 0x56, 0xbb, 0x69, 0x02, 0x02, 0x46, 0x45, 0x8f, 0x8f,
        0x78, 0x56, 0xbb, 0x69, 0x12, 0x02, 0x7a, 0x9d, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    char revString[50];
    u8 mbVersion = I2CGetXboxMBRev();
    if(ConfirmDialog("     Overwrite EEPROM with generic image?", 1))       //First generic warning
        return;
    sprintf(revString, "    Overwriting with %s EEPROM image. OK?", xbox_mb_rev[mbVersion]);
    if(ConfirmDialog(revString, 1))             //Second warning for user to assert if Xbox revision detection is right.
        return;
    switch(mbVersion){
        //TODO: Validate if all DevKits and DebugKits are 1.0!
        case DEVKIT:
        case DEBUGKIT:
        case REV1_0:
            memcpy(editeeprom, EEPROMimg10, sizeof(EEPROMDATA));
            break;
        case REV1_1:
            memcpy(editeeprom, EEPROMimg11, sizeof(EEPROMDATA));
            break;
        case REV1_2:
            memcpy(editeeprom, EEPROMimg12, sizeof(EEPROMDATA));
            break;
        case REV1_4:
            memcpy(editeeprom, EEPROMimg14, sizeof(EEPROMDATA));
            break;
        case REV1_6:
            memcpy(editeeprom, EEPROMimg16, sizeof(EEPROMDATA));
            break;
    }
}

void bruteForceFixDisplayresult(void *ignored){
    u8 eepromVersion;
    char unused[20];
    ToolHeader("Brute Force Fix EEPROM");
    eepromVersion = BootHddKeyGenerateEepromKeyData(editeeprom,unused);

    if(eepromVersion == 13){
        if(bruteForceFixEEprom()){
            //success
            printk("\n\n           Successfully fixed!\n\n\n");
        }
        else{
            printk("\n\n           EEPROM could be fixed...\n           Use \"Last resort recovery\" feature or try something else.\n\n\n");
        }
    }
    else{
        printk("\n\n           Brute force fix not useful here.\n           Aborting.\n\n\n");
    }
    UIFooter();
}

bool bruteForceFixEEprom(void){
    u8 ver, bytepos;
    int bytecombinations;
    u8 *teeprom;
    char unused[20];
    teeprom = malloc(sizeof(EEPROMDATA));

    //Fix attempt to sucessfully decrypt 48 first bytes of EEPROM by
    //trying to change a single byte in the buffer. all possible values
    //of this byte are tried in the calculation. If this yields no
    //positive result, next byte in buffer is given the same treatment.
    //So, effectively, this technique can only recover a corrupt
    //EEPROM with only a single corrupt byte in it's first 48 bytes.
    for (bytepos=0;bytepos<0x30;bytepos++) {
        for (bytecombinations=0;bytecombinations<0x100;bytecombinations++) {
            memcpy(teeprom,editeeprom,sizeof(EEPROMDATA));
            teeprom[bytepos]=bytecombinations;
            ver = BootHddKeyGenerateEepromKeyData(teeprom,unused);
            if (ver!=13) {
                memcpy(editeeprom,teeprom,sizeof(EEPROMDATA));
                free(teeprom);
                return true;
            }
        }
    }

    free(teeprom);
    return false;      // No Match found
}

void confirmSaveToEEPROMChip(void *ignored){
    u8 nIndexDrive, unlockConfirm[2];
    bool cancelChanges = false;

    if(ConfirmDialog("          Save modified EEPROM to chip?", 1))
            return;
    memcpy(&eeprom, editeeprom, sizeof(EEPROMDATA));   //Copy back edition buffer to main eeprom buffer.
    ToolHeader("Saved EEPROM image");
    printk("\n\n           Modified buffer has been saved to main EEPROM buffer.\n           Pressing \'A\' will program EEPROM chip and restart the console.\n           Pressing Power button will cancel EEPROM chip write.\n\n\n");
    UIFooter();
    for(nIndexDrive = 0; nIndexDrive < 2; nIndexDrive++){               //Probe 2 possible drives
        if(tsaHarddiskInfo[nIndexDrive].m_fDriveExists && !tsaHarddiskInfo[nIndexDrive].m_fAtapi){      //If there's a HDD plugged on specified port
            if((tsaHarddiskInfo[nIndexDrive].m_securitySettings &0x0002)==0x0002) {       //If drive is locked
                    if(UnlockHDD(nIndexDrive, 0, (unsigned char *)&eeprom))                                             //0 is for silent
                        unlockConfirm[nIndexDrive] = 1;                                   //Everything went well, we'll relock after eeprom write.
                    else{
                        unlockConfirm[0] = 255;       //error
                        unlockConfirm[1] = 255;       //error
                        break;
                    }
            }
            else{
                unlockConfirm[nIndexDrive] = 0;                                         //Drive not locked, won't relock after eeprom write.
            }
        }
        else{
            unlockConfirm[nIndexDrive] = 0;       //Won't relock as no HDD was detected on that port.
        }
    }
    if(unlockConfirm[0] == 255 && unlockConfirm[1] == 255){      //error in unlocking one of 2 drives.
        cancelChanges = ConfirmDialog("        Drive(s) still locked! Continue anyway?", 1);
    }
    if(!cancelChanges){
        memcpy(&eeprom, editeeprom, sizeof(EEPROMDATA));
        for(nIndexDrive = 0; nIndexDrive < 2; nIndexDrive++){               //Probe 2 possible drives
            if(unlockConfirm[nIndexDrive] == 1){
                LockHDD(nIndexDrive, 0, (unsigned char *)&eeprom);                                //0 is for silent mode.
            }
        }
        SlowReboot(NULL);   //This function will take care of saving eeprom image to chip.
        while(1);
    }
    else{
        printk("\n\n           Error unlocking drives with previous key.");
        printk("\n           Actual EEPROM has NOT been changed.");
        printk("\n           Please Manually unlock all connected HDDs before modifying EEPROM content.");
        UIFooter();
    }
}

void editMACAddress(void *ignored){
    u8 i, j;
    char macString[13];
    u8 nibble[2];
    sprintf(macString, "%02X%02X%02X%02X%02X%02X",
    editeeprom->MACAddress[0], editeeprom->MACAddress[1], editeeprom->MACAddress[2],
    editeeprom->MACAddress[3], editeeprom->MACAddress[4], editeeprom->MACAddress[5]);
    OnScreenKeyboard(macString, 13, 3, HEX_KEYPAD); //Function will add terminating character.
    if(strlen(macString) == 12){
        for(i = 0; i < 6; i++){
            for(j = 0; j < 2; j++){
                //Dumdum way of converting string of hex into actual hex.
                switch(macString[i*2 + j]){
                    case '0':
                        nibble[j] = 0;
                        break;
                    case '1':
                        nibble[j] = 0x1;
                        break;
                    case '2':
                        nibble[j] = 0x2;
                        break;
                    case '3':
                        nibble[j] = 0x3;
                        break;
                    case '4':
                        nibble[j] = 0x4;
                        break;
                    case '5':
                        nibble[j] = 0x5;
                        break;
                    case '6':
                        nibble[j] = 0x6;
                        break;
                    case '7':
                        nibble[j] = 0x7;
                        break;
                    case '8':
                        nibble[j] = 0x8;
                        break;
                    case '9':
                        nibble[j] = 0x9;
                        break;
                    case 'A':
                        nibble[j] = 0xA;
                        break;
                    case 'B':
                        nibble[j] = 0xB;
                        break;
                    case 'C':
                        nibble[j] = 0xC;
                        break;
                    case 'D':
                        nibble[j] = 0xD;
                        break;
                    case 'E':
                        nibble[j] = 0xE;
                        break;
                    case 'F':
                        nibble[j] = 0xF;
                        break;
                }
            }
            editeeprom->MACAddress[i] = (nibble[0] << 4) | nibble[1];
        }
    }
}

void restoreEEPROMFromFile(void *fname) {
    int res;
    FATXFILEINFO fileinfo;
    FATXPartition *partition;

    partition = OpenFATXPartition (0, SECTOR_SYSTEM, SYSTEM_SIZE);

    res = LoadFATXFile(partition, fname, &fileinfo);
    ToolHeader("Load EEPROM image from HDD");
    if(res){
        updateEEPROMEditBufferFromInputBuffer(fileinfo.buffer, fileinfo.fileSize);
        free(fileinfo.buffer);
    }
    else{
            printk("\n\n           Error!\n           File read error.");
    }
    UIFooter();
}

int updateEEPROMEditBufferFromInputBuffer(u8 *buffer, u32 size){
    int res = 0, version, tempVersion;
    u8 unusedBuffer[0x30];

    if(size != 256){
        res = -3;
    }
    else{
        version = decryptEEPROMData((u8 *)&eeprom, unusedBuffer);
        tempVersion = decryptEEPROMData(buffer, unusedBuffer);
        if(version >= 9 && version < 13){   //Current content in eeprom is valid.
            //Let's check if load eeprom image is of same version.
            if(tempVersion >= 9 && tempVersion < 13){
                //Need user confirmation if versions are not equal.
                if((version == tempVersion) || !ConfirmDialog("     EEPROM version mismatch. Continue anyway?", 1)){
                    memcpy(editeeprom, buffer, size);
                    res = 1;
                }
                else{
                    res = -2;   //Aborted by user.
                }
            }
            else{
                res = -1;   //loaded EEPROM image is not valid
            }
        }
        else{       //Content of EEPROM chip is not valid, let's go ahead and skip version matching.
            if(tempVersion >= 9 && tempVersion < 13){       //Still, we won't accept an invalid input image.
                memcpy(editeeprom, buffer, size);
                res = 1;
            }
            else
                res = -1;   //loaded EEPROM image is not valid
        }
    }

    if(res > 0){
        printk("\n\n           Success!.\n           EEPROM image successfully loaded to modified EEPROM buffer.");
    }
    else{
        printk("\n\n           Error!");
        if(res == -1)
            printk("\n           Invalid EEPROM image file.");
        else if(res == -2)
            printk("\n           Aborted by user.");
        else if(res == -3)
            printk ("\n          EEPROM image file size wrong.");
    }
    return res;
}
