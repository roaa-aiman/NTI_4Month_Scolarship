/*
 * HW_ICU_register.h
 *
 * Created: 3/21/2024 1:40:07 PM
 *  Author: SMART
 */ 


#ifndef HW_ICU_REGISTER_H_
#define HW_ICU_REGISTER_H_

/*Timer/Counter1 Control Register B*/
#define	TCCR1B_REG	*((volatile u8*)0x4E)
#define	TCCR1B_ICES1	6      // input capture edge select 

#define	TIMSK_REG	*((volatile u8*)0x59)
#define	TIMSK_TICIE1	5    //input capture  enable

/*Input Capture Register 1 */
#define ICR1_REG	*((volatile u16*)0x46)


#endif /* HW_ICU_REGISTER_H_ */