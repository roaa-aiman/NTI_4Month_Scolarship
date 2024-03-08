/*
 * SPI_program.c
 *
 * Created: 3/5/2024 11:39:58 AM
 *  Author: roaa aiman
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_private.h"
static void (*CallBack) (void)= NULL;


void SPI_voidInitMaster(void)
{
	SET_BIT(SPCR_REG, MSTR );
	
	#if SPI_DATA_ORDER == LSB_FIRST
	SET_BIT(SPCR_REG,DORD);
	#elif SPI_DATA_ORDER == MSB_FIRST
	CLR_BIT(SPCR_REG,DORD);
	#endif
	
	#if SPI_CLOCK_POLARITY == IDLE_LOW
	CLR_BIT(SPCR_REG,CPOL);
	#elif SPI_CLOCK_POLARITY == IDLE_HIGH
	SET_BIT(SPCR_REG,CPOL);
	#endif
	
	#if SPI_CLOCK_PHASE == SAMPLE_AT_LEADING
	CLR_BIT(SPCR_REG,CPHA);
	#elif SPI_CLOCK_PHASE == SETUP_AT_LEADING
	SET_BIT(SPCR_REG,CPHA);
	#endif

    #if SPI_FREQUENCY == DIVIDE_BY_2
    SET_BIT(SPSR_REG,SPI2X);
    CLR_BIT(SPCR_REG,SPR1);
    CLR_BIT(SPCR_REG,SPR0);
    #elif SPI_FREQUENCY == DIVIDE_BY_4
    CLR_BIT(SPSR_REG,SPI2X);
    CLR_BIT(SPCR_REG,SPR1);
    CLR_BIT(SPCR_REG,SPR0);
	#elif SPI_FREQUENCY == DIVIDE_BY_16
	CLR_BIT(SPSR_REG,SPI2X );
	CLR_BIT(SPCR_REG,SPR1);
	SET_BIT(SPCR_REG,SPR0);
	#elif SPI_FREQUENCY == DIVIDE_BY_64
	CLR_BIT(SPSR_REG,SPI2X );
	SET_BIT(SPCR_REG,SPR1);
	CLR_BIT(SPCR_REG,SPR0);
    #endif

    //Enable Interrupt
    #if SPI_INTERRUPT_MODE  == ENABLE_INTERRUPT
    SET_BIT(SPCR_REG,SPIE);
    #elif SPI_INTERRUPT_MODE == DISABLE_INTERRUPT
    CLR_BIT(SPCR_REG,SPIE);
    #endif
	//enable SPI
	SET_BIT(SPCR_REG,SPE);	
}
void SPI_voidInitSlave(void)
{
	CLR_BIT(SPCR_REG, MSTR );
	
	#if SPI_DATA_ORDER == LSB_FIRST
	SET_BIT(SPCR_REG,DORD);
	#elif SPI_DATA_ORDER == MSB_FIRST
	CLR_BIT(SPCR_REG,DORD);
	#endif
	
	#if SPI_CLOCK_POLARITY == IDLE_LOW
	CLR_BIT(SPCR_REG,CPOL);
	#elif SPI_CLOCK_POLARITY == IDLE_HIGH
	SET_BIT(SPCR_REG,CPOL);
	#endif
	
	#if SPI_CLOCK_PHASE == SAMPLE_AT_LEADING
	CLR_BIT(SPCR_REG,CPHA);
	#elif SPI_CLOCK_PHASE == SETUP_AT_LEADING
	SET_BIT(SPCR_REG,CPHA);
	#endif
    //Enable Interrupt
    #if SPI_INTERRUPT_MODE  == ENABLE_INTERRUPT
    SET_BIT(SPCR_REG,SPIE);
    #elif SPI_INTERRUPT_MODE == DISABLE_INTERRUPT
    CLR_BIT(SPCR_REG,SPIE);
    #endif
	//enable SPI
	SET_BIT(SPCR_REG,SPE);
}

void SPI_voidSetCallBack( void (*PtrToFunc) (void) )
{
	if(PtrToFunc!=NULL)
	{
		CallBack = PtrToFunc ;
	}
	else
	{
		//error
	}

}

void __vector_12(void) __attribute__((signal , used));
void __vector_12(void)
{
   if(CallBack!=NULL)
   {
	   CallBack();
   }
   else
   {
	   //error
   }

}

void SPI_voidSendDataISR(u8 Copy_Data)
{
	SPDR_REG = Copy_Data ;
}

u8 SPI_u8ReadDataISR(void)
{
	return SPDR_REG ;
}

void SPI_voidTransieve(u8 copy_u8TxData,u8* copy_pu8RxData)
{
 	if( copy_pu8RxData !=NULL)
	{
		SPDR_REG = copy_u8TxData;
		
		//busy wait for SPI flag
		while(0==GET_BIT(SPSR_REG,SPIF));
		
		*copy_pu8RxData= SPDR_REG;
	
	}
	else
	{
		//error
	}
}