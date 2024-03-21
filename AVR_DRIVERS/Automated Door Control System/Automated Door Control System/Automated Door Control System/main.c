/*
 * main.c
 *
 *  Created on: Mar 1, 2024
 *      Author: Roaa aiman
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KPD.h"
#include "Servo_Motor.h"
#include <util/delay.h>
#include <string.h>

#define PASSWORD_LENGTH    4
#define CORRECT_PASSWORD   "1234"

int main(void) {
	u8 password[PASSWORD_LENGTH + 1] = {0}; // Extra space for null terminator
	u8 Flag = 0;
	u8 Counter;
	u8 Local_u8PressedKey;

	DIO_voidInit();
	LCD_INIT();
	Servo_Motor_voidIntialization();

	while (1) 
	{
		Counter = 0;
		memset(password, 0, sizeof(password)); // Clear password array

		LCD_CLEAR_SCREEN();
		LCD_GOTOXY(0, 0);
		u8 myString1[] ="Enter Password:";
		LCD_voidSendString(myString1);

		for (u8 i = 0; i < 3; i++)
		 {
			while (Counter < PASSWORD_LENGTH)
			 {
				Local_u8PressedKey = KPD_u8GetPressedKey();
				if (Local_u8PressedKey != NO_PRESSED_KEY) 
				{
					LCD_WRITE_CHAR('*'); // Mask password input
					password[Counter++] = Local_u8PressedKey;
					_delay_ms(100); // Debouncing delay
				}
			}

			if (strcmp((char*)password, CORRECT_PASSWORD) == 0)
			 {
				Flag = 1;
				break;
			} 
			else 
			{
				Flag = 0;
				LCD_CLEAR_SCREEN();
				LCD_GOTOXY(0, 0);
				u8 myString2[] ="Try Again:";
				LCD_voidSendString(myString2);
				Counter = 0;
				//_delay_ms(1000);
			}
		}

		if (Flag == 1) 
		{
			LCD_CLEAR_SCREEN();
			LCD_GOTOXY(0, 0);
			u8 myString3[] ="Welcome";
			LCD_voidSendString(myString3);
			Servo_Motor_voidON(180);
			_delay_ms(1000);
			Servo_Motor_voidOFF();
			_delay_ms(1000);
			Servo_Motor_voidON(0);
			_delay_ms(1000);
			Servo_Motor_voidOFF();
			} 
		else 
		{
			LCD_CLEAR_SCREEN();
			LCD_GOTOXY(0, 0);
			u8 myString4[] ="NOW More Try";
			LCD_voidSendString(myString4);
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN5, DIO_PIN_HIGH); // Indicate wrong password
			DIO_voidTogglePinValue (DIO_PORTA, DIO_PIN6);
			_delay_ms(1000);
		}

		_delay_ms(1000);
	}

	return 0;
}
