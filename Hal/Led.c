#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "Led.h"



void LED_Init()
{	
	DIO_SetEnable(LED_PORT,LED_PIN,DIO_EN);
	DIO_SetDir(LED_PORT,LED_PIN,DIO_OUT);
	
}


void LED_ON()
{
	DIO_SetValue(LED_PORT,LED_PIN,LED_On);
}
void LED_OFF()
{
	DIO_SetValue(LED_PORT,LED_PIN,LED_Off);
}


