/*
 * INTERRUPT_program.c
 *
 * Created: 3/3/2024 12:35:37 PM
 *  Author: roaa aiman
 */ 

#include "INTERRUPT_interface.h"

static void(*PRV0_pFunction)(void)=NULL;
static void(*PRV1_pFunction)(void)=NULL;
static void(*PRV2_pFunction)(void)=NULL;

void EXTI_voidEnable (EXTI_source copy_enumInterruptSource,EXTI_senseControl copy_enumSenseControl)
{
	   switch(copy_enumInterruptSource)
	   {
		   case EXTI_INT0 :
			   switch(copy_enumSenseControl)
			   {
				   case RISING_EDGE :
				   SET_BIT(MCUCR_REG,MCUCR_ISC00);
				   SET_BIT(MCUCR_REG,MCUCR_ISC01);
				   break;
				   case FALLING_EDGE:
				   CLR_BIT(MCUCR_REG,MCUCR_ISC00);
				   SET_BIT(MCUCR_REG,MCUCR_ISC01);
				   break;
				   
				   case LOW_LEVEL:
				   CLR_BIT(MCUCR_REG,MCUCR_ISC00);
				   CLR_BIT(MCUCR_REG,MCUCR_ISC01);
				   break;
				   
				   case LOGIC_CHANGE :
				   SET_BIT(MCUCR_REG,MCUCR_ISC00);
				   CLR_BIT(MCUCR_REG,MCUCR_ISC01);
				   break;
			   }
		   SET_BIT(GICR_REG,GICR_INT0);   
		   break;
		   
		   case EXTI_INT1 :
		    switch(copy_enumSenseControl)
		    {
			    case RISING_EDGE :
			    SET_BIT(MCUCR_REG,MCUCR_ISC10);
			    SET_BIT(MCUCR_REG,MCUCR_ISC11);
			    break;
			    case FALLING_EDGE:
			    CLR_BIT(MCUCR_REG,MCUCR_ISC10);
			    SET_BIT(MCUCR_REG,MCUCR_ISC11);
			    break;
			    
			    case LOW_LEVEL:
			    CLR_BIT(MCUCR_REG,MCUCR_ISC10);
			    CLR_BIT(MCUCR_REG,MCUCR_ISC11);
			    break;
			    
			    case LOGIC_CHANGE :
			    SET_BIT(MCUCR_REG,MCUCR_ISC10);
			    CLR_BIT(MCUCR_REG,MCUCR_ISC11);
			    break;
		    }
		    SET_BIT(GICR_REG,GICR_INT1);
		    break;
		    
			
		   case EXTI_INT2 :
		   switch(copy_enumSenseControl)
		   {
			   case RISING_EDGE :
			   SET_BIT(MCUCSR_REG,MCUCSR_ISC2);
			   break;
			   case FALLING_EDGE:
			   CLR_BIT(MCUCSR_REG,MCUCSR_ISC2);
			   break;
			   
		   }
		   SET_BIT(GICR_REG,GICR_INT2);
		   break;
		     
	   }		   
}
void EXTI_voidDisable (EXTI_source copy_enumInterruptSource)
{
	switch(copy_enumInterruptSource)
	{
		case EXTI_INT0 :
		CLR_BIT(GICR_REG,GICR_INT0);
		break;
		
		case EXTI_INT1 :
		CLR_BIT(GICR_REG,GICR_INT1);
		break;
		
		case EXTI_INT2 :
		CLR_BIT(GICR_REG,GICR_INT2);
		break;
		
	}
	
	
	
}
void EXTI_voidSetCall_BackINT0(void(*copy_pFunction)(void))
{
	if (copy_pFunction!=NULL)
	{
		PRV0_pFunction=copy_pFunction;
	}
	else
	{
		//return error
	}
	
}
void EXTI_voidSetCall_BackINT1(void(*copy_pFunction)(void))
{
	if (copy_pFunction!=NULL)
	{
		PRV1_pFunction=copy_pFunction;
	}
	else
	{
		//return error
	}
	
}

void EXTI_voidSetCall_BackINT2(void(*copy_pFunction)(void))
{
	if (copy_pFunction!=NULL)
	{
		PRV2_pFunction=copy_pFunction;
	}
	else
	{
		//return error
	}
	
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(PRV0_pFunction!=NULL)
	{
		PRV0_pFunction();
	}
	
}
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(PRV1_pFunction!=NULL)
	{
		PRV1_pFunction();
	}
	
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(PRV2_pFunction!=NULL)
	{
		PRV2_pFunction();
	}
	
}