/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *    Module: AUtosar dio high level code
 *    File Name: Dio_Regs.h
      Description: Header file for ATMEGA32 Microcontroller - Dio Driver Register
 *    SW Version: 1.0.0
 *    Autosar Version : 4.4.0
 *    Author : Roaa Aiman 
 *********************************************************************************************************************/




#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_
#include "Std_Types.h"
/*
 * Module Version 1.0.0
 */
#define DIO_REGS_SW_MAJOR_VERSION           (1U)
#define DIO_REGS_SW_MINOR_VERSION           (0U)
#define DIO_REGS_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define DIO_REGS_AR_RELEASE_MAJOR_VERSION   (4U)
#define DIO_REGS_AR_RELEASE_MINOR_VERSION   (4U)
#define DIO_REGS_AR_RELEASE_PATCH_VERSION   (0U)

/* AUTOSAR checking between Std Types and Dio Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != DIO_REGS_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != DIO_REGS_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != DIO_REGS_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

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


#endif /* DIO_PRIVATE_H_ */