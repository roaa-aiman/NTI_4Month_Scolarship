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
void LCD_WRITE_COMMAND(unsigned char command);
void LCD_WRITE_CHAR(unsigned char character);
void LCD_WRITE_STRING(u8 *string);
void LCD_check_lcd_isbusy(void);
void LCD_GOTOXY(unsigned char line, unsigned char position);

#endif /* LCD_H_ */



