/*
 * Timer1_Interface.h
 *
 * Created: 3/20/2024 4:53:44 PM
 *  Author: SMART
 */ 


#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

void TIMER1_voidInitialization(void);


void TIMER1_voidSetDutyCycle(u16 Copy_u16DutyCycleValue);
void TIMER1_voidSetICR(u16 Copy_u8MaxAngle);

//for ICU
void TIMER1_voidSetTimerValue(u16 Copy_u16TimerValue);
u16  TIMER1_voidGetTimerValue(void);

#endif /* TIMER1_INTERFACE_H_ */