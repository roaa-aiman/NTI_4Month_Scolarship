/*
 * DC_Motor.c
 *
 * Created: 3/19/2024 8:25:00 AM
 *  Author: Roaa Aiman
 */
#include  "DIO_interface.h"
void DC_MOTOR_voidIntialization(void)
{
	DIO_voidSetPinDirection ( DIO_PORTB	,  DIO_PIN3,  DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection ( DIO_PORTB	,  DIO_PIN5,  DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection ( DIO_PORTB	,  DIO_PIN6,  DIO_PIN_OUTPUT);	
}
void DC_MOTOR_void_CW(void)
{
   DIO_voidSetPinValue (DIO_PORTB	,  DIO_PIN5,  DIO_PIN_HIGH);	
}
void DC_MOTOR_void_CCW(void)
{
	DIO_voidSetPinValue (DIO_PORTB	,  DIO_PIN5,  DIO_PIN_LOW);
}

void DC_MOTOR_voidOFF(void)
{
	
}

