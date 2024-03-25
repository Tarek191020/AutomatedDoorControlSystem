/*
 * PWM_register.h
 *
 * Created: 3/17/2024 10:48:44 AM
 *  Author: Tarek Alaa
 */ 


#ifndef PWM_REGISTER_H_
#define PWM_REGISTER_H_

#include "STD_TYPES.h"

						/***********************************CH0REGS**************************************/

// Timer/Counter0 Control Register
#define TCCR0_REG			(*(volatile u8*)0x53)
#define CS00                0
#define CS01                1
#define CS02                2
#define WGM01               3
#define COM00               4
#define COM01               5
#define WGM00               6
#define FOC0                7

// Timer/Counter0 Register
#define TCNT0_REG           (*(volatile u8*)0x52)

// Output Compare Register0
#define OCR0_REG            (*(volatile u8*)0x5C)


						/***********************************CH1AREGS**************************************/

typedef struct
{
	u16 ICR1L;
	u16 OCR1BL;
	u16 OCR1AL;
	u16 TCNT1L;
	u8 TCCR1B;
	u8 TCCR1A;
}TMR1;

#define TMR1_REG	((volatile TMR1*)(0x46))

//TCCR1A bits
#define TCCR1A_WGM10		0
#define TCCR1A_WGM11		1
#define TCCR1A_FOC1B		2
#define TCCR1A_FOC1A		3
#define TCCR1A_COM1B0		4
#define TCCR1A_COM1B1		5
#define TCCR1A_COM1A0		6
#define TCCR1A_COM1A1		7

//TCCR1B bits
#define TCCR1B_CS10			0
#define TCCR1B_CS11			1
#define TCCR1B_CS12			2
#define TCCR1B_WGM12		3
#define TCCR1B_WGM13		4
#define TCCR1B_ICES1		6
#define TCCR1B_ICNC1		7


						/***********************************CH2REGS**************************************/

// Timer/Counter2 Control Register
#define TCCR2_REG			(*(volatile u8*)0x45)
#define CS20                0
#define CS21                1
#define CS22                2
#define WGM21               3
#define COM20               4
#define COM21               5
#define WGM20               6
#define FOC0                7

// Timer/Counter2 Register
#define TCNT2_REG           (*(volatile u8*)0x44)

// Output Compare Register2
#define OCR2_REG            (*(volatile u8*)0x43)


// Timer/Counter Interrupt Mask Register
#define TIMSK_REG           (*(volatile u8*)0x59)
#define TOIE0               0
#define OCIE0               1

// Timer/Counter Interrupt Flag Register
#define TIFR_REG            (*(volatile u8*)0x58)
#define TOV0                0
#define OCF0                1


#endif /* PWM_REGISTER_H_ */