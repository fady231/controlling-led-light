#ifndef INTCTRL_H
#define	INTCTRL_H

#include "Std_Types.h"
#include "Bit_Math.h"



#define	NVIC_GROUP_3_SUB_0		0x05FA0400
#define	NVIC_GROUP_2_SUB_1		0x05FA0500
#define	NVIC_GROUP_1_SUB_2		0x05FA0600
#define	NVIC_GROUP_0_SUB_3		0x05FA0700


#define GROUP_3_SUB_0 0
#define GROUP_2_SUB_1 1
#define GROUP_1_SUB_2 2
#define GROUP_0_SUB_3 3

#define EN 1
#define DIS 0






void IntCrtl_Group_Distribution(u8 dis);
void IntCrtl_SetPriority(u8 Index ,u8 Priority);
void IntCrtl_EN_DIS( u8 Index ,u8 Status );



#endif
