/*
 * PWM_interface.h
 *
 * Created: 3/17/2024 10:47:47 AM
 *  Author: Tarek Alaa
 */ 


#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

typedef enum
{
	_NO_CLOCK,
	_NO_PRESCALING,
	_8_PRESCALER,
	_64_PRESCALER,
	_256_PRESCALER,
	_1024_PRESCALER,
	_EXT_CLCK_FALLING,
	_EXT_CLCK_RISING
}PRESCALER_t;

						/***********************************CH0**************************************/

void PWM_voidInitChannel_0			(void);
void PWM_voidGenerate_PWM_Channel_0	(u8 copy_u8DutyCycle, PRESCALER_t copy_enumPrescaler);
void PWM_voidStop_PWM_Channel_0		(void);

						/***********************************CH1A**************************************/

void PWM_voidInitChannel_1A			(void);
void PWM_voidGenerate_PWM_Channel_1A(u16 copy_u16Frequency_HZ, f32 copy_f32DutyCycle);
void PWM_voidStop_PWM_Channel_1A	(void);

						/***********************************CH2**************************************/

void PWM_voidInitChannel_2			(void);
void PWM_voidGenerate_PWM_Channel_2	(u8 copy_u8DutyCycle, PRESCALER_t copy_enumPrescaler);
void PWM_voidStop_PWM_Channel_2		(void);


#endif /* PWM_INTERFACE_H_ */