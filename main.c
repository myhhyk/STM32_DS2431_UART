#include "main.h"

void setupRCC(void);
void setupPORTC(void);

int main(void)
{
	setupRCC();
	setupPORTC();
  while (1)
  {
	  GPIOC->ODR ^=		(1<<13);
	  for(uint16_t i = 0; i<0xffff;i++);
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
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
