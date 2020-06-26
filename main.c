/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
/* USART1 TX => PA9
 * USART1 RX => PA10
 *
 * */

#include "Kiti.h"
uint8_t arr[10];
uint32_t test;
int main(void)
{
	for(uint8_t i = 0;i<10; i++) arr[i] = i+1;
setupUSART1();

DMA_Disable(DMA1_Channel4);
DMA_DeInit(DMA1_Channel4);

DMA_Init(DMA1_Channel4, 10, (uint32_t)&(USART1->DR),(uint32_t)&(arr),
	TransCompl_Int_Disable	|
	HalfCompl_Int_Disable	|
	TransError_Int_Disable	|
	ReadPerif		|
	CircularMode_Enable	|
	PeripheralInc_Disable	|
	MemoryInc_Enable	|
	PDataSize_B		|
	MDataSize_B		|
	DMA_PRIORITY_LOW	|
	M2M_Disable);
DMA_Enable(DMA1_Channel4);
//test	=	&arr[0];
  while (1)
  {

  }

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
