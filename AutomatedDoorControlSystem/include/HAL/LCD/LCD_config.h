/*
 * LCD_config.h
 *
 * Created: 2/3/2024 10:05:04 PM
 * Author: Tarek Alaa
 */ 
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_



#define LCD_4BITS_MODE 1
#define LCD_8BINS_MODE 0

#define EN_PIN				DIO_PIN2
#define RS_PIN				DIO_PIN3

/*LCD Ports*/
#define LCD_DATA_PORT       DIO_PORTB
#define LCD_CONTROL_PORT    DIO_PORTA

/*LCD Pins*/
#define LCD_PIN0            DIO_PIN0
#define LCD_PIN1            DIO_PIN1
#define LCD_PIN2            DIO_PIN2
#define LCD_PIN3            DIO_PIN3
#define LCD_PIN4            DIO_PIN4
#define LCD_PIN5            DIO_PIN5
#define LCD_PIN6            DIO_PIN6
#define LCD_PIN7            DIO_PIN7

/*commands*/
#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define EIGHT_BITS 0x38
#define FOUR_BITS 0x28

#endif