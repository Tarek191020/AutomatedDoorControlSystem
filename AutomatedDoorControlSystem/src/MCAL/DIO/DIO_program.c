/*
 * DIO_program.c
 *
 * Created: 2/29/2024 2:00:00 PM
 * Author: Tarek Alaa
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
				/**********************************PIN FUNCTIONS**********************************/		
void DIO_voidSetPinDirection(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
			if(copy_u8PinDirection==DIO_PIN_INPUT)
				CLR_BIT(DIO_DDRA_R, copy_u8PinId);
			else
				SET_BIT(DIO_DDRA_R, copy_u8PinId);
			break;
		case DIO_PORTB:
			if(copy_u8PinDirection==DIO_PIN_INPUT)
				CLR_BIT(DIO_DDRB_R, copy_u8PinId);
			else
				SET_BIT(DIO_DDRB_R, copy_u8PinId);
			break;
		case DIO_PORTC:
			if(copy_u8PinDirection==DIO_PIN_INPUT)
				CLR_BIT(DIO_DDRC_R, copy_u8PinId);
			else
				SET_BIT(DIO_DDRC_R, copy_u8PinId);
			break;
		case DIO_PORTD:
			if(copy_u8PinDirection==DIO_PIN_INPUT)
				CLR_BIT(DIO_DDRD_R, copy_u8PinId);
			else
				SET_BIT(DIO_DDRD_R, copy_u8PinId);
			break;
		default:
			break;
	}
}
void DIO_voidSetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
			if(copy_u8PinValue==DIO_PIN_LOW)
				CLR_BIT(DIO_PORTA_R, copy_u8PinId);
			else
				SET_BIT(DIO_PORTA_R, copy_u8PinId);
			break;
		case DIO_PORTB:
			if(copy_u8PinValue==DIO_PIN_LOW)
				CLR_BIT(DIO_PORTB_R, copy_u8PinId);
			else
				SET_BIT(DIO_PORTB_R, copy_u8PinId);
			break;
		case DIO_PORTC:
			if(copy_u8PinValue==DIO_PIN_LOW)
				CLR_BIT(DIO_PORTC_R, copy_u8PinId);
			else
				SET_BIT(DIO_PORTC_R, copy_u8PinId);
			break;
		case DIO_PORTD:
			if(copy_u8PinValue==DIO_PIN_LOW)
				CLR_BIT(DIO_PORTD_R, copy_u8PinId);
			else
				SET_BIT(DIO_PORTD_R, copy_u8PinId);
			break;
		default:
			break;
	}
}
void DIO_voidGetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8 *copy_pu8PinValue)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
			*copy_pu8PinValue=GET_BIT(DIO_PINA_R, copy_u8PinId);
			break;
		case DIO_PORTB:
			*copy_pu8PinValue=GET_BIT(DIO_PINB_R, copy_u8PinId);
			break;
		case DIO_PORTC:
			*copy_pu8PinValue=GET_BIT(DIO_PINC_R, copy_u8PinId);
			break;
		case DIO_PORTD:
			*copy_pu8PinValue=GET_BIT(DIO_PIND_R, copy_u8PinId);
			break;
		default:
			break;
	}
}
void DIO_voidTogglePinValue(u8 copy_u8PortId, u8 copy_u8PinId)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
			TOGG_BIT(DIO_PORTA_R, copy_u8PinId);
			break;
		case DIO_PORTB:
			TOGG_BIT(DIO_PORTB_R, copy_u8PinId);
			break;
		case DIO_PORTC:
			TOGG_BIT(DIO_PORTC_R, copy_u8PinId);
			break;
		case DIO_PORTD:
			TOGG_BIT(DIO_PORTD_R, copy_u8PinId);
			break;
		default:
			break;
	}
}
void DIO_voidActivePinPullUpResistance(u8 copy_u8PortId, u8 copy_u8PinId)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
			SET_BIT(DIO_PORTA_R, copy_u8PinId);
			break;
		case DIO_PORTB:
			SET_BIT(DIO_PORTB_R, copy_u8PinId);
			break;
		case DIO_PORTC:
			SET_BIT(DIO_PORTC_R, copy_u8PinId);
			break;
		case DIO_PORTD:
			SET_BIT(DIO_PORTD_R, copy_u8PinId);
			break;
		default:
			break;
	}
}

				/**********************************PORT FUNCTIONS**********************************/
void DIO_voidSetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
			DIO_DDRA_R=copy_u8PortDirection;
			break;
		case DIO_PORTB:
			DIO_DDRB_R=copy_u8PortDirection;
			break;
		case DIO_PORTC:
			DIO_DDRC_R=copy_u8PortDirection;
			break;
		case DIO_PORTD:
			DIO_DDRD_R=copy_u8PortDirection;
			break;
		default:
			break;
	}
}
void DIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA:	
			DIO_PORTA_R=copy_u8PortValue;
			break;
		case DIO_PORTB:	
			DIO_PORTB_R=copy_u8PortValue;
			break;
		case DIO_PORTC:	
			DIO_PORTC_R=copy_u8PortValue;
			break;
		case DIO_PORTD:	
			DIO_PORTD_R=copy_u8PortValue;
			break;
		default:
			break;
	}
}
void DIO_voidGetPortValue(u8 copy_u8PortId, u8* copy_pu8PortValue)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
			*copy_pu8PortValue=DIO_PINA_R;
			break;
		case DIO_PORTB:
			*copy_pu8PortValue=DIO_PINB_R;
			break;
		case DIO_PORTC:
			*copy_pu8PortValue=DIO_PINC_R;
			break;
		case DIO_PORTD:
			*copy_pu8PortValue=DIO_PIND_R;
			break;
		default:
			break;
	}
}
void DIO_voidTogglePortValue(u8 copy_u8PortId)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
			(DIO_PORTA_R)^=DIO_PORT_HIGH;
			break;
		case DIO_PORTB:
			(DIO_PORTB_R)^=DIO_PORT_HIGH;
			break;
		case DIO_PORTC:
			(DIO_PORTC_R)^=DIO_PORT_HIGH;
			break;
		case DIO_PORTD:
			(DIO_PORTD_R)^=DIO_PORT_HIGH;
			break;
		default:
			break;
	}
}
void DIO_voidActivePortInPullUpResistance(u8 copy_u8PortId)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
			DIO_PORTA_R=DIO_PORT_HIGH;
			break;
		case DIO_PORTB:
			DIO_PORTB_R=DIO_PORT_HIGH;
			break;
		case DIO_PORTC:
			DIO_PORTC_R=DIO_PORT_HIGH;
			break;
		case DIO_PORTD:
			DIO_PORTD_R=DIO_PORT_HIGH;
			break;
		default:
			break;
	}
}