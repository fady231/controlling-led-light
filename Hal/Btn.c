#include "DIO.h"
#include "Btn.h"




void BTN_INIT()
{
	DIO_SetEnable(BTN_PORT,BTN1_PIN,DIO_EN);
	DIO_SetDir(BTN_PORT,BTN1_PIN,DIO_IN);
    DIO_SetPD(BTN1_PIN);
	DIO_SetEnable(BTN_PORT,BTN2_PIN,DIO_EN);
	DIO_SetDir(BTN_PORT,BTN2_PIN,DIO_IN);
    DIO_SetPD(BTN2_PIN);
}


