/*
 * Kiti.h
 *
 *  Created on: 25 июн. 2020 г.
 *      Author: engineer01
 */

#ifndef SRC_KITI_H_
#define SRC_KITI_H_

#include "stm32f103xb.h"
#include "main.h"
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

void DMA_Init(DMA_Channel_TypeDef* Channel, uint16_t Size, uint32_t Perif, uint32_t Mem, uint16_t Conf){
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

void DMA_Enable(DMA_Channel_TypeDef* Channel){
	Channel->CCR 	|=	DMA_CCR1_EN;
}

void DMA_Disable(DMA_Channel_TypeDef* Channel){
	Channel->CCR	&=	(uint16_t)(~DMA_CCR1_EN);
}

void setupRCC(void){
	RCC->CR 		|=	(16<<3);	 	//TRIM = 16
	RCC->CR 		|=	(1<<0);			//HSION
	while(!(RCC->CR & (1<<1)));			//wait HSIRDY
	RCC->CFGR		|=	(5<<MCO);		//HSI selected
}

void setupUSART1(void){
	RCC->APB2ENR 	|=	(1<<USART1EN);	//USART1 EN

}




#endif /* SRC_KITI_H_ */

