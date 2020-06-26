/*
 * Kiti.h
 *
 *  Created on: 16 июн. 2020 г.
 *      Author: myhhuk
 */

#ifndef INC_KITI_H_
#define INC_KITI_H_

#define DMA1_Channel1_IT_Mask ((uint32_t)(15<<0))
#define DMA1_Channel2_IT_Mask ((uint32_t)(15<<4))
#define DMA1_Channel3_IT_Mask ((uint32_t)(15<<8))
#define DMA1_Channel4_IT_Mask ((uint32_t)(15<<12))
#define DMA1_Channel5_IT_Mask ((uint32_t)(15<<16))
#define DMA1_Channel6_IT_Mask ((uint32_t)(15<<20))
#define DMA1_Channel7_IT_Mask ((uint32_t)(15<<24))

#define DMAEnable ((uint16_t)(1<<0))
#define DMADisable ((uint16_t)0)

#define TransCompl_Int_Enable ((uint16_t)(1<<1))
#define TransCompl_Int_Disable ((uint16_t)0)

#define HalfCompl_Int_Enable ((uint16_t)1<<2)
#define HalfCompl_Int_Disable ((uint16_t)0)

#define TransError_Int_Enable ((uint16_t)(1<<3))
#define TransError_Int_Disable ((uint16_t)0)

#define ReadMemory ((uint16_t)(1<<4))
#define ReadPerif ((uint16_t)0)

#define CircularMode_Enable ((uint16_t)1<<5)
#define CircularMode_Disable ((uint16_t)0)


#define PeripheralInc_Enable ((uint16_t)(1<<6))
#define PeripheralInc_Disable ((uint16_t)0)

#define MemoryInc_Enable ((uint16_t)(1<<7))
#define MemoryInc_Disable ((uint16_t)0)

#define PDataSize_B ((uint16_t)0)
#define PDataSize_W ((uint16_t)0x0100)
#define PDataSize_DW ((uint16_t)0x0200)

#define MDataSize_B ((uint16_t)0)
#define MDataSize_W ((uint16_t)0x0400)
#define MDataSize_DW ((uint16_t)0x0800)

#define DMA_Priority_Low ((uint16_t)0)
#define DMA_Priority_Med ((uint16_t)(1<<12))
#define DMA_Priority_Hi  ((uint16_t)(2<<12))
#define DMA_Priority_VHi ((uint16_t)(3<<12))

#define M2M_Enable (1<<14)
#define M2M_Disable 0
#define CCR_CLEAR_Mask           ((uint32_t)0xFFFF8001)

#define MCO 		24
#define USART1EN 	14

#define	DMA_CCR1_EN	(1<<0)


void DMA_Init(DMA_Channel_TypeDef Channel, uint16_t Size, uint32_t Perif, uint32_t Mem, uint16_t Conf){
uint32_t tmp  = 0;

	tmp = 	Channel->CCR;
	tmp	&=	(uint32_t)(0xffff0001);
	Conf =	tmp;

	Channel->CNDTR 	= 	Size;
	Channel->CPAR	=	Perif;
	Channel->CMAR	=	Mem;
	Channel->CCR	=	Conf;
}

void DMA_DeInit(DMA_Channel_TypeDef* Channel){

	Channel->CCR	&=	(uint16_t)(~DMA_CCR1_EN);
	Channel->CCR	=	0;
	Channel->CNDTR	=	0;
	Channel->CPAR	=	0;
	Channel->CMAR	=	0;

	if (Channel == DMA1_Channel1)
	{
		DMA1->IFCR 	|=  DMA1_Channel1_IT_Mask;
	}
	else if(Channel == DMA1_Channel2){
		DMA1->IFCR	|=	DMA1_Channel2_IT_Mask;
	}
	else if(Channel == DMA1_Channel3){
		DMA1->IFCR	|=	DMA1_Channel3_IT_Mask;
	}
	else if(Channel == DMA1_Channel4){
		DMA1->IFCR	|=	DMA1_Channel4_IT_Mask;
	}
	else if(Channel == DMA1_Channel5){
		DMA1->IFCR	|=	DMA1_Channel5_IT_Mask;
	}
}


void setupRCC(void){
	RCC->CR			|=	(16<<3);//HSITRIM = 16
	RCC->CR			|= 	(1<<0);//HSI on

	RCC->CFGR		|=	(5<<24);//MCO HSI sel
	RCC->APB2ENR	|=	(1<<4);//IOPC
}
void setupPORTC(void){
	GPIOC->CRH		&=	~(15<<20);//0b0000<<20
	GPIOC->CRH		|=	 (2<<20);//mode output 2mHz
	GPIOC->CRH 		&=	~(3<<22);//cnf  push/pull
}
void setupUSART1(void){
	RCC->APB2ENR 	|=	(1<<USART1EN);	//USART1 EN
}



#endif /* INC_KITI_H_ */
