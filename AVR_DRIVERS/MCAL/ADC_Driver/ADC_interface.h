/*
 * ADC_interface.h
 *
 * Created: 3/4/2024 11:29:54 AM
 *  Author: SMART
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_private.h"
#include "ADC_config.h"

void ADC_voidInit(u8 copy_u8ReferrenceVoltage);
void ADC_voidGetDigitalValue(u8 copy_u8ChannelNumber,u16* copy_pu16DigitalValue);



#endif /* ADC_INTERFACE_H_ */