/**
  ******************************************************************************
  * @file    tim.c
  * @brief   This file provides code for the configuration
  *          of the TIM instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "tim.h"
#include "main.h"
#include "globals.h"
#include "param_process_data.h"
#include <string.h>

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

TIM_HandleTypeDef htim2;
uint32_t uwPrescalerValue = 0;

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/* TIM2 init function */
void MX_TIM2_Init(void)
{
	uwPrescalerValue = (uint32_t) (SystemCoreClock / 10000) - 1;
	htim2.Instance = TIMx;
	htim2.Init.Period = 1000 - 1;	//2^32
	htim2.Init.Prescaler = uwPrescalerValue;
	htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim2.Init.RepetitionCounter = 0;
	htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
	{
		Error_Handler();
	}
	if(HAL_TIM_Base_Start_IT(&htim2) != HAL_OK)
	{
		Error_Handler();
	}
}

/**
  * @brief TIM2 Initialization
  *        This function configures the hardware resources used:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  *           - NVIC configuration for DMA interrupt request enable
  * @param htim: TIM handle pointer
  * @retval None
  */
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
	/* TIMx Peripheral clock enable */
	TIMx_CLK_ENABLE();

	/* Set Interrupt Group Priority */
	HAL_NVIC_SetPriority(TIMx_IRQn, 3, 0);

	/* Enable the TIMx global Interrupt */
	HAL_NVIC_EnableIRQ(TIMx_IRQn);
}

/**
  * @brief TIM2 MSP De-Initialization
  *        This function frees the hardware resources used:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO to their default state
  * @param htim: TIM handle pointer
  * @retval None
  */
void HAL_TIM_MspDeInit(TIM_HandleTypeDef* htim)
{
	if(htim->Instance == TIMx)
	{
		__HAL_RCC_TIM2_CLK_DISABLE();

	    /* TIM2 interrupt Deinit */
	    HAL_NVIC_DisableIRQ(TIMx_IRQn);
	}
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    BSP_LED_Toggle(LED3);
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
