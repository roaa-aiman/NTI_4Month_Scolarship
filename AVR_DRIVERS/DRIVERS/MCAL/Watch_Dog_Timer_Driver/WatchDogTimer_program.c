/*
 * WatchDogTimer_program.c
 *
 * Created: 3/19/2024 10:31:50 AM
 *  Author: ROaa aiman
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include  "WatchDogTimer_register.h"
#include "WatchDogTimer_interface.h"
void WDT_voidEnable(u8 copy_u8Time)
{
	switch(copy_u8Time)
	{
		case  WDT_TIME_16_3_MS:
		CLR_BIT(WDTCR_REG,WDTCR_WDP0);
		CLR_BIT(WDTCR_REG,WDTCR_WDP1);
		CLR_BIT(WDTCR_REG,WDTCR_WDP2);
		break;
		case WDT_TIME_32_5_MS :
		SET_BIT(WDTCR_REG,WDTCR_WDP0);
		CLR_BIT(WDTCR_REG,WDTCR_WDP1);
		CLR_BIT(WDTCR_REG,WDTCR_WDP2);
		break;
		case WDT_TIME_65_MS :
		CLR_BIT(WDTCR_REG,WDTCR_WDP0);
		SET_BIT(WDTCR_REG,WDTCR_WDP1);
		CLR_BIT(WDTCR_REG,WDTCR_WDP2);
		break;
		case WDT_TIME_0_13_MS :
		SET_BIT(WDTCR_REG,WDTCR_WDP0);
		SET_BIT(WDTCR_REG,WDTCR_WDP1);
		CLR_BIT(WDTCR_REG,WDTCR_WDP2);
		break;
		case WDT_TIME_0_26_MS:
		CLR_BIT(WDTCR_REG,WDTCR_WDP0);
		CLR_BIT(WDTCR_REG,WDTCR_WDP1);
		SET_BIT(WDTCR_REG,WDTCR_WDP2);
		break;
		case WDT_TIME_0_52_MS :
		SET_BIT(WDTCR_REG,WDTCR_WDP0);
		CLR_BIT(WDTCR_REG,WDTCR_WDP1);
		SET_BIT(WDTCR_REG,WDTCR_WDP2);
		break;
		case WDT_TIME_1_0_MS :
		CLR_BIT(WDTCR_REG,WDTCR_WDP0);
		SET_BIT(WDTCR_REG,WDTCR_WDP1);
		SET_BIT(WDTCR_REG,WDTCR_WDP2);
		break;
		case WDT_TIME_2_1_MS :
		SET_BIT(WDTCR_REG,WDTCR_WDP0);
		SET_BIT(WDTCR_REG,WDTCR_WDP1);
		SET_BIT(WDTCR_REG,WDTCR_WDP2);
		break;
		
	}
	
	//enable watch dog
	SET_BIT(WDTCR_REG,WDTCR_WDE);

}

void WDT_voidDisable(void)
{
	WDTCR_REG = 1<<WDTCR_WDTOE | 1<< WDTCR_WDE;
	WDTCR_REG = 0 ;
	
}					