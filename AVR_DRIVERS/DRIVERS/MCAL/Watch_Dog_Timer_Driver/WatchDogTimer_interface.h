/*
 * WatchDogTimer_interface.h
 *
 * Created: 3/19/2024 10:32:20 AM
 *  Author: SMART
 */ 


#ifndef WATCHDOGTIMER_INTERFACE_H_
#define WATCHDOGTIMER_INTERFACE_H_

#define WDT_TIME_16_3_MS  1
#define WDT_TIME_32_5_MS  2
#define WDT_TIME_65_MS    3
#define WDT_TIME_0_13_MS  4
#define WDT_TIME_0_26_MS  5
#define WDT_TIME_0_52_MS  6
#define WDT_TIME_1_0_MS   7
#define WDT_TIME_2_1_MS   8



void WDT_voidEnable(u8 copy_u8Time);
void WDT_voidDisable(void);




#endif /* WATCHDOGTIMER_INTERFACE_H_ */