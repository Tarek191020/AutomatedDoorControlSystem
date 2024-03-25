/*
 * BUZZER_program.c
 *
 * Created: 3/20/2024 2:12:23 PM
 *  Author: Tarek Alaa
 */ 


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "BUZZER_interface.h"
#include "BUZZER_config.h"

void BUZZER_voidInit()
{
	DIO_voidSetPinDirection(BUZZER_PORT, BUZZER_PIN, DIO_PIN_OUTPUT);
}
void BUZZER_voidTurnOn()
{
	DIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_PIN_HIGH);
}
void BUZZER_voidTurnOff()
{
	DIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_PIN_LOW);
}
void BUZZER_voidToggle()
{
	DIO_voidTogglePinValue(BUZZER_PORT, BUZZER_PIN);
}