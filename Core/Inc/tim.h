/**
  ******************************************************************************
  * @file    tim.h
  * @brief   Header for tim.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _TIM_H_
#define _TIM_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"
#include "stm32f3xx_nucleo_32.h"
#include "param_process_data.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Definition for TIMx clock resources */
#define TIMx                           TIM2
#define TIMx_CLK_ENABLE                __HAL_RCC_TIM2_CLK_ENABLE

/* Definition for TIMx's NVIC */
#define TIMx_IRQn                      TIM2_IRQn
#define TIMx_IRQHandler                TIM2_IRQHandler

/* Exported variables ------------------------------------------------------- */

/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

void MX_TIM2_Init(void);

/* Exported variables ------------------------------------------------------- */

extern TIM_HandleTypeDef htim2;

#endif /* _TIM_H_ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
