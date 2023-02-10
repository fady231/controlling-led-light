
#include "Std_Types.h"
#include "Bit_Math.h"
#include "Mcu_Hw.h"
#include "IntCtrl.h"




void IntCrtl_Group_Distribution(u8 Dis)
{
	switch (Dis)
	{
		case GROUP_3_SUB_0:
							SCB_AIRCR = NVIC_GROUP_3_SUB_0;
		break;
		
		case GROUP_2_SUB_1:
							SCB_AIRCR = NVIC_GROUP_2_SUB_1;
		break;

		case GROUP_1_SUB_2:
							SCB_AIRCR = NVIC_GROUP_1_SUB_2;
		break;
		
		case GROUP_0_SUB_3:
							SCB_AIRCR = NVIC_GROUP_0_SUB_3;
		break;

		default :
		break;
	}
	
	
}

void IntCrtl_SetPriority(u8 Index ,u8 Priority)
{
		NVIC_IPR_30 = Priority;
	
}





void IntCrtl_EN_DIS( u8 Index ,u8 Status )
{

	if( Index <= 31)
	{
		if(Status==EN)	NVIC_ISER0 = ( 1 << Index );
		else	NVIC_ICER0 = ( 1 << Index );
	}	
	else if( Index <= 63)
	{
		Index -= 32 ;
		if(Status==EN)	NVIC_ISER1 = ( 1 << Index );
		else	NVIC_ICER1 = ( 1 << Index );	
	}
	else if( Index <= 95)
	{
		Index -= 64 ;
		if(Status==EN)	NVIC_ISER2 = ( 1 << Index );
		else	NVIC_ICER2 = ( 1 << Index );	
	}
	else if( Index <= 127)
	{
		Index -= 96 ;
		if(Status==EN)	NVIC_ISER3= ( 1 << Index );	
		else	NVIC_ICER3= ( 1 << Index );
	}
	else if( Index <= 138)
	{
		Index -= 128 ;
		if(Status==EN)	NVIC_ISER4 = ( 1 << Index );
		else	NVIC_ICER4 = ( 1 << Index );	
	}
	else
	{
		/*Do Nothing*/
	}
}











