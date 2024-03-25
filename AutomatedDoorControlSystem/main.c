/*
 * main.c
 *
 * Created: 3/20/2024 1:56:38 PM
 *  Author: Tarek Alaa
 */ 

#define F_CPU  16000000UL
#include <xc.h>
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PWM_interface.h"

#include "KEYPAD_interface.h"
#include "LCD_interface.h"
#include "Servo_interface.h"
#include "LED_interface.h"
#include "BUZZER_interface.h"

int main(void)
{
	/*initialize HAL*/
	LCD_voidInit();
	LED_voidInit();
	BUZZER_voidInit();
	//SERVO_voidInit();
	//KEYPAD_voidInit();
	
	/*init password*/
	u8 password[]={'1','2','3'};
	u8 enteredPassword[3];
	
	/*string variables to use with lcd*/
	u8 str[]="enter password: ";
	u8 WelcomeString[]="welecome";
	u8 WrongString[]="Wrong Password";
	
	/*variables used to check password*/
	u8 trial=0;
	u8 true=0;
	
	u8 close=NOTPRESSED;
	while(1)
	{
		KEYPAD_voidInit();
		LCD_voidClear();
		_delay_ms(100);
		
		LCD_voidWriteString(str);
		LCD_voidGoToXY(1,0);
		
		//entering password using keypad
		for (u8 i=0; i<3; i++)
		{
			true=0;
			do
			{
				KEYPAD_voidGetButton(&enteredPassword[i]);
			} while (enteredPassword[i]==NOTPRESSED);
			LCD_voidWriteData(enteredPassword[i]);
		}
		
		//checking password
		for (u8 i=0;i<3;i++)
		{
			if (enteredPassword[i]==password[i])
			{
				true++;
			}
		}
		_delay_ms(50);
		
		//open door if password true
		if (true==3)
		{
			LCD_voidClear();
			LCD_voidGoToXY(1,5);
			LCD_voidWriteString(WelcomeString);
			SERVO_voidInit();
			SERVO_voidOn(90);
			_delay_ms(1000);
			SERVO_voidOn(0);
			SERVO_voidOff();
			_delay_ms(200);
			trial=0;
		}
		
		//close door if pass is wrong 
		else
		{
			SERVO_voidInit();
			SERVO_voidOn(0);
			_delay_ms(500);
			SERVO_voidOff();
			KEYPAD_voidInit();
			LCD_voidClear();
			LCD_voidGoToXY(1,2);
			LCD_voidWriteString(WrongString);
			trial++;
			//security system fire if 3 trials of password are wrong
			if (trial==3)
			{
				do
				{
					LED_voidTurnOn();
					BUZZER_voidTurnOn();
					KEYPAD_voidGetButton(&close);
					//if any button of keypad pressed security system will stop
					if (close!=NOTPRESSED)
					{
						BUZZER_voidTurnOff();
						LED_voidTurnOff();
						break;
					}
				} while (close==NOTPRESSED);
				trial=0;
			}
		}
		_delay_ms(1000);
	}
}