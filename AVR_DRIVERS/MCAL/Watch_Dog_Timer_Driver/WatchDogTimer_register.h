/*
 * WatchDogTimer_register.h
 *
 * Created: 3/19/2024 10:32:06 AM
 *  Author: SMART
 */ 


#ifndef WATCHDOGTIMER_REGISTER_H_
#define WATCHDOGTIMER_REGISTER_H_

#define	 WDTCR_REG			*((volatile u8*) 0x41)
#define	 WDTCR_WDP0		0
#define	 WDTCR_WDP1		1
#define	 WDTCR_WDP2 	2
#define	 WDTCR_WDE		3
#define	 WDTCR_WDTOE	4


#endif /* WATCHDOGTIMER_REGISTER_H_ */