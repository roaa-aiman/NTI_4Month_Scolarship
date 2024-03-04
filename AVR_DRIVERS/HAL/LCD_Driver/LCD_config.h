/*
 * LCD_config.h
 *
 * Created: 3/2/2024 9:36:03 PM
 *  Author: ROAA AIMAN
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_PORT			DIO_PORTB


#define CLCD_D4				DIO_PIN0
#define CLCD_D5				DIO_PIN1
#define CLCD_D6				DIO_PIN2
#define CLCD_D7				DIO_PIN4


#define LCD_CTRL			DIO_PORTA


//#define	RW_PIN			2

#define RS_PIN				DIO_PIN3
#define EN_SWITCH			DIO_PIN2


/* options 
 1-EIGHT_BIT_MODE
 2-FOUR_BIT_MODE
*/
#define  LCD_u8_MODE              FOUR_BIT_MODE



#endif /* LCD_CONFIG_H_ */