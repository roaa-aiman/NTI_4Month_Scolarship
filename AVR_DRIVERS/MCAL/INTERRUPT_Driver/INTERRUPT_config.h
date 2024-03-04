/*
 * INTERRUPT_config.h
 *
 * Created: 3/3/2024 12:35:18 PM
 *  Author: SMART
 */ 


#ifndef INTERRUPT_CONFIG_H_
#define INTERRUPT_CONFIG_H_

typedef enum
{
	
	EXTI_INT0 = 0,
	EXTI_INT1,
	EXTI_INT2
}EXTI_source;

typedef enum
{
	RISING_EDGE =0 ,
	FALLING_EDGE,
	LOW_LEVEL  ,
	LOGIC_CHANGE

}EXTI_senseControl;



#endif /* INTERRUPT_CONFIG_H_ */