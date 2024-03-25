/*
 * LED_program.c
 *
 * Created: 3/7/2024 4:16:03 AM
 *  Author: Tarek Alaa
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LED_config.h"
#include "LED_interface.h"

void LED_voidInit()
{
	DIO_voidSetPinDirection(LED_PORT, LED_PIN, DIO_PIN_OUTPUT);
}
void LED_voidTurnOn()
{
	DIO_voidSetPinValue(LED_PORT, LED_PIN, DIO_PIN_HIGH);
}
void LED_voidTurnOff()
{
	DIO_voidSetPinValue(LED_PORT, LED_PIN, DIO_PIN_LOW);
}
void LED_voidToggle()
{
	DIO_voidTogglePinValue(LED_PORT, LED_PIN);
}