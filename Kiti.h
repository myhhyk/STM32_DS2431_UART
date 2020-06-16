/*
 * Kiti.h
 *
 *  Created on: 16 июн. 2020 г.
 *      Author: myhhuk
 */

#ifndef INC_KITI_H_
#define INC_KITI_H_

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
