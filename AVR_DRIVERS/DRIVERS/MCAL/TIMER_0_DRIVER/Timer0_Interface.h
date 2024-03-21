/*
 * Timer0_Interface.h
 *
 * Created: 3/16/2024 10:31:52 AM
 *  Author: Roaa Aiman 
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#define TIMER0_NORMAL_OVER_FLOW			1
#define TIMER0_CTC_COMPARE_MATCH		2


void TIMER0_voidInitialize(void);
void TIMER0_voidStart(void);
void TIMER0_voidSetDelay_CTC(u16 Copy_u16Delay_ms);
void TIMER0_u8SetCallBack(void (*Copy_voidCallBackFunction)(void),u8 Copy_u8InterrputSource);



#endif /* TIMER0_INTERFACE_H_ */