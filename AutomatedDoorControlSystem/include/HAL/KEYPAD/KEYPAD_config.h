/*
 * KEYPAD_config.h
 *
 * Created: 3/3/2024 7:00:00 PM
 * Author: Tarek Alaa
 */ 

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_


const KEYPADCONFIG_t keypadConfig = {
	.ROWS_PORT = DIO_PORTC,
	.ROWPINS = {DIO_PIN5, DIO_PIN4, DIO_PIN3, DIO_PIN2},
	.COLSPORT = DIO_PORTD,
	.COLPINS = {DIO_PIN7, DIO_PIN6, DIO_PIN5, DIO_PIN3},
	.arr={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}}
};

#endif