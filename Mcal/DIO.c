#include "Std_Types.h"
#include "Bit_Math.h"
#include "Mcu_Hw.h"
#include "DIO.h"


static void (*ExInt_CallBack) (void);

void  DIO_SetEnable(u8 PORT , u8 PIN , u8 Status)
{
	switch(PORT)
	{
		case DIOA :
					RCGCPORT |= (1U << 0);
					if(DIO_EN == Status)
					{
						SET_BIT( GPIOA_DEN , PIN);
					}
					else
					{
						CLR_BIT( GPIOA_DEN , PIN );
					}
		break;
		case DIOB :
					RCGCPORT |= (1U << 1);
					if(DIO_EN == Status)
					{
						SET_BIT( GPIOB_DEN , PIN);
					}
					else
					{
						CLR_BIT( GPIOB_DEN , PIN );
					}
		break;
		case DIOC :
					RCGCPORT |= (1U << 2);	
					if(DIO_EN == Status)
					{
						SET_BIT( GPIOC_DEN , PIN);
					}
					else
					{
						CLR_BIT( GPIOC_DEN , PIN );
					}
		break;
		case DIOD :
					RCGCPORT |= (1U << 3);
					if(DIO_EN == Status)
					{
						SET_BIT( GPIOD_DEN , PIN);
					}
					else
					{
						CLR_BIT( GPIOD_DEN , PIN );
					}
		break;
		case DIOE :
					RCGCPORT |= (1U << 4);
					if(DIO_EN == Status)
					{
						SET_BIT( GPIOE_DEN , PIN);
					}
					else
					{
						CLR_BIT( GPIOE_DEN , PIN );
					}
		break;
		case DIOF :
					RCGCPORT |= (1U << 5);
					if(DIO_EN == Status)
					{
						SET_BIT( GPIOF_DEN , PIN);
					}
					else
					{
						CLR_BIT( GPIOF_DEN , PIN );
					}
		break;
		default : 
		break;
	}
}



void DIO_SetPD(u8 PIN)
{
	GPIOF_LOCK = 0x4C4F434B;  
	GPIOF_CR	|= ( 1 << PIN );
	GPIOF_PDR |= (1 << PIN );        
	GPIOF_DR4R |= (1 << PIN );	

}



void  DIO_SetDir(u8 PORT , u8 PIN , u8 PinDir)
{
	switch(PORT)
	{
		case DIOA :
					if(DIO_OUT == PinDir)	SET_BIT( GPIOA_DIR , PIN);			
					else	CLR_BIT( GPIOA_DIR , PIN );		
		break;

		case DIOB :
					if(DIO_OUT == PinDir)	SET_BIT( GPIOB_DIR , PIN);	
					else	CLR_BIT( GPIOB_DIR , PIN );
		break;

		case DIOC :
					if(DIO_OUT == PinDir)	SET_BIT( GPIOC_DIR , PIN);
					else	CLR_BIT( GPIOC_DIR , PIN );		
		break;

		case DIOD :
					if(DIO_OUT == PinDir)	SET_BIT( GPIOD_DIR , PIN);	
					else	CLR_BIT( GPIOD_DIR , PIN );		
		break;

		case DIOE :
					if(DIO_OUT == PinDir)	SET_BIT( GPIOE_DIR , PIN);
					else	CLR_BIT( GPIOE_DIR , PIN );			
		break;

		case DIOF :
					if(DIO_OUT == PinDir)	SET_BIT( GPIOF_DIR , PIN);
					else	CLR_BIT( GPIOF_DIR , PIN );
		break;
		default : 
		break;
		
	}
}


void DIO_SetValue(u8 PORT , u8 PIN , u8 Value)
{
	switch(PORT)
	{
		case DIOA :
					if(DIO_HIGH == Value)	SET_BIT( GPIOA_DATA , PIN);
					else	CLR_BIT( GPIOA_DATA , PIN );
		break;

		case DIOB :
					if(DIO_HIGH == Value)	SET_BIT( GPIOB_DATA , PIN);
					else	CLR_BIT( GPIOB_DATA , PIN );				
		break;

		case DIOC :
					if(DIO_HIGH == Value)	SET_BIT( GPIOC_DATA , PIN);		
					else	CLR_BIT( GPIOC_DATA , PIN );
		break;

		case DIOD :
					if(DIO_HIGH == Value)	SET_BIT( GPIOD_DATA , PIN);
					else	CLR_BIT( GPIOD_DATA , PIN );
		break;

		case DIOE :
					if(DIO_HIGH == Value)	SET_BIT( GPIOE_DATA , PIN);
					else	CLR_BIT( GPIOE_DATA , PIN );	
		break;

		case DIOF :
					if(DIO_HIGH == Value)	SET_BIT( GPIOF_DATA , PIN);
					else	CLR_BIT( GPIOF_DATA , PIN );
		break;
		default : 
		break;
		
	}
	
}


u8 DIO_ReadChannel(u8 PORT , u8 PIN )
{
	u8 Result = 0;
	switch(PORT)
	{
		case DIOA :
			Result = GET_BIT(GPIOA_DATA,PIN); 
		break;

		case DIOB :
			Result = GET_BIT(GPIOB_DATA,PIN); 
		break;

		case DIOC :	
			Result = GET_BIT(GPIOC_DATA,PIN); 
		break;	

		case DIOD :	
			Result = GET_BIT(GPIOC_DATA,PIN); 	
		break;

		case DIOE :	
			Result = GET_BIT(GPIOE_DATA,PIN); 	
		break;

		case DIOF : 	
			Result = GET_BIT(GPIOF_DATA,PIN); 
		break;

		default :
		break;                                      	
	}
	return Result ;
}


void DIO_ToggleChannel(u8 PORT , u8 PIN )
{
	switch(PORT)
	{
		case DIOA :
					TOG_BIT( GPIOA_DATA , PIN);
		break;

		case DIOB :
					TOG_BIT( GPIOB_DATA , PIN);
		break;

		case DIOC :
					TOG_BIT( GPIOC_DATA , PIN);
		break;

		case DIOD :
					TOG_BIT( GPIOD_DATA , PIN);
		break;

		case DIOE :
					TOG_BIT( GPIOE_DATA , PIN);
		break;

		case DIOF :			
					TOG_BIT( GPIOF_DATA , PIN);
		break;

		default :
		break;
	}
	
}

void DIO_ExInt()
{	
	CLR_BIT(GPIOF_IS, PIN_0);
	CLR_BIT(GPIOF_IS, PIN_4);
	CLR_BIT(GPIOF_IBE, PIN_0);
	CLR_BIT(GPIOF_IBE, PIN_4);
	CLR_BIT(GPIOF_IEV, PIN_0);
	CLR_BIT(GPIOF_IEV, PIN_4);
	SET_BIT( GPIOF_IM , PIN_0);
	SET_BIT( GPIOF_IM , PIN_4);
	SET_BIT( GPIOF_ICR , PIN_0);
	SET_BIT( GPIOF_ICR , PIN_4);
	NVIC_ISER0 |=(1<<30);
	NVIC_IPR_30=0x60;

}
void ExInt_voidCallBack( void (*ptr) (void))
{
		 ExInt_CallBack = ptr ;
}


void GPIOF_Handler()
{
	ExInt_CallBack();
}