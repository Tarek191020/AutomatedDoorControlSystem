/*
 * LCD_interface.h
 *
 * Created: 2/3/2024 10:05:04 PM
 * Author: Tarek Alaa
 */ 

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include"DIO_interface.h"

void LCD_voidInit();
void LCD_voidWriteData(u8 copy_u8data);

void LCD_voidWriteCommand(u8 copy_u8Command);



void LCD_voidWriteString(u8 * copy_str);

void LCD_voidGoToXY(u8 copy_u8Row,u8 copy_u8Col);

void LCD_voidClear(void);
void LCD_voidWriteNumber( u32 Copy_u32num );


void LCD_voidWriteSpecialCharToCGRAM(u8 * copy_u8data , u8 copy_u8ByteNum );

void LCD_voidDisplaySpecialChar(u8 copy_u8ByteNum ) ;


#endif