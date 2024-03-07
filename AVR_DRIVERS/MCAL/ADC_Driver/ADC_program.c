/*
 * ADC_program.c
 *
 * Created: 3/4/2024 11:31:18 AM
 *  Author: Roaa aiman 
 */
#include "ADC_interface.h" 
void ADC_voidInit(u8 copy_u8ReferrenceVoltage)
{
        switch(copy_u8ReferrenceVoltage)
		{
			case VOLTAGE_REFERENCE_AVREF:
			  CLR_BIT(ADMUX_REG ,ADMUX_REFS1);
			  CLR_BIT(ADMUX_REG ,ADMUX_REFS0);
			  break;
			case VOLTAGE_REFERENCE_INTERNAL:
			 SET_BIT(ADMUX_REG ,ADMUX_REFS1);
			 SET_BIT(ADMUX_REG ,ADMUX_REFS0);
			 break;
			case VOLTAGE_REFERENCE_AVCC:
			 CLR_BIT(ADMUX_REG ,ADMUX_REFS1);
			 SET_BIT(ADMUX_REG ,ADMUX_REFS0);
			 break;
			
		}
		//RIGHT_ADJUSTMENT
		CLR_BIT(ADMUX_REG,ADMUX_ADLAR);
        //prescaler 128
		SET_BIT(ADCSRA_REG,ADCSRA_ADPS2);
		SET_BIT(ADCSRA_REG,ADCSRA_ADPS1);
		SET_BIT(ADCSRA_REG,ADCSRA_ADPS0);
		//disable autotrrigred
		CLR_BIT(ADCSRA_REG,ADCSRA_ADATE);
		//disable interrupt
		CLR_BIT(ADCSRA_REG,ADCSRA_ADIE);		
}

void ADC_voidGetDigitalValue(u8 copy_u8ChannelNumber,u16* copy_pu16DigitalValue)
{
	if((copy_pu16DigitalValue!=NULL)&&(*copy_pu16DigitalValue<32))
	{
		//clear channel bit 
		ADMUX_REG &=   0xE0;     //0b11100000;
		//SELECT CHANNEL 
		ADMUX_REG |= copy_u8ChannelNumber;
		
		//start conversion
		SET_BIT(ADCSRA_REG,ADCSRA_ADSC);

		while(!GET_BIT(ADCSRA_REG,ADCSRA_ADIF))
		{
			//POLLING : BUSY WAITING UNTIL EVENT
			//fix me: need time out
		}

		//CLEAR THE FLAG
		SET_BIT(ADCSRA_REG,ADCSRA_ADIF);
		
		*copy_pu16DigitalValue = ADC_REG;
		
	}
	else
	{
		//error state
	}
}