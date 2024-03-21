/*
 * Timer0_Private.h
 *
 * Created: 3/16/2024 10:30:41 AM
 *  Author: Roaa
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

/*Options for Clock Select*/
#define TIMER0_NO_CLK					0
#define TIMER0_CLK_NO_PRESCALER			1
#define TIMER0_CLK_DIVIDED_BY_8			2
#define TIMER0_CLK_DIVIDED_BY_64		3
#define TIMER0_CLK_DIVIDED_BY_256		4
#define TIMER0_CLK_DIVIDED_BY_1024		5
#define TIMER0_CLK_ON_FALLING_EDGE		6
#define TIMER0_CLK_ON_RISING_EDGE		7

/*Options for Waveform Generation*/
#define TIMER0_NORMAL_MODE		1
#define TIMER0_CTC_MODE			2

#define  TIMER0_COMPAR_MATCH_INTERRUPT_ENABLE	1
#define  TIMER0_OVERFLOW_INTERRUPT_ENABLE		2






#endif /* TIMER0_PRIVATE_H_ */