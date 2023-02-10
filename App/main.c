#include "Std_Types.h"
#include "Bit_Math.h"
#include "SysTick.h"
#include "IntCtrl.h"
#include "DIO.h"
#include "Led.h"
#include "Btn.h"
#include "Mcu_Hw.h"




void Adjust(void);
void check(void);

static u8  Flag = 1;
static u8 ON_Time = 2;
static u8 ON_temp = 2;
static u8 OFF_Time =2;
static u8 OFF_temp =2;





void Adjust(void)
{	

	if(Flag==1)
	{
		LED_ON();
		ON_temp-- ;
		if(ON_temp==0)
		{
			Flag=0;
			ON_temp=ON_Time;
			OFF_temp=OFF_Time;
		}
	}
	
	else{
	LED_OFF();
	OFF_temp--;
		if(OFF_temp==0)
		{
			Flag=1;
			ON_temp=ON_Time;
			OFF_temp=OFF_Time;
		}	
	}
}

int main(void)
{

	LED_Init();
	BTN_INIT();
	DIO_ExInt();
	Systick_Init();
	Systick_StartTimer(16000000);
	Systick_VoidCallBack(Adjust);
	ExInt_voidCallBack(check);
	
	
	while(1)
		{	
		}

}



void check(void)
{

	 if ((GPIOF_MIS&0x01)==0x01)
	{

		ON_Time--;
		OFF_Time++;
		ON_temp=ON_Time;
		OFF_temp=OFF_Time;
		
		SET_BIT(GPIOF_ICR,PIN_0);
		
	}
	else if((GPIOF_MIS&0x10)==0x10)
	{
		
		ON_Time++;
		OFF_Time--;
		ON_temp=ON_Time;
		OFF_temp=OFF_Time;
		SET_BIT(GPIOF_ICR,PIN_4);
	}
}