/*
 * lcd.h
 *
 * Created: 3/2/2024 9:22:46 AM
 *  Author: roaa aiman
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
#include "BIT_Math.h"
#include "DIO_interface.h"
#include "STD_TYPES.h"
#include "LCD_config.h"
#include "LCD_private.h"


#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>



void LCD_INIT(void);
void LCD_CLEAR_SCREEN(void);
void LCD_lcd_kick(void);
void LCD_WRITE_COMMAND(u8 command);
void LCD_WRITE_CHAR(u8 character);
void LCD_WRITE_STRING(u8 *string);
void LCD_GOTOXY(u8 line, u8 position);
void LCD_voidWriteNumber( u32 Copy_u8num );

#endif /* LCD_H_ */



