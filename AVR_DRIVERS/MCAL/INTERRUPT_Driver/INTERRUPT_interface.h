/*
 * INTERRUPT_interface.h
 *
 * Created: 3/3/2024 12:34:19 PM
 *  Author: SMART
 */ 


#ifndef INTERRUPT_INTERFACE_H_
#define INTERRUPT_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "INTERRUPT_config.h"
#include "INTERRUPT_private.h"

void EXTI_voidEnable (EXTI_source copy_enumInterruptSource,EXTI_senseControl copy_enumSenseControl);
void EXTI_voidDisable (EXTI_source copy_enumInterruptSource);
void EXTI_voidSetCall_BackINT0(void(*copy_pFunction)(void));
void EXTI_voidSetCall_BackINT1(void(*copy_pFunction)(void));
void EXTI_voidSetCall_BackINT2(void(*copy_pFunction)(void));

#endif /* INTERRUPT_INTERFACE_H_ */