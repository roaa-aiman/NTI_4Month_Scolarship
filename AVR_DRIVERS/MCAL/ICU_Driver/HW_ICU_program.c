/*
 * HW_ICU_program.c
 *
 * Created: 3/19/2024 12:53:20 PM
 *  Author: roaa aiman
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "HW_ICU_interface.h"
#include "HW_ICU_register.h"

static void (*GICU_voidCallBack1)(void) = NULL;

void ICU_voidSetTriggerEdge (ICU_senseControl copy_enumSenseControl)
{
	switch(copy_enumSenseControl)
	{
		case ICU_RISING_EDGE :
		SET_BIT(TCCR1B_REG, TCCR1B_ICES1);
		break;
		case ICU_FALLING_EDGE:
		CLR_BIT(TCCR1B_REG, TCCR1B_ICES1);
		break;
	}
}
void ICU_voidEnable (void)
{
	SET_BIT(TIMSK_REG, TIMSK_TICIE1);	
}
void ICU_voidDisable (void)
{
	CLR_BIT(TIMSK_REG, TIMSK_TICIE1);	
}
u16 ICU_u16ReadInputCapture(void)
{
	return ICR1_REG ;
}


void ICU_u8SetCallBack(void (*Copy_voidCallBackFunction)(void))
{
	if (Copy_voidCallBackFunction != NULL)
	{
		
		GICU_voidCallBack1 = Copy_voidCallBackFunction;
		
	}
	else
	{
		//error
	}
}


void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	
     if (GICU_voidCallBack1 != NULL)
		{
			GICU_voidCallBack1();
		}
		else
		{
			// Error
		}

}