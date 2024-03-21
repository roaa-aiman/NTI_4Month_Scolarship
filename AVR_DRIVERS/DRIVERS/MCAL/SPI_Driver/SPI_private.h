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
#define    SPIF         7
#define    WCOL         6
#define    SPI2X        0
#define SPCR_REG  (*(volatile u8*)0x2D)

/* SPI Control Register - SPCR */
#define    SPIE         7
#define    SPE          6
#define    DORD         5
#define    MSTR         4
#define    CPOL         3
#define    CPHA         2
#define    SPR1         1
#define    SPR0         0


#define ENABLE_INTERRUPT    1
#define DISABLE_INTERRUPT   0

#define LSB_FIRST           0
#define MSB_FIRST           1


#define IDLE_LOW            0
#define IDLE_HIGH           1

#define SAMPLE_AT_LEADING   0
#define SETUP_AT_LEADING    1

#define DIVIDE_BY_4         0
#define DIVIDE_BY_2         1
#define DIVIDE_BY_16        2
#define DIVIDE_BY_64        3


#endif /* SPI_PRIVATE_H_ */