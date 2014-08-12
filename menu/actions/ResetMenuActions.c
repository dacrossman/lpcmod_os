/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#include "ResetMenuActions.h"

void SlowReboot(void *ignored){
	assertWriteEEPROM();
	I2CRebootSlow();
}

void QuickReboot(void *ignored){
	assertWriteEEPROM();
	I2CRebootQuick();
}

void PowerOff(void *ignored) {
	assertWriteEEPROM();
	I2CPowerOff();
}
