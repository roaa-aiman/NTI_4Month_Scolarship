/*
 * PWM_Interface.h
 *
 * Created: 3/17/2024 10:45:46 AM
 *  Author: SMART
 */ 


#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

void PWM_voidInitializeChannel_0(void);
void PWM_voidStopChannel_0(void);
void PWM_voidGenerateChannel_0 (u8 copy_u8DutyCycle);


void PWM_voidInitializeChannel_1A(void);
void PWM_voidStopChannel_1A(void);
void PWM_voidGenerateChannel_1A (u32 copy_u32Frequency_HZ,f32 copy_f32DutyCycle);



#endif /* PWM_INTERFACE_H_ */