/*
 * DIO_register.h
 *
 * Created: 2/29/2024 1:00:00 PM
 * Author: Tarek Alaa
 */ 

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

		/********************MACROS FOR DIO REGISTERS********************/
/*Macros for direction registers*/
#define DIO_DDRA_R   *((volatile u8*)0x3A)
#define DIO_DDRB_R   *((volatile u8*)0x37)
#define DIO_DDRC_R   *((volatile u8*)0x34)
#define DIO_DDRD_R   *((volatile u8*)0x31)

/*Macros for output registers*/
#define DIO_PORTA_R  *((volatile u8*)0x3B)
#define DIO_PORTB_R  *((volatile u8*)0x38)
#define DIO_PORTC_R  *((volatile u8*)0x35)
#define DIO_PORTD_R  *((volatile u8*)0x32)

/*Macros for input registers*/
#define DIO_PINA_R  *((volatile u8*)0x39)
#define DIO_PINB_R  *((volatile u8*)0x36)
#define DIO_PINC_R  *((volatile u8*)0x33)
#define DIO_PIND_R  *((volatile u8*)0x30)

#endif /*DIO_REGISTER_H_*/