/*
 * PWM_Register.h
 *
 * Created: 3/17/2024 10:45:11 AM
 *  Author: SMART
 */ 


#ifndef PWM_REGISTER_H_
#define PWM_REGISTER_H_

/*Special Function IO Register*/
#define	SFIOR_REG			*((volatile u8*) 0x50)
#define	SFIOR_PSR10		0

/*Timer/Counter Control Register*/
#define	TCCR0_REG			*((volatile u8*) 0x53)
#define	TCCR0_CS00		0
#define	TCCR0_CS01		1
#define	TCCR0_CS02		2
#define	TCCR0_WGM01		3
#define	TCCR0_COM00		4
#define	TCCR0_COM01		5
#define	TCCR0_WGM00		6
#define	TCCR0_FOC0		7

/*Timer/Counter Register*/
#define	TCNT0_REG		*((volatile u8*) 0x52)

/*Output Compare Register*/
#define	OCR0_REG		*((volatile u8*) 0x5C)

/*Timer/Counter Interrupt Mask Register*/
#define	TIMSK_REG		*((volatile u8*) 0x59)
#define	TIMSK_OCIE0		1
#define	TIMSK_TOIE0		0


/*Timer/Counter Interrupt Flag Register*/
#define	TIFR_REG		*((volatile u8*) 0x58)
#define	TIFR_OCF0		1	/* Timer/Counter0 Output Compare Match Interrupt Enable*/
#define	TIFR_TOV0		0	/*Timer/Counter0 Overflow Interrupt Enable*/


//TIMER 1 REGISTER

/*Timer/Counter1 Control Register A*/
#define	TCCR1A_REG	*((volatile u8*)0x4F)
#define	TCCR1A_COM1A1	7
#define	TCCR1A_COM1A0	6
#define	TCCR1A_COM1B1	5
#define	TCCR1A_COM1B0	4
#define	TCCR1A_FOC1A	3
#define	TCCR1A_FOC1B	2
#define	TCCR1A_WGM11	1
#define	TCCR1A_WGM10	0

/*Timer/Counter1 Control Register B*/
#define	TCCR1B_REG	*((volatile u8*)0x4E)
#define	TCCR1B_ICNC1	7
#define	TCCR1B_ICES1	6
/*Bit 5 is reversed */
#define	TCCR1B_WGM13	4
#define	TCCR1B_WGM12	3
#define	TCCR1B_CS12		2
#define	TCCR1B_CS11		1
#define	TCCR1B_CS10		0

#define	TCNT1H_REG	*((volatile u8*)0x4D)
#define	TCNT1L_REG	*((volatile u8*)0x4C)

/*Output Compare Register 1 A*/

#define	OCR1AL_REG	*((volatile u16*)0x4A)

/*Output Compare Register 1 B*/
#define	OCR1BH_REG	*((volatile u8*)0x49)
#define	OCR1BL_REG	*((volatile u8*)0x48)

/*Input Capture Register 1 */
#define ICR1L_REG	*((volatile u16*)0x46)

/*Timer/Counter Interrupt Mask Register*/
#define	TIMSK_REG	*((volatile u8*)0x59)
#define	TIMSK_TICIE1	5
#define	TIMSK_OCIE1A	4
#define	TIMSK_OCIE1B	3
#define	TIMSK_TOIE1		2

/*Timer/Counter Interrupt Flag Register */
#define	TIFR_REG	*((volatile u8*)0x58)
#define	TIFR_ICF1		5
#define	TIFR_OCF1A		4
#define	TIFR_OCF1B		3
#define	TIFR_TOV1		2




#endif /* PWM_REGISTER_H_ */