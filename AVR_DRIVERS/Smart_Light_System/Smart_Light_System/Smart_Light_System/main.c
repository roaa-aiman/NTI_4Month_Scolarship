/*
 * main.c
 *
 *  Created on: Mar 1, 2024
 *      Author: Roaa aiman
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KPD.h"
#include "ADC_interface.h"
#include <stdlib.h>
#include <stdio.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	u16 digitalValue, AnalogValue;
	u8 Threshold_arr[2] = {0}, counter = 0;
	u8 Local_u8PressedKey;
	
	DIO_voidInit();
	LCD_INIT();
	ADC_voidInit(VOLTAGE_REFERENCE_AVCC);
	
	while(1)
	{
		LCD_CLEAR_SCREEN();
		LCD_GOTOXY(0,0);
		counter = 0;
		u8 myString1[] = "Enter threshold:";
		LCD_voidSendString(myString1);
		
		while(counter < 2)
		{
			Local_u8PressedKey = KPD_u8GetPressedKey();
			if(Local_u8PressedKey != NO_PRESSED_KEY)
			{
				LCD_WRITE_CHAR(Local_u8PressedKey);
				Threshold_arr[counter] = Local_u8PressedKey;
				counter++;
			}
		}
		u16 Threshold = (Threshold_arr[0] - '0') * 10 + (Threshold_arr[1] - '0');
		
		ADC_voidGetDigitalValue(ADC_CHANNEL_1, &digitalValue);
		AnalogValue = digitalValue/10;
		
		LCD_GOTOXY(1,0);
		u8 myString2[] = "light percentage:";
		LCD_voidSendString(myString2);
		LCD_voidWriteNumber(AnalogValue);
		LCD_WRITE_CHAR('%');
		
		if(AnalogValue > Threshold)
		{
			DIO_voidSetPinValue(DIO_PORTC, DIO_PIN0, DIO_PIN_LOW);
		}
		else
		{
			DIO_voidSetPinValue(DIO_PORTC, DIO_PIN0, DIO_PIN_HIGH);
		}
		_delay_ms(1000);
	}
	
	return 0 ;
}
