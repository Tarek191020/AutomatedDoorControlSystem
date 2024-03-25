/*
 * KEYPAD_program.c
 *
 * Created: 3/3/2024 7:00:00 PM
 * Author: Tarek Alaa
 */ 
#define F_CPU 16000000
#include <util/delay.h>
/*include libraries*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*include MCAL*/
#include"DIO_interface.h"

/*include headers*/
#include"KEYPAD_interface.h"
#include"KEYPAD_config.h"

//u8 arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};

void KEYPAD_voidInit()
{
	for (u8 i = 0; i < 4; i++) {
		DIO_voidSetPinDirection(keypadConfig.ROWS_PORT, keypadConfig.ROWPINS[i], DIO_PIN_OUTPUT);
	}
	for (u8 i = 0; i < 4; i++) {
		DIO_voidSetPinDirection(keypadConfig.COLSPORT, keypadConfig.COLPINS[i], DIO_PIN_INPUT);
		DIO_voidActivePinPullUpResistance(keypadConfig.COLSPORT, keypadConfig.COLPINS[i]);
	}
}

void KEYPAD_voidGetButton(u8 *copy_u8Press)
{
	*copy_u8Press = NOTPRESSED;

	for (u8 row = 0; row < 4; row++)
	{
		// Activate the current row
		DIO_voidSetPinValue(keypadConfig.ROWS_PORT, keypadConfig.ROWPINS[row], DIO_PIN_LOW);

		for (u8 col = 0; col < 4; col++)
		{
			// Check the state of the column pins
			u8 pinState = DIO_PIN_HIGH;
			DIO_voidGetPinValue(keypadConfig.COLSPORT, keypadConfig.COLPINS[col], &pinState);
			
			if (pinState == DIO_PIN_LOW)
			{
				// Delay for a short period to debounce the button
				_delay_ms(10);

				// Check the pin state again after debouncing
				DIO_voidGetPinValue(keypadConfig.COLSPORT, keypadConfig.COLPINS[col], &pinState);

				// If the pin state is still low, register the button press
				if (pinState == DIO_PIN_LOW)
				{
					// Button pressed, determine the corresponding character
					*copy_u8Press = keypadConfig.arr[row][col];

					// Wait until the button is released
					while (pinState == DIO_PIN_LOW)
					{
						DIO_voidGetPinValue(keypadConfig.COLSPORT, keypadConfig.COLPINS[col], &pinState);
						_delay_ms(10);
					}
				}
			}
		}

		// Deactivate the current row
		DIO_voidSetPinValue(keypadConfig.ROWS_PORT, keypadConfig.ROWPINS[row], DIO_PIN_HIGH);
	}
}