#ifndef	SYSTICK_H
#define	SYSTICK_H

#include "STD_TYPES.h"


#define	SYSTEM_CLK_SRC 			0
#define	PREC_INTERNAL_OSC_4		1

#define	SysTick_S_INTERVAL	0
#define	SysTick_P_INTERVAL	1

#define	 SysTick_CLK_SRC		SYSTEM_CLK_SRC	

void Systick_Init(void);
void Systick_StartTimer( u32 Ticks );
void Systick_VoidCallBack( void (*ptr) (void));


#endif
