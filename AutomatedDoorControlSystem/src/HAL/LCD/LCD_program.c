/*
 * LCD_program.c
 *
 * Created: 2/3/2024 10:05:04 PM
 * Author: Tarek Alaa
 */ 
#define F_CPU 8000000UL
#include"BIT_MATH.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include <util/delay.h>

static void intToString(u32 num, u8* buffer);

void LCD_voidInit()
{
	_delay_ms(200);
	
	#if LCD_4BITS_MODE ==1
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_PIN4, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_PIN2, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_PIN1, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_PIN0, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, RS_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_OUTPUT);
	
	LCD_voidWriteCommand(RETURN_HOME);
	_delay_ms(10);
	LCD_voidWriteCommand(FOUR_BITS);
	
	_delay_ms(1);
	
	LCD_voidWriteCommand(CURSOR_ON_DISPLAN_ON);
	
	_delay_ms(1);
	
	LCD_voidWriteCommand(CLR_SCREEN);
	
	_delay_ms(10);
	
	LCD_voidWriteCommand(ENTRY_MODE);
	_delay_ms(1);
	#else
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, RS_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPortDirection(LCD_DATA_PORT, DIO_PIN_OUTPUT);
	
	LCD_voidWriteCommand(EIGHT_BITS);
	
	_delay_ms(1);
	
	LCD_voidWriteCommand(CURSOR_ON_DISPLAN_ON);
	
	_delay_ms(1);
	
	LCD_voidWriteCommand(CLR_SCREEN);
	
	_delay_ms(10);
	
	LCD_voidWriteCommand(ENTRY_MODE);
	_delay_ms(1);
	#endif
}

void LCD_voidWriteCommand(u8 copy_u8command)
{
	#if LCD_4BITS_MODE==1
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_PIN4, GET_BIT(copy_u8command, 7));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_PIN2, GET_BIT(copy_u8command, 6));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_PIN1, GET_BIT(copy_u8command, 5));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_PIN0, GET_BIT(copy_u8command, 4));
	
	DIO_voidSetPinValue(LCD_CONTROL_PORT, RS_PIN, DIO_PIN_LOW);
	
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_LOW);
	_delay_ms(2);
	
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_PIN4, GET_BIT(copy_u8command, 3));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_PIN2, GET_BIT(copy_u8command, 2));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_PIN1, GET_BIT(copy_u8command, 1));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_PIN0, GET_BIT(copy_u8command, 0));
	DIO_voidSetPinValue(LCD_CONTROL_PORT, RS_PIN, DIO_PIN_LOW);
	
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_LOW);
	_delay_ms(2);
	
	#else
	DIO_voidSetPortValue(LCD_DATA_PORT, copy_u8command);
	
	DIO_voidSetPinValue(LCD_CONTROL_PORT, RS_PIN, DIO_PIN_LOW);
	
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_LOW);
	_delay_ms(2);
	#endif	
	_delay_ms(1);
}
void LCD_voidWriteData(u8 copy_u8data)
{
	#if LCD_4BITS_MODE==1
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_PIN4, GET_BIT(copy_u8data, 7));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_PIN2, GET_BIT(copy_u8data, 6));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_PIN1, GET_BIT(copy_u8data, 5));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_PIN0, GET_BIT(copy_u8data, 4));
	
	DIO_voidSetPinValue(LCD_CONTROL_PORT, RS_PIN, DIO_PIN_HIGH);
	
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_LOW);
	_delay_ms(2);
	
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_PIN4, GET_BIT(copy_u8data, 3));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_PIN2, GET_BIT(copy_u8data, 2));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_PIN1, GET_BIT(copy_u8data, 1));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_PIN0, GET_BIT(copy_u8data, 0));
	DIO_voidSetPinValue(LCD_CONTROL_PORT, RS_PIN, DIO_PIN_HIGH);
	
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_LOW);
	_delay_ms(2);
	
	#else
	DIO_voidSetPortValue(LCD_DATA_PORT, copy_u8data);
	
	DIO_voidSetPinValue(LCD_CONTROL_PORT, RS_PIN, DIO_PIN_HIGH);
	
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_LOW);
	_delay_ms(2);
	#endif
	_delay_ms(1);	
}
void LCD_voidWriteString(u8 *copy_str)
{
	while((*copy_str)!='\0')
	{
		LCD_voidWriteData(*copy_str);
		copy_str++;
	}
}
void LCD_voidGoToXY(u8 copy_u8Row,u8 copy_u8Col)
{
	switch(copy_u8Row)
	{
		case 0:
			LCD_voidWriteCommand(0x80+copy_u8Col);
			break;
		case 1:
			LCD_voidWriteCommand(0xC0+copy_u8Col);
			break;
		case 2:
			LCD_voidWriteCommand(0x94+copy_u8Col);
			break;
		case 3:
			LCD_voidWriteCommand(0xD4+copy_u8Col);
			break;
		default:
			break;
	}
	_delay_ms(1);
}
void LCD_voidClear(void)
{
	LCD_voidWriteCommand(CLR_SCREEN);
	_delay_ms(10);
}
static void intToString(u32 num, u8* buffer) 
{
	int i = 0;
	while(num != 0) 
	{
		buffer[i++]=(num % 10) + '0';
		num/=10;
	}
	buffer[i]='\0';
	for(int j=0, k=i-1; j<k; j++, k--) 
	{
		u8 temp=buffer[j];
		buffer[j]=buffer[k];
		buffer[k]=temp;
	}
}
void LCD_voidWriteNumber( u32 Copy_u32num )
{
	u8 buffer[20];
	if(Copy_u32num == 0)
	{
		LCD_voidWriteData('0');
	}
	intToString(Copy_u32num, buffer);
	u8 i=0;
	while(buffer[i]!='\0') 
	{
		LCD_voidWriteData(buffer[i]);
		i++;
	}
}
void LCD_voidWriteSpecialCharToCGRAM(u8 * copy_u8data , u8 copy_u8ByteNum )
{
	LCD_voidWriteCommand(0x40+(copy_u8ByteNum*8));
	for (u8 i=0;i<8;i++)
	{
		LCD_voidWriteData(copy_u8data[i]);
	}
	LCD_voidWriteCommand(0b10000000);
}
void LCD_voidDisplaySpecialChar(u8 copy_u8ByteNum )
{
	LCD_voidWriteCommand(0x40+(copy_u8ByteNum*8));
	LCD_voidGoToXY(3,19);
	LCD_voidWriteData(copy_u8ByteNum);
}