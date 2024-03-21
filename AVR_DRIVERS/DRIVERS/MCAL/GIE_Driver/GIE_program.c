/*
 * GIF_interface.c
 *
 * Created: 3/3/2024 1:56:53 PM
 *  Author: SMART
 */ 

#include "GIE_interface.h"
void GIE_voidEnable(void)
{
	SET_BIT(SREG_REG,SREG_I);
}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG_REG,SREG_I);
}