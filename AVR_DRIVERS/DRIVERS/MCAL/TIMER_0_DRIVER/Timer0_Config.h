/*   
 * Timer0_Config.h
 *
 * Created: 3/16/2024 10:30:59 AM
 *  Author: SMART
 */ 
#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

/*
 * Options:
 			1-TIMER0_NORMAL_MODE	
 			2-TIMER0_CTC_MODE		
 */
#define TIMER0_MODE		TIMER0_CTC_MODE
/*
 * Options:
			1- TIMER0_NO_CLK					2- TIMER0_CLK_NO_PRESCALER
			3- TIMER0_CLK_DIVIDED_BY_8			4- TIMER0_CLK_DIVIDED_BY_64
			5- TIMER0_CLK_DIVIDED_BY_256		6- TIMER0_CLK_DIVIDED_BY_1024
			7- TIMER0_CLK_ON_FALLING_EDGE		8- TIMER0_CLK_ON_RISING_EDGE
 */
#define TIMER0_SELECT_CLK	TIMER0_CLK_DIVIDED_BY_64

/*Hand analysis to set start point*/
#define TIMER0_PRELOAD_VALUE 	224

#define TIMER0_COMPARE_VALUE  249

/*
 * Options:
 			1-COMPAR_MATCH_INTERRUPT_ENABLE
 			2-OVERFLOW_INTERRUPT_ENABLE
 */
#define TIMER0_INTERRUPT_ENABLE		TIMER0_COMPAR_MATCH_INTERRUPT_ENABLE


#define TIMER0_DESIRED_OVERFLOW		1954
#define TIMER0_OUTPUT_COMPARE_VALUE 1500




#endif /* TIMER0_CONFIG_H_ */