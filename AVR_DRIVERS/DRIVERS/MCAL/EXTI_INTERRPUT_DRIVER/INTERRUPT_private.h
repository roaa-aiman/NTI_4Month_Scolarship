/*
 * INTERRUPT_private.h
 *
 * Created: 3/3/2024 12:34:33 PM
 *  Author: SMART
 */ 


#ifndef INTERRUPT_PRIVATE_H_
#define INTERRUPT_PRIVATE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define MCUCR_REG		 *((volatile u8*)0x55) // CONTROL REGISTER
#define MCUCR_ISC10		2//INT1
#define MCUCR_ISC11		3//INT1
#define MCUCR_ISC01		1//INT0
#define MCUCR_ISC00		0//INT0

#define MCUCSR_REG		 *((volatile u8*)0x54)
#define MCUCSR_ISC2		6//INT2

#define GICR_REG	 		*((volatile u8*)0x5B) //general interrupt control (SIE)
#define GICR_INT2      5
#define GICR_INT0      6
#define GICR_INT1      7

#define GIFR_REG		 	*((volatile u8*)0x5A)  //general interrupt flag (PIF)(read only)
#define GIFR_INTF2		5//INT1
#define GIFR_INTF0		6//INT1
#define GIFR_INTF1		7//INT0



#endif /* INTERRUPT_PRIVATE_H_ */