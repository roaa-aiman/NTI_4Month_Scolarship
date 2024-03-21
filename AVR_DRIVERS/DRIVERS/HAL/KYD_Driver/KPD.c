/*
 * KPD.c
 *
 * Created: 3/2/2024 8:09:03 PM
 *  Author: ROAA AIMAN
 */ 


#include "KPD.h"
#define F_CPU 16000000UL
#include <util/delay.h>

u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey = NO_PRESSED_KEY;
	u8 Local_u8RowIndex,Local_u8ColumnIndex;
	u8 Local_u8SwitchValue;
	u8 Local_u8Array[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS] = KPD_ARRAY;
	u8 Local_u8RowsArray[NUMBER_OF_ROWS] = {KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
	u8 Local_u8ColumnsArray[NUMBER_OF_COLUMNS] = {KPD_COL0_PIN,KPD_COL1_PIN,KPD_COL2_PIN,KPD_COL3_PIN};


	//deactivate all rows
	for (int i = 0; i<NUMBER_OF_ROWS; i++)
	{
		DIO_voidSetPinValue(KPD_ROWS_PORT,Local_u8RowsArray[i], DIO_PIN_HIGH);
	}

	//looping
	for (Local_u8RowIndex=0; Local_u8RowIndex < NUMBER_OF_ROWS; Local_u8RowIndex++)
	{
		// ACTIVATE THE ROW
		DIO_voidSetPinValue(KPD_ROWS_PORT,Local_u8RowsArray[Local_u8RowIndex], DIO_PIN_LOW);
		

		for (Local_u8ColumnIndex=0; Local_u8ColumnIndex<NUMBER_OF_COLUMNS; Local_u8ColumnIndex++)
		{
			DIO_voidGetPinValue(KPD_COLS_PORT,Local_u8ColumnsArray[Local_u8ColumnIndex],&Local_u8SwitchValue);
			if (!Local_u8SwitchValue)
			{
				 //DEBOUNCING
				 _delay_ms(2);
				while(!Local_u8SwitchValue)
				{
					DIO_voidGetPinValue(KPD_COLS_PORT,Local_u8ColumnsArray[Local_u8ColumnIndex],&Local_u8SwitchValue);
				}
				Local_u8PressedKey= Local_u8Array[Local_u8RowIndex][Local_u8ColumnIndex];
                return Local_u8PressedKey;	
			}
			
		}
		//DEACTIVATE THE ROW
		DIO_voidSetPinValue(KPD_ROWS_PORT,Local_u8RowsArray[Local_u8RowIndex], DIO_PIN_HIGH);
	}
	return Local_u8PressedKey;
}

//u8* pu8PinValue ;
//7-Segments
/*static unsigned char SEGMENT_PATTERN[] = 
	{
		0x0000, // 0
		0x0001, // 1
		0x0010, // 2
		0x0011, // 3
		0x0100, // 4
		0x0101, // 5
		0x0110, // 6
		0x0111, // 7
		0x1000, // 8
		0x1001 // 9
	};*/