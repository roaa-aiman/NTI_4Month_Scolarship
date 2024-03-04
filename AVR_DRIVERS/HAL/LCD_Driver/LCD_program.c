/*
 * lcd.c
 *
 * Created: 3/2/2024 9:22:07 AM
 *  Author: roaa aiman
 */ 
#include "LCD_interface.h"

void LCD_CLEAR_SCREEN(void)
{
	LCD_WRITE_COMMAND(LCD_CMD_CLEAR_SCREEN);
}

void LCD_lcd_kick(void)
{
	DIO_voidSetPinValue(LCD_CTRL,EN_SWITCH, DIO_PIN_HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_CTRL,EN_SWITCH, DIO_PIN_LOW);
}

void LCD_WRITE_COMMAND(u8 command)
{
	#if LCD_u8_MODE == EIGHT_BIT_MODE
	DIO_voidSetPinValue(LCD_CTRL,RS_PIN, DIO_PIN_LOW);
	DIO_voidSetPortValue(LCD_PORT, command);
	LCD_lcd_kick();
	
	#elif LCD_u8_MODE==FOUR_BIT_MODE
	DIO_voidSetPinValue(LCD_CTRL,RS_PIN, DIO_PIN_LOW);
	DIO_voidSetPinValue (LCD_PORT, CLCD_D7, GET_BIT(command,7) );
	DIO_voidSetPinValue (LCD_PORT, CLCD_D6, GET_BIT(command,6) );
	DIO_voidSetPinValue (LCD_PORT, CLCD_D5, GET_BIT(command,5) );
	DIO_voidSetPinValue (LCD_PORT, CLCD_D4, GET_BIT(command,4) );

	LCD_lcd_kick();
	_delay_us(200);
	
	DIO_voidSetPinValue (LCD_PORT, CLCD_D7, GET_BIT(command,3) );
	DIO_voidSetPinValue (LCD_PORT, CLCD_D6, GET_BIT(command,2) );
	DIO_voidSetPinValue (LCD_PORT, CLCD_D5, GET_BIT(command,1) );
	DIO_voidSetPinValue (LCD_PORT, CLCD_D4, GET_BIT(command,0) );
	LCD_lcd_kick();
	_delay_ms(2);
	
	#endif
}
void LCD_WRITE_CHAR(u8 character)
{
	#if LCD_u8_MODE==EIGHT_BIT_MODE
	DIO_voidSetPinValue(LCD_CTRL,RS_PIN, DIO_PIN_HIGH);
	DIO_voidSetPortValue(LCD_PORT, character);
	LCD_lcd_kick();
	
	#elif LCD_u8_MODE==FOUR_BIT_MODE
	DIO_voidSetPinValue(LCD_CTRL,RS_PIN, DIO_PIN_HIGH);
	DIO_voidSetPinValue (LCD_PORT, CLCD_D7, GET_BIT(character,7) );
	DIO_voidSetPinValue (LCD_PORT, CLCD_D6, GET_BIT(character,6) );
	DIO_voidSetPinValue (LCD_PORT, CLCD_D5, GET_BIT(character,5) );
	DIO_voidSetPinValue (LCD_PORT, CLCD_D4, GET_BIT(character,4) );

	LCD_lcd_kick();
	_delay_us(200);
	
	DIO_voidSetPinValue (LCD_PORT, CLCD_D7, GET_BIT(character,3) );
	DIO_voidSetPinValue (LCD_PORT, CLCD_D6, GET_BIT(character,2) );
	DIO_voidSetPinValue (LCD_PORT, CLCD_D5, GET_BIT(character,1) );
	DIO_voidSetPinValue (LCD_PORT, CLCD_D4, GET_BIT(character,0) );
	LCD_lcd_kick();
	_delay_ms(2);
	
	
	#endif
}


void LCD_INIT(void)
{
	DIO_voidSetPortDirection(LCD_PORT, DIO_PORT_OUTPUT);
	DIO_voidSetPortDirection(LCD_CTRL , DIO_PORT_OUTPUT);
	
	LCD_WRITE_COMMAND(LCD_CMD_RETURN_HOME);

	_delay_ms(35);
	
	#ifdef EIGHT_BIT_MODE
	LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_8BIT_2LINES);
	#endif
	
	#ifdef FOUR_BIT_MODE
	//LCD_WRITE_COMMAND(0x02); // As datasheet
	LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_4BIT_2LINES);
	#endif
	
	_delay_ms(1);
	LCD_WRITE_COMMAND(LCD_CMD_DISP_ON_CURSOR_ON);
	_delay_ms(1);
	LCD_CLEAR_SCREEN();
	_delay_ms(2);
	LCD_WRITE_COMMAND(LCD_CMD_ENTRY_MODE);
	//LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW);
}



void LCD_GOTOXY(unsigned char line, unsigned char position)
{
	if (line == 0)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	else if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}

void LCD_WRITE_STRING(u8 *string)
{
	int count = 0; // To count how much char on the line (it should be 16 char only)
	
	while (*string > 0)
	{
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16) // Go to the second line
		{
			LCD_GOTOXY(1,0); // Line 1 position 0
		}
		else if (count == 
		
		
		32 ) // Clear screen and show again
		{
			LCD_CLEAR_SCREEN();
			LCD_GOTOXY(0,0); // Line 0 Position 0
			count = 0;
		}
	}
}






