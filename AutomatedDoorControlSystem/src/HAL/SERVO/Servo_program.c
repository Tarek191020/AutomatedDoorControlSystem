/*
 * Servo_program.c
 *
 * Created: 3/18/2024 12:35:01 PM
 *  Author: Tarek Alaa
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PWM_interface.h"

void SERVO_voidInit(void)
{
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);
	PWM_voidInitChannel_1A();
}

void SERVO_voidOn(u8 copy_u8Angle)
{
	f32 DutyCycle = (((copy_u8Angle)/180.0)*5)+5;
	PWM_voidGenerate_PWM_Channel_1A(50, DutyCycle);
}

void SERVO_voidOff()
{
	PWM_voidStop_PWM_Channel_1A();
}