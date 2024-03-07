/*
 * ADC_private.h
 *
 * Created: 3/4/2024 11:30:34 AM
 *  Author: SMART
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADMUX_REG     *((volatile u8 *)0x27)
#define ADMUX_MUX0   0
#define ADMUX_MUX1   1
#define ADMUX_MUX2   2
#define ADMUX_MUX3   3
#define ADMUX_MUX4   4
#define ADMUX_ADLAR  5
#define ADMUX_REFS0  6
#define ADMUX_REFS1  7

#define ADCSRA_REG    *((volatile u8 *)0x26)
#define ADCSRA_ADPS0  0
#define ADCSRA_ADPS1  1
#define ADCSRA_ADPS2  2
#define ADCSRA_ADIE   3
#define ADCSRA_ADIF   4
#define ADCSRA_ADATE  5
#define ADCSRA_ADSC   6
#define ADCSRA_ADEN   7


#define ADCH_REG      *((volatile u8 *)0x25)
#define ADCL_REG      *((volatile u8 *)0x24)

#define ADC_REG       *((volatile u16 *)0x24)

#define SFIOR_REG     *((volatile u8 *)0x50)
#define SFIOR_ADTS0   5
#define SFIOR_ADTS1   6
#define SFIOR_ADTS2   7

#define ADC_CHANNEL_1 0
#define ADC_CHANNEL_2 1
#define ADC_CHANNEL_3 2
#define ADC_CHANNEL_4 3
#define ADC_CHANNEL_5 4
#define ADC_CHANNEL_6 5
#define ADC_CHANNEL_7 6
#define ADC_CHANNEL_8 7



	    
#define VOLTAGE_REFERENCE_AVREF     0
#define VOLTAGE_REFERENCE_AVCC      1
#define VOLTAGE_REFERENCE_INTERNAL  2

#define RIGHT_ADJUSTMENT  0

#define LEFT_ADJUSTMENT   1


/*****/
#define SINGLE_CONVERSION 	0
#define AUTOTRIGGERED 		1
/*****/

#define FREE_RUNNING_MODE   0
/*****/


#define 	DIVID_BY_128  128

#define INTERRUPT_ENABLE 1
#define INTERRUPT_DISABLE 0

#define ADC_ENABLE  1
#define ADC_DISABLE  0

#endif /* ADC_PRIVATE_H_ */