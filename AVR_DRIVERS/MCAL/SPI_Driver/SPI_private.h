/*
 * SPI_private.h
 *
 * Created: 3/5/2024 11:37:59 AM
 *  Author: SMART
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


/*typedef struct   
{
	u8 SPDR_REG; 
	u8 SPSR_REG;
    u8 SPCR_REG; 
}SPI_TypeDef;*/

#define SPDR_REG  (*(volatile u8*)0x2F)
#define SPSR_REG  (*(volatile u8*)0x2E)
#define SPCR_REG  (*(volatile u8*)0x2D)

#define    SPIF         7
#define    WCOL         6
#define    SPI2X        0

/* SPI Control Register - SPCR */
#define    SPIE         7
#define    SPE          6
#define    DORD         5
#define    MSTR         4
#define    CPOL         3
#define    CPHA         2
#define    SPR1         1
#define    SPR0         0


#endif /* SPI_PRIVATE_H_ */