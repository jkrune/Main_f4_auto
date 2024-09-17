#include "delay.h"

TIM_HandleTypeDef htim4;
uint32_t time_run;
void MX_TIM4_Init(void)
{


//50ms
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 1439;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 5000;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_TIM_MspPostInit(&htim4);

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM4)
	{
		time_run++;
	}
}

uint32_t millis(void)
{
	return time_run*50;
}
