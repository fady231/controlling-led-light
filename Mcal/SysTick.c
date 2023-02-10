
#include "Std_Types.h"
#include "Bit_Math.h"
#include "Mcu_Hw.h"
#include "SysTick.h"
#include "IntCtrl.h"

static void (*SysTick_CallBack) (void);


void SysTick_Handler(void);
	


void Systick_Init(void)
{
	
	STK -> STCTRL = 7;
}

void Systick_StartTimer( u32 Ticks )
{
	
	STK -> STRELOAD = Ticks-1;
	STK->STCURRENT=	0;
}


void Systick_VoidCallBack( void (*ptr) (void))
{
		 SysTick_CallBack = ptr ;
}


void SysTick_Handler(void)
{
	
	SysTick_CallBack();
}

