/*
 * PWM_program.c
 *
 * Created: 3/17/2024 10:49:01 AM
 *  Author: Tarek Alaa
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PWM_interface.h"
#include "PWM_config.h"
#include "PWM_private.h"
#include "PWM_register.h"


void PWM_voidInitChannel_0(void)
{
	//select PWM generation mode
	#if PWM_WAVE_GENERATION_MODE_CH0 == FAST_PWM_MODE
		//select fastPWM mode
		SET_BIT(TCCR0_REG, WGM00);
		SET_BIT(TCCR0_REG, WGM01);
	#elif PWM_WAVE_GENERATION_MODE_CH0 == PWM_PHASE_CORRECT_MODE
		//select PWM Phase correct mode
		SET_BIT(TCCR0_REG, WGM00);
		CLR_BIT(TCCR0_REG, WGM01);
	#endif
	// select pwm compare output mode
	#if PWM_COMPARE_OUTPUT_MODE_CH0 == PWM_NON_INVERTING_MODE
		//select non-inverting mode
		CLR_BIT(TCCR0_REG, COM00);
		SET_BIT(TCCR0_REG, COM01);
	#elif PWM_COMPARE_OUTPUT_MODE_CH0 == PWM_INVERTING_MODE
		//select inverting mode
		SET_BIT(TCCR0_REG, COM00);
		SET_BIT(TCCR0_REG, COM01);
	#endif
	
	
}
void PWM_voidGenerate_PWM_Channel_0	(u8 copy_u8DutyCycle, PRESCALER_t copy_enumPrescaler)
{
	if(copy_u8DutyCycle<=100)
	{
		#if PWM_WAVE_GENERATION_MODE_CH0 == FAST_PWM_MODE
			#if PWM_COMPARE_OUTPUT_MODE_CH0 == PWM_NON_INVERTING_MODE
				//set value duty
				OCR0_REG = (((u16)copy_u8DutyCycle*256)/100)-1;
				//select prescaler
				TCCR0_REG |= copy_enumPrescaler;
				
			#elif PWM_COMPARE_OUTPUT_MODE_CH0 == PWM_INVERTING_MODE
				//set value duty
				OCR0_REG = (256-(((u16)copy_u8DutyCycle*256)/100))-1;
				//select prescaler 
				TCCR0_REG |= copy_enumPrescaler;
			#endif
		#elif PWM_WAVE_GENERATION_MODE_CH0 == PWM_PHASE_CORRECT_MODE
			#if PWM_COMPARE_OUTPUT_MODE_CH0 == PWM_NON_INVERTING_MODE
				//set value duty
				OCR0_REG = (((u16)copy_u8DutyCycle*255)/100)-1;
				//select prescaler
				TCCR0_REG |= copy_enumPrescaler;
			#elif PWM_COMPARE_OUTPUT_MODE_CH0 == PWM_INVERTING_MODE
				//set value duty
				OCR0_REG = (255-(((u16)copy_u8DutyCycle*255)/100))-1;
				//select prescaler
				TCCR0_REG |= copy_enumPrescaler;
			#endif
		#endif
	}
	else
	{
		//return error state
	}
}
void PWM_voidStop_PWM_Channel_0()
{
	// Disable PWM by clearing the PWM control register (TCCR0)
	TCCR0_REG =0;
}


void PWM_voidInitChannel_1A			(void)
{
	//select mode 14
	CLR_BIT(TMR1_REG->TCCR1A, TCCR1A_WGM10);
	SET_BIT(TMR1_REG->TCCR1A, TCCR1A_WGM11);
	SET_BIT(TMR1_REG->TCCR1B, TCCR1B_WGM12);
	SET_BIT(TMR1_REG->TCCR1B, TCCR1B_WGM13);
	
	#if PWM_COMPARE_OUTPUT_MODE_CH1A == PWM_NON_INVERTING_MODE
	//select noninverting mode
	CLR_BIT(TMR1_REG->TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TMR1_REG->TCCR1A, TCCR1A_COM1A1);
	#elif PWM_COMPARE_OUTPUT_MODE_CH1A == PWM_INVERTING_MODE
	//select inverting mode
	SET_BIT(TMR1_REG->TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TMR1_REG->TCCR1A, TCCR1A_COM1A1);
	#endif
	
}
void PWM_voidGenerate_PWM_Channel_1A(u16 copy_u16Frequency_HZ, f32 copy_f32DutyCycle)
{
	if (copy_f32DutyCycle<=100)
	{
		
		//select freq
		TMR1_REG->ICR1L = ((1000000UL/copy_u16Frequency_HZ)/4)-1;//undercondition ticktime=4us
		
		//select dutycycle
		TMR1_REG->OCR1AL = ((copy_f32DutyCycle*(TMR1_REG->ICR1L+1))/100)-1;
		
		//select prescaler 64
		SET_BIT(TMR1_REG->TCCR1B, TCCR1B_CS10);
		SET_BIT(TMR1_REG->TCCR1B, TCCR1B_CS11);
		CLR_BIT(TMR1_REG->TCCR1B, TCCR1B_CS12);
	}
	else
	{
		//return error state
	}
}

void PWM_voidStop_PWM_Channel_1A()
{
	/*
	CLR_BIT(TMR1_REG->TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TMR1_REG->TCCR1A, TCCR1A_WGM11);
	CLR_BIT(TMR1_REG->TCCR1B, TCCR1B_WGM12);
	CLR_BIT(TMR1_REG->TCCR1B, TCCR1B_WGM13);
	CLR_BIT(TMR1_REG->TCCR1A, TCCR1A_COM1A0);
	CLR_BIT(TMR1_REG->TCCR1A, TCCR1A_COM1A1);
	*/
	CLR_BIT(TMR1_REG->TCCR1B, TCCR1B_CS10);
	CLR_BIT(TMR1_REG->TCCR1B, TCCR1B_CS11);
	CLR_BIT(TMR1_REG->TCCR1B, TCCR1B_CS12);
}

void PWM_voidInitChannel_2			(void)
{
	//select PWM generation mode
	#if PWM_WAVE_GENERATION_MODE_CH2 == FAST_PWM_MODE
	//select fastPWM mode
	SET_BIT(TCCR2_REG, WGM20);
	SET_BIT(TCCR2_REG, WGM21);
	#elif PWM_WAVE_GENERATION_MODE_CH2 == PWM_PHASE_CORRECT_MODE
	//select PWM Phase correct mode
	SET_BIT(TCCR2_REG, WGM20);
	CLR_BIT(TCCR2_REG, WGM21);
	#endif
	// select pwm compare output mode
	#if PWM_COMPARE_OUTPUT_MODE_CH2 == PWM_NON_INVERTING_MODE
	//select non-inverting mode
	CLR_BIT(TCCR2_REG, COM20);
	SET_BIT(TCCR2_REG, COM21);
	#elif PWM_COMPARE_OUTPUT_MODE_CH2 == PWM_INVERTING_MODE
	//select inverting mode
	SET_BIT(TCCR2_REG, COM20);
	SET_BIT(TCCR2_REG, COM21);
	#endif
}
void PWM_voidGenerate_PWM_Channel_2	(u8 copy_u8DutyCycle, PRESCALER_t copy_enumPrescaler)
{
	if(copy_u8DutyCycle<=100)
	{
		#if PWM_WAVE_GENERATION_MODE_CH2 == FAST_PWM_MODE
		#if PWM_COMPARE_OUTPUT_MODE_CH2 == PWM_NON_INVERTING_MODE
		//set value duty
		OCR2_REG = (((u16)copy_u8DutyCycle*256)/100)-1;
		//select prescaler
		TCCR2_REG |= copy_enumPrescaler;
		
		#elif PWM_COMPARE_OUTPUT_MODE_CH2 == PWM_INVERTING_MODE
		//set value duty
		OCR2_REG = (256-(((u16)copy_u8DutyCycle*256)/100))-1;
		//select prescaler
		TCCR2_REG |= copy_enumPrescaler;
		#endif
		#elif PWM_WAVE_GENERATION_MODE_CH2 == PWM_PHASE_CORRECT_MODE
		#if PWM_COMPARE_OUTPUT_MODE_CH2 == PWM_NON_INVERTING_MODE
		//set value duty
		OCR2_REG = (((u16)copy_u8DutyCycle*255)/100)-1;
		//select prescaler
		TCCR2_REG |= copy_enumPrescaler;
		#elif PWM_COMPARE_OUTPUT_MODE_CH2 == PWM_INVERTING_MODE
		//set value duty
		OCR2_REG = (255-(((u16)copy_u8DutyCycle*255)/100))-1;
		//select prescaler
		TCCR2_REG |= copy_enumPrescaler;
		#endif
		#endif
	}
	else
	{
		//return error state
	}
}
void PWM_voidStop_PWM_Channel_2		(void)
{
	// Disable PWM by clearing the PWM control register (TCCR0)
	TCCR2_REG =0;
}
