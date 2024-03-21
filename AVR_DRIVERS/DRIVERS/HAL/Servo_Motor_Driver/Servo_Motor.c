/*
 * Servo_Motor.c
 *
 * Created: 3/18/2024 1:06:22 PM
 *  Author: ROAA  Aiman 
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Servo_Motor.h"
#include "DIO_interface.h"
#include "PWM_Interface.h"

void Servo_Motor_voidIntialization(void)
{
	DIO_voidSetPinDirection ( DIO_PORTD	,  DIO_PIN5,  DIO_PIN_OUTPUT);
	PWM_voidInitializeChannel_1A();
}
void Servo_Motor_voidON(u32 copy_u32Angale)
{
	f32 Local_u8DutyCycle =((((f32)copy_u32Angale + 90)/180)*5)+5 ;  
  	PWM_voidGenerateChannel_1A (50,Local_u8DutyCycle);
	
}

void Servo_Motor_voidOFF(void)
{
	PWM_voidStopChannel_1A();
}