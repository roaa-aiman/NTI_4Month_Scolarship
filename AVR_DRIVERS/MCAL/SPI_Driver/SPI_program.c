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
void SPI_voidInitMaster(void)
{
	CLR_BIT(SPCR_REG,SPIE);
	
	SET_BIT(SPCR_REG,DORD);
	
	SET_BIT(SPCR_REG, MSTR );
	
    SET_BIT(SPCR_REG,CPOL);
    SET_BIT(SPCR_REG,CPHA);
	
	CLR_BIT(SPCR_REG,SPR0);
	SET_BIT(SPCR_REG,SPR1);
	CLR_BIT(SPSR_REG,SPI2X );
	
	SET_BIT(SPCR_REG,SPE);	
}
void SPI_voidInitSlave(void)
{
	CLR_BIT(SPCR_REG,SPIE);
	
	SET_BIT(SPCR_REG,DORD);
	
	CLR_BIT(SPCR_REG, MSTR );
	
	SET_BIT(SPCR_REG,CPOL);
	SET_BIT(SPCR_REG,CPHA);
	
	
	SET_BIT(SPCR_REG,SPE);
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