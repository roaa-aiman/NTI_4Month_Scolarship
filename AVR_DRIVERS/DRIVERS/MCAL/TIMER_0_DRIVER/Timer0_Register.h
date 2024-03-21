/*
 * Timer0_Register.h
 *
 * Created: 3/16/2024 10:31:15 AM
 *  Author: SMART
 */ 


#ifndef TIMER0_REGISTER_H_
#define TIMER0_REGISTER_H_

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



#endif /* TIMER0_REGISTER_H_ */