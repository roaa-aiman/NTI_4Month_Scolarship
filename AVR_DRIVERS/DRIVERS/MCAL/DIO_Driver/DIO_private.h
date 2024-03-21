/*
 * DIO_private.h
 *
 *  Created on: Feb 29, 2024
 *      Author: roaa aiman
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define PORTA_REG    *((volatile u8*)0x3B)
#define DDRA_REG     *((volatile u8*)0x3A)
#define PINA_REG     *((volatile u8*)0x39)

#define PORTB_REG    *((volatile u8*)0x38)
#define DDRB_REG     *((volatile u8*)0x37)
#define PINB_REG     *((volatile u8*)0x36)

#define PORTC_REG    *((volatile u8*)0x35)
#define DDRC_REG     *((volatile u8*)0x34)
#define PINC_REG     *((volatile u8*)0x33)

#define PORTD_REG    *((volatile u8*)0x32)
#define DDRD_REG     *((volatile u8*)0x31)
#define PIND_REG     *((volatile u8*)0x30)

#define MCUCR_REG		 *((volatile u8*)0x55) // CONTROL REGISTER

/* Macros for Pins Direction */
#define DIO_u8_INTIAL_OUTPUT                         1
#define DIO_u8_INTIAL_INPUT                          0

/* Macros for Pins Values */
#define DIO_u8_OUTPUT_LOW                            0
#define DIO_u8_OUTPUT_HIGH                           1
#define DIO_u8_INPUT_FLOATING                        0
#define DIO_u8_INPUT_PULLUP                          1

#define Conc(b7,b6,b5,b4,b3,b2,b1,b0)           Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)      0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif /* DIO_PRIVATE_H_ */
