/*
 * KEYPAD_interface.h
 *
 * Created: 3/3/2024 7:00:00 PM
 * Author: Tarek Alaa
 */ 

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "STD_TYPES.h"

#define NOTPRESSED  0xff

typedef struct {
	u8 ROWS_PORT;       // Port of the keypad rows
	u8 ROWPINS[4];      // Pins of the keypad rows (4 rows)
	u8 COLSPORT;        // Port of the keypad columns
	u8 COLPINS[4];      // Pins of the keypad columns (4 columns)
	u8 arr[4][4];
}KEYPADCONFIG_t;

void KEYPAD_voidInit();
void KEYPAD_voidGetButton(u8 *copy_u8press);

#endif
