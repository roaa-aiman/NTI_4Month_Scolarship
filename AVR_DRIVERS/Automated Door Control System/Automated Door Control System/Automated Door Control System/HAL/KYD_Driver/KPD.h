/*
 * KPD.h
 *
 * Created: 3/2/2024 8:08:47 PM
 *  Author: ROAA AIMAN
 */ 


#ifndef KPD_H_
#define KPD_H_
#define F_CPU 16000000UL
#include <avr/io.h>
#include "DIO_interface.h"

#define KPD_ROWS_PORT 	DIO_PORTC

#define KPD_ROW0_PIN 	DIO_PIN5
#define KPD_ROW1_PIN	DIO_PIN4
#define KPD_ROW2_PIN	DIO_PIN3
#define KPD_ROW3_PIN	DIO_PIN2

#define KPD_COLS_PORT 	DIO_PORTD

#define KPD_COL0_PIN 	DIO_PIN7
#define KPD_COL1_PIN	DIO_PIN6
#define KPD_COL2_PIN	DIO_PIN4
#define KPD_COL3_PIN	DIO_PIN3

#define KPD_ARRAY  {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'.','0','=','+'}}

#define NO_PRESSED_KEY 	'\0'

#define NUMBER_OF_ROWS			4
#define NUMBER_OF_COLUMNS		4

u8 KPD_u8GetPressedKey(void);




#endif /* KPD_H_ */