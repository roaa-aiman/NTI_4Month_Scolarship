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
	//_delay_ms(2);
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

	DIO_voidSetPinDirection (LCD_CTRL , RS_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection (LCD_CTRL,EN_SWITCH,DIO_PIN_OUTPUT);
	
	DIO_voidSetPinDirection (LCD_PORT , CLCD_D4,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection (LCD_PORT , CLCD_D5,DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection (LCD_PORT , CLCD_D6,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection (LCD_PORT , CLCD_D7,DIO_PIN_OUTPUT);
	
	LCD_WRITE_COMMAND(LCD_CMD_RETURN_HOME);

	_delay_ms(35);
	#if LCD_u8_MODE == EIGHT_BIT_MODE
	LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_8BIT_2LINES);
	#elif LCD_u8_MODE == FOUR_BIT_MODE
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



void LCD_GOTOXY(u8 line, u8 position)
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

void LCD_voidSendString(u8 *str)
{
	// Send each character in the string to the LCD
	while (*str)
	{
		LCD_WRITE_CHAR(*str++);
	}
}

void LCD_voidWriteNumber( u32 Copy_u8num )
{
	
	u8 str[10]={0},i=0 ,j;
	if(Copy_u8num==0)
	{
		LCD_WRITE_CHAR('0');
		return;
	}
	if(Copy_u8num<0)
	{
		Copy_u8num=Copy_u8num*(-1);
		LCD_WRITE_CHAR('-');
	}
	
	while(Copy_u8num!=0)
	{
		str[i]=Copy_u8num%10 +'0';
		Copy_u8num=Copy_u8num/10;
		i++;
		
	}
	
	for (j=i;j>0;j--)
	{
		LCD_WRITE_CHAR(str[j-1]);
	}
}




