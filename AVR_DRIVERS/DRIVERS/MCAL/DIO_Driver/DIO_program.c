/*
 * DIO_program.c
 *
 *  Created on: Feb 29, 2024
 *      Author: Roaa aiman
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"


void DIO_voidInit (void)
{
	DDRA_REG = Conc(DIO_u8_PA7_INTIAL_DIRECTION,DIO_u8_PA6_INTIAL_DIRECTION,DIO_u8_PA5_INTIAL_DIRECTION,DIO_u8_PA4_INTIAL_DIRECTION,
	DIO_u8_PA3_INTIAL_DIRECTION,DIO_u8_PA2_INTIAL_DIRECTION,DIO_u8_PA1_INTIAL_DIRECTION,DIO_u8_PA0_INTIAL_DIRECTION);

	DDRB_REG = Conc(DIO_u8_PB7_INTIAL_DIRECTION,DIO_u8_PB6_INTIAL_DIRECTION,DIO_u8_PB5_INTIAL_DIRECTION,DIO_u8_PB4_INTIAL_DIRECTION,
	DIO_u8_PB3_INTIAL_DIRECTION,DIO_u8_PB2_INTIAL_DIRECTION,DIO_u8_PB1_INTIAL_DIRECTION,DIO_u8_PB0_INTIAL_DIRECTION);

	DDRC_REG = Conc(DIO_u8_PC7_INTIAL_DIRECTION,DIO_u8_PC6_INTIAL_DIRECTION,DIO_u8_PC5_INTIAL_DIRECTION,DIO_u8_PC4_INTIAL_DIRECTION,
	DIO_u8_PC3_INTIAL_DIRECTION,DIO_u8_PC2_INTIAL_DIRECTION,DIO_u8_PC1_INTIAL_DIRECTION,DIO_u8_PC0_INTIAL_DIRECTION);

	DDRD_REG = Conc(DIO_u8_PD7_INTIAL_DIRECTION,DIO_u8_PD6_INTIAL_DIRECTION,DIO_u8_PD5_INTIAL_DIRECTION,DIO_u8_PD4_INTIAL_DIRECTION,
	DIO_u8_PD3_INTIAL_DIRECTION,DIO_u8_PD2_INTIAL_DIRECTION,DIO_u8_PD1_INTIAL_DIRECTION,DIO_u8_PD0_INTIAL_DIRECTION);

	PORTA_REG = Conc(DIO_u8_PA7_INTIAL_VALUE,DIO_u8_PA6_INTIAL_VALUE,DIO_u8_PA5_INTIAL_VALUE,DIO_u8_PA4_INTIAL_VALUE,
	DIO_u8_PA3_INTIAL_VALUE,DIO_u8_PA2_INTIAL_VALUE,DIO_u8_PA1_INTIAL_VALUE,DIO_u8_PA0_INTIAL_VALUE);
	
	PORTB_REG = Conc(DIO_u8_PB7_INTIAL_VALUE,DIO_u8_PB6_INTIAL_VALUE,DIO_u8_PB5_INTIAL_VALUE,DIO_u8_PB4_INTIAL_VALUE,
	DIO_u8_PB3_INTIAL_VALUE,DIO_u8_PB2_INTIAL_VALUE,DIO_u8_PB1_INTIAL_VALUE,DIO_u8_PB0_INTIAL_VALUE);
	
	PORTC_REG = Conc(DIO_u8_PC7_INTIAL_VALUE,DIO_u8_PC6_INTIAL_VALUE,DIO_u8_PC5_INTIAL_VALUE,DIO_u8_PC4_INTIAL_VALUE,
	DIO_u8_PC3_INTIAL_VALUE,DIO_u8_PC2_INTIAL_VALUE,DIO_u8_PC1_INTIAL_VALUE,DIO_u8_PC0_INTIAL_VALUE);
	
	PORTD_REG = Conc(DIO_u8_PD7_INTIAL_VALUE,DIO_u8_PD6_INTIAL_VALUE,DIO_u8_PD5_INTIAL_VALUE,DIO_u8_PD4_INTIAL_VALUE,
	DIO_u8_PD3_INTIAL_VALUE,DIO_u8_PD2_INTIAL_VALUE,DIO_u8_PD1_INTIAL_VALUE,DIO_u8_PD0_INTIAL_VALUE);
}

void DIO_voidSetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
				if(copy_u8PortDirection == DIO_PORT_OUTPUT)
				{
					DDRA_REG =0xFF;
				}
				else if(copy_u8PortDirection == DIO_PORT_INPUT)
				{
					DDRA_REG =0x00; //or 0 or 0b00000000
				}
				else
				{
					//Invalid direction
				}
				break;
		case DIO_PORTB:
				if(copy_u8PortDirection == DIO_PORT_OUTPUT)
				{
					DDRB_REG =0xFF;
				}
				else if(copy_u8PortDirection == DIO_PORT_INPUT)
				{
					DDRB_REG =0x00; //or 0 or 0b00000000
				}
				else
				{
					//Invalid direction
				}
				break;
		case DIO_PORTC:
				if(copy_u8PortDirection == DIO_PORT_OUTPUT)
				{
					DDRC_REG =0xFF;
				}
				else if(copy_u8PortDirection == DIO_PORT_INPUT)
				{
					DDRC_REG =0x00; //or 0 or 0b00000000
				}
				else
				{
					//Invalid direction
				}
				break;
		case DIO_PORTD:
				if(copy_u8PortDirection == DIO_PORT_OUTPUT)
				{
					DDRD_REG =0xFF;
				}
				else if(copy_u8PortDirection == DIO_PORT_INPUT)
				{
					DDRD_REG =0x00; //or 0 or 0b00000000
				}
				else
				{
					//Invalid direction
				}
				break;
		default: /*invalid port id */ break;
	}
}

void DIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
				if(copy_u8PortValue == DIO_PORT_HIGH)
				{
					PORTA_REG = 0xFF;
				}
				else if(copy_u8PortValue == DIO_PORT_LOW)
				{
					PORTA_REG = 0x00; //or 0 or 0b00000000
				}
				else
				{
					PORTA_REG = copy_u8PortValue;
				}
				break;
		case DIO_PORTB:
				if(copy_u8PortValue == DIO_PORT_HIGH)
				{
					PORTB_REG = 0xFF;
				}
				else if(copy_u8PortValue == DIO_PORT_LOW)
				{
					PORTB_REG = 0x00; //or 0 or 0b00000000
				}
				else
				{
					PORTB_REG = copy_u8PortValue;
				}
				break;
		case DIO_PORTC:
				if(copy_u8PortValue == DIO_PORT_HIGH)
				{
					PORTC_REG =0xFF;
				}
				else if(copy_u8PortValue == DIO_PORT_LOW)
				{
					PORTC_REG =0x00; //or 0 or 0b00000000
				}
				else
				{
					PORTC_REG = copy_u8PortValue;
				}
				break;
		case DIO_PORTD:
				if(copy_u8PortValue == DIO_PORT_HIGH)
				{
					PORTD_REG =0xFF;
				}
				else if(copy_u8PortValue == DIO_PORT_LOW)
				{
					PORTD_REG =0x00; //or 0 or 0b00000000
				}
				else
				{
					PORTD_REG = copy_u8PortValue;
				}
				break;
		default: /*invalid port id */ break;
	}
}

void DIO_voidSetPinDirection (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection)
{
	switch (copy_u8PortId)
	{
		case DIO_PORTA:
			if(copy_u8PinId<=7)
			{
			  if(copy_u8PinDirection == DIO_PIN_OUTPUT)
				{
					SET_BIT(DDRA_REG, copy_u8PinId);
				}
				else if(copy_u8PinDirection == DIO_PIN_INPUT)
				{
					CLR_BIT(DDRA_REG, copy_u8PinId);
				}
				else
				{
					//Invalid direction
				}
			}
			else
			  {
			    //Invalid pin value
			  }
				break;
		case DIO_PORTB:

		 if(copy_u8PinId<=7)
		 {
			if(copy_u8PinDirection == DIO_PIN_OUTPUT)
				{
					SET_BIT(DDRB_REG, copy_u8PinId);
				}
				else if(copy_u8PinDirection == DIO_PIN_INPUT)
				{
					CLR_BIT(DDRB_REG, copy_u8PinId);
				}
				else
				{
					//Invalid direction
				}
		 }
		 else
		   {
		 	//Invalid pin value
		   }
				break;
		case DIO_PORTC:

		if(copy_u8PinId<=7)
		 {
			if(copy_u8PinDirection == DIO_PIN_OUTPUT)
				{
					SET_BIT(DDRC_REG, copy_u8PinId);
				}
				else if(copy_u8PinDirection == DIO_PIN_INPUT)
				{
					CLR_BIT(DDRC_REG, copy_u8PinId);
				}
				else
				{
					//Invalid direction
				}
		 }
		 else
			{
			 //Invalid pin value
		    }
				break;
		case DIO_PORTD:
		 if(copy_u8PinId<=7)
		 {
			if(copy_u8PinDirection == DIO_PIN_OUTPUT)
				{
					SET_BIT(DDRD_REG, copy_u8PinId);
				}
				else if(copy_u8PinDirection == DIO_PIN_INPUT)
				{
					CLR_BIT(DDRD_REG, copy_u8PinId);
				}
				else
				{
					//Invalid direction
				}
		 }
		 else
		   {
		 	 //Invalid pin value
		   }
				break;
		default: /*Invalid port id*/ break;
	}
}


void DIO_voidSetPinValue (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue)
{
	switch (copy_u8PortId)
	{
		case DIO_PORTA:
			if(copy_u8PinId<=7)
			{
				if(copy_u8PinValue == DIO_PIN_HIGH)
				{
					SET_BIT(PORTA_REG, copy_u8PinId);
				}
				else if(copy_u8PinValue == DIO_PIN_LOW)
				{
					CLR_BIT(PORTA_REG, copy_u8PinId);
				}
				else
				{
					//error
				}
			}
			else
			  {
			   //Invalid pin value
			  }
				break;
		case DIO_PORTB:
			if(copy_u8PinId<=7)
			{
				if(copy_u8PinValue == DIO_PIN_HIGH)
				{
					SET_BIT(PORTB_REG, copy_u8PinId);
				}
				else if(copy_u8PinValue == DIO_PIN_LOW)
				{
					CLR_BIT(PORTB_REG, copy_u8PinId);
				}
				else
				{
					//error
				}
			}
			else
			  {
			    //Invalid pin value
			  }
				break;
		case DIO_PORTC:
			if(copy_u8PinId<=7)
			{
				if(copy_u8PinValue == DIO_PIN_HIGH)
				{
					SET_BIT(PORTC_REG, copy_u8PinId);
				}
				else if(copy_u8PinValue == DIO_PIN_LOW)
				{
					CLR_BIT(PORTC_REG, copy_u8PinId);
				}
				else
				{
					//error
				}
			}
			else
			  {
				 //Invalid pin value
			  }
				break;
		case DIO_PORTD:
			if(copy_u8PinId<=7)
			 {
				if(copy_u8PinValue == DIO_PIN_HIGH)
				{
					SET_BIT(PORTD_REG, copy_u8PinId);
				}
				else if(copy_u8PinValue == DIO_PIN_LOW)
				{
					CLR_BIT(PORTD_REG, copy_u8PinId);
				}
				else
				{
					//error
				}
			 }
			else
			 {
				//Invalid pin value
			 }
				break;
		default: /*Invalid port id*/ break;
	}
}


void DIO_voidTogglePinValue (u8 copy_u8PortId, u8 copy_u8PinId)
{
  if(copy_u8PinId<=7)
	{
	switch (copy_u8PortId)
	{

		case DIO_PORTA:
				TOG_BIT(PORTA_REG, copy_u8PinId);
				break;
		case DIO_PORTB:
				TOG_BIT(PORTB_REG, copy_u8PinId);
				break;
		case DIO_PORTC:
				TOG_BIT(PORTC_REG, copy_u8PinId);
				break;
		case DIO_PORTD:
				TOG_BIT(PORTD_REG, copy_u8PinId);
				break;
		default: /*Invalid port id*/ break;
	}
	}
   else
  	 {
  		//Invalid pin value
  	 }
}

void DIO_voidTogglePortValue(u8 copy_u8PortId)
{

	switch (copy_u8PortId)
		{
			case DIO_PORTA:
					PORTA_REG ^=0xFF;
					break;
			case DIO_PORTB:
				    PORTB_REG ^=0xFF;
					break;
			case DIO_PORTC:
				    PORTC_REG ^=0xFF;
					break;
			case DIO_PORTD:
				    PORTD_REG ^=0xFF;
					break;
			default: /*Invalid port id*/ break;
		}
}

void DIO_voidGetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8* copy_pu8PinValue)
{
	switch (copy_u8PortId)
	{
		case DIO_PORTA:
		    	*copy_pu8PinValue = GET_BIT(PINA_REG, copy_u8PinId);
				break;
		case DIO_PORTB:
			    *copy_pu8PinValue = GET_BIT(PINB_REG, copy_u8PinId);
				break;
		case DIO_PORTC:
			    *copy_pu8PinValue = GET_BIT(PINC_REG, copy_u8PinId);
				break;
		case DIO_PORTD:
			    *copy_pu8PinValue = GET_BIT(PIND_REG, copy_u8PinId);
				break;
		default: /*Invalid port id*/ break;
	}
}

void DIO_voidGetPortValue(u8 copy_u8PortId, u8* copy_pu8PortValue)
{
	switch (copy_u8PortId)
		{
			case DIO_PORTA:
				*copy_pu8PortValue =PORTA_REG;
					break;
			case DIO_PORTB:
				*copy_pu8PortValue =PORTB_REG;
					break;
			case DIO_PORTC:
				*copy_pu8PortValue = PORTC_REG;
					break;
			case DIO_PORTD:
				*copy_pu8PortValue = PORTD_REG;
					break;
			default: /*Invalid port id*/ break;
		}
}

void DIO_voidActivePinInPullUpResistance(u8 copy_u8PortId, u8 copy_u8PinId)
{

	CLR_BIT(MCUCR_REG, DIO_PIN4);
	switch (copy_u8PortId)
		{
			case DIO_PORTA:
					SET_BIT(PORTA_REG, copy_u8PinId);
					CLR_BIT(DDRA_REG, copy_u8PinId);
					break;
			case DIO_PORTB:
				    SET_BIT(PORTB_REG, copy_u8PinId);
				    CLR_BIT(DDRB_REG, copy_u8PinId);
					break;
			case DIO_PORTC:
				    SET_BIT(PORTC_REG, copy_u8PinId);
				    CLR_BIT(DDRC_REG, copy_u8PinId);
					break;
			case DIO_PORTD:
				    SET_BIT(PORTD_REG, copy_u8PinId);
				    CLR_BIT(DDRD_REG, copy_u8PinId);
					break;
			default: /*Invalid port id*/ break;
		}

}

void DIO_voidActivePortInPullUpResistance(u8 copy_u8PortId)
{
	CLR_BIT(MCUCR_REG, DIO_PIN4);
	switch (copy_u8PortId)
			{
				case DIO_PORTA:
						PORTA_REG =0xFF;
						DDRA_REG =0x00;
						break;
				case DIO_PORTB:
					    PORTB_REG =0xFF;
					    DDRB_REG =0x00;
						break;
				case DIO_PORTC:
					    PORTC_REG =0xFF;
					    DDRC_REG =0x00;
						break;
				case DIO_PORTD:
					    PORTD_REG =0xFF;
					    DDRD_REG =0x00;
						break;
				default: /*Invalid port id*/ break;
			}

}
