/*
 * Timer0_Program.c
 *
 * Created: 3/16/2024 10:31:32 AM
 *  Author: Roaa Aiman
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Timer0_Interface.h"
#include "Timer0_Private.h"
#include "Timer0_Register.h"
#include "Timer0_Config.h"

static void (*GTimer0_voidCallBack1)(void) = NULL;
static void (*GTimer0_voidCallBack2)(void) = NULL;
 //
 static u16 PRV_CTC_Counter;

void TIMER0_voidInitialize(void)
{
	/*Select Timer0 Mode*/

	#if TIMER0_MODE == TIMER0_NORMAL_MODE
	CLR_BIT(TCCR0_REG, TCCR0_WGM00);
	CLR_BIT(TCCR0_REG, TCCR0_WGM01);
	TCNT0_REG = TIMER0_PRELOAD_VALUE;
	#elif TIMER0_MODE == TIMER0_CTC_MODE
	CLR_BIT(TCCR0_REG, TCCR0_WGM00);
	SET_BIT(TCCR0_REG, TCCR0_WGM01);
	OCR0_REG= TIMER0_COMPARE_VALUE;
	#else
	//error
	#endif

	/*Enable Mode of Interrupt*/
	#if TIMER0_INTERRUPT_ENABLE == TIMER0_COMPAR_MATCH_INTERRUPT_ENABLE
	SET_BIT(TIMSK_REG, TIMSK_OCIE0);
	#elif TIMER0_INTERRUPT_ENABLE == TIMER0_OVERFLOW_INTERRUPT_ENABLE
	SET_BIT(TIMSK_REG, TIMSK_TOIE0);
	#else
	//error
	#endif

	
}
void TIMER0_voidStart(void)
{
	/*Select Clock Prescaler*/
	#if TIMER0_SELECT_CLK == TIMER0_NO_CLK
	CLR_BIT(TCCR0_REG, TCCR0_CS00);
	CLR_BIT(TCCR0_REG, TCCR0_CS01);
	CLR_BIT(TCCR0_REG, TCCR0_CS02);

	#elif TIMER0_SELECT_CLK == TIMER0_CLK_NO_PRESCALER
	SET_BIT(TCCR0_REG, TCCR0_CS00);
	CLR_BIT(TCCR0_REG, TCCR0_CS01);
	CLR_BIT(TCCR0_REG, TCCR0_CS02);

	#elif TIMER0_SELECT_CLK == TIMER0_CLK_DIVIDED_BY_8
	CLR_BIT(TCCR0_REG, TCCR0_CS00);
	SET_BIT(TCCR0_REG, TCCR0_CS01);
	CLR_BIT(TCCR0_REG, TCCR0_CS02);

	#elif TIMER0_SELECT_CLK == TIMER0_CLK_DIVIDED_BY_64
	SET_BIT(TCCR0_REG, TCCR0_CS00);
	SET_BIT(TCCR0_REG, TCCR0_CS01);
	CLR_BIT(TCCR0_REG, TCCR0_CS02);


	#elif TIMER0_SELECT_CLK == TIMER0_CLK_DIVIDED_BY_256
	CLR_BIT(TCCR0_REG, TCCR0_CS00);
	CLR_BIT(TCCR0_REG, TCCR0_CS01);
	SET_BIT(TCCR0_REG, TCCR0_CS02);

	#elif TIMER0_SELECT_CLK == TIMER0_CLK_DIVIDED_BY_1024
	SET_BIT(TCCR0_REG, TCCR0_CS00);
	CLR_BIT(TCCR0_REG, TCCR0_CS01);
	SET_BIT(TCCR0_REG, TCCR0_CS02);

	#elif TIMER0_SELECT_CLK == TIMER0_CLK_ON_FALLING_EDGE
	CLR_BIT(TCCR0_REG, TCCR0_CS00);
	SET_BIT(TCCR0_REG, TCCR0_CS01);
	SET_BIT(TCCR0_REG, TCCR0_CS02);
	
	#elif TIMER0_SELECT_CLK == TIMER0_CLK_ON_RISING_EDGE
	SET_BIT(TCCR0_REG, TCCR0_CS00);
	SET_BIT(TCCR0_REG, TCCR0_CS01);
	SET_BIT(TCCR0_REG, TCCR0_CS02);
	#else
	//error
	#endif
}

void TIMER0_voidSetDelay_CTC(u16 Copy_u16Delay_ms)
{
	//under condition tick time 4us
	OCR0_REG= TIMER0_COMPARE_VALUE ; 
	PRV_CTC_Counter = (Copy_u16Delay_ms*1000)/((TIMER0_COMPARE_VALUE+1)*4);//change 4 if the prescaler and  timer freq was changed
	
	
}

void TIMER0_u8SetCallBack(void (*Copy_voidCallBackFunction)(void),u8 Copy_u8InterrputSource)
{
if (Copy_voidCallBackFunction != NULL)
{
	switch(Copy_u8InterrputSource)
	{
		case TIMER0_NORMAL_OVER_FLOW :
		GTimer0_voidCallBack1 = Copy_voidCallBackFunction;
		break;
		
		case TIMER0_CTC_COMPARE_MATCH:
		GTimer0_voidCallBack2 = Copy_voidCallBackFunction;
		break;
	}
	
}
else
{
	//error
}
} 

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static volatile u32 Local_u32CTC_Counter = 0;
	Local_u32CTC_Counter++;
	if ( PRV_CTC_Counter ==	Local_u32CTC_Counter)
	{
		if (GTimer0_voidCallBack2 != NULL)
		{
			GTimer0_voidCallBack2();
		}
		else
		{
			// Error
		}
		Local_u32CTC_Counter = 0;
	}

}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static volatile u32 Local_u32OVF_Counter = 0;
	Local_u32OVF_Counter ++;
	if (TIMER0_DESIRED_OVERFLOW == Local_u32OVF_Counter)
	{
		TCNT0_REG = TIMER0_PRELOAD_VALUE;
		if (GTimer0_voidCallBack1 != NULL)
		{
			GTimer0_voidCallBack1();
		}
		else
		{
			// Error
		}
		Local_u32OVF_Counter = 0;
	}

}