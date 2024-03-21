/*
 * HW_ICU_interface.h
 *
 * Created: 3/19/2024 12:52:58 PM
 *  Author: SMART
 */ 


#ifndef HW_ICU_INTERFACE_H_
#define HW_ICU_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "HW_ICU_config.h"

void ICU_voidSetTriggerEdge (ICU_senseControl copy_enumSenseControl);
void ICU_voidEnable (void);
void ICU_voidDisable (void);
u16 ICU_u16ReadInputCapture(void);
void ICU_u8SetCallBack(void (*Copy_voidCallBackFunction)(void));



#endif /* HW_ICU_INTERFACE_H_ */