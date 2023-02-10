
#ifndef		DIO_H
#define		DIO_H

#include "STD_TYPES.h"


#define		DIO_HIGH	1
#define		DIO_LOW		0		
#define 	DIO_IN	0
#define		DIO_OUT	1
#define		DIO_EN		1
#define		DIO_DIS		0


#define		DIOA	0
#define		DIOB	1
#define		DIOC	2
#define		DIOD	3
#define		DIOE	4
#define		DIOF	5



#define		PIN_0	0
#define		PIN_1	1
#define		PIN_2	2
#define		PIN_3	3
#define		PIN_4	4
#define		PIN_5	5
#define		PIN_6	6
#define		PIN_7	7


void  DIO_SetEnable(u8 PORT , u8 PIN , u8 Status);
void DIO_SetPD(u8 PIN);
void  DIO_SetDir(u8 PORT , u8 PIN , u8 PinDir);
void DIO_SetValue(u8 PORT , u8 PIN , u8 Value);
u8 DIO_ReadChannel(u8 PORT , u8 PIN );
void DIO_ToggleChannel(u8 PORT , u8 PIN );
void DIO_ExInt();
void ExInt_voidCallBack( void (*ptr) (void));
#endif
