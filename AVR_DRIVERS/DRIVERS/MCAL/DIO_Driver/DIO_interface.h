/*
 * DIO_interface.h
 *
 * Created on: Feb 29, 2024
 *  Author: roaa aiman
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_private.h"
#include "DIO_config.h"
                             /*************** MACROS FOR PORT ***************/
/* macros for port id */
#define DIO_PORTA			    0
#define DIO_PORTB			    1
#define DIO_PORTC			    2
#define DIO_PORTD			    3

/* macros for port direction */
#define DIO_PORT_INPUT          0x00
#define DIO_PORT_OUTPUT			0xff

/* macros for port value */
#define DIO_PORT_LOW            0x00
#define DIO_PORT_HIGH			0xff

                             /*************** MACROS FOR PIN ***************/
/* macros for pin id */
#define DIO_PIN0			    0
#define DIO_PIN1			    1
#define DIO_PIN2			    2
#define DIO_PIN3			    3
#define DIO_PIN4			    4
#define DIO_PIN5			    5
#define DIO_PIN6			    6
#define DIO_PIN7			    7

/* macros for pin direction */
#define DIO_PIN_INPUT           0
#define DIO_PIN_OUTPUT			1

/* macros for pin value */
#define DIO_PIN_LOW             0
#define DIO_PIN_HIGH			1


                             /*************** APIS PROTO TYPES ***************/
void DIO_voidInit (void);

/* Pin Apis */							
void DIO_voidSetPinDirection            (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection);
void DIO_voidSetPinValue                (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue);
void DIO_voidGetPinValue                (u8 copy_u8PortId, u8 copy_u8PinId, u8* copy_pu8PinValue);
void DIO_voidTogglePinValue             (u8 copy_u8PortId, u8 copy_u8PinId);
void DIO_voidActivePinInPullUpResistance(u8 copy_u8PortId, u8 copy_u8PinId);

/* Port Apis */	
void DIO_voidSetPortDirection            (u8 copy_u8PortId, u8 copy_u8PortDirection);
void DIO_voidSetPortValue                (u8 copy_u8PortId, u8 copy_u8PortValue);
void DIO_voidGetPortValue                (u8 copy_u8PortId, u8* copy_pu8PortValue);
void DIO_voidTogglePortValue             (u8 copy_u8PortId);
void DIO_voidActivePortInPullUpResistance(u8 copy_u8PortId);


#endif /* DIO_INTERFACE_H_ */
