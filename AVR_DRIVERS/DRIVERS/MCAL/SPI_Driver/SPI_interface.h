/*
 * SPI_interface.h
 *
 * Created: 3/5/2024 11:39:22 AM
 *  Author: ROAA AIMAN
 */ 
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidInitMaster(void);
void SPI_voidInitSlave(void);
void SPI_voidSetCallBack( void (*PtrToFunc) (void) );
u8 SPI_u8ReadDataISR(void);
void SPI_voidSendDataISR(u8 Copy_u8Data);

void SPI_voidTransieve(u8 copy_u8TxData,u8* copy_pu8RxData);





#endif /* SPI_INTERFACE_H_ */