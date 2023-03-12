/**
  ******************************************************************************
  * @file    main.h
  * @author  MCD Application Team
  * @brief   Header for main.c module
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
#ifndef _CAN_H_
#define _CAN_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"
#include "stm32f3xx_nucleo_32.h"
#include "param_process_data.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Definition for CANx clock resources */
#define CANx                           CAN
#define CANx_CLK_ENABLE()              __HAL_RCC_CAN1_CLK_ENABLE()
#define CANx_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOA_CLK_ENABLE()

#define CANx_FORCE_RESET()             __HAL_RCC_CAN1_FORCE_RESET()
#define CANx_RELEASE_RESET()           __HAL_RCC_CAN1_RELEASE_RESET()

/* Definition for CANx Pins */
#define CANx_TX_PIN                    GPIO_PIN_12
#define CANx_TX_GPIO_PORT              GPIOA
#define CANx_TX_AF                     GPIO_AF9_CAN
#define CANx_RX_PIN                    GPIO_PIN_11
#define CANx_RX_GPIO_PORT              GPIOA
#define CANx_RX_AF                     GPIO_AF9_CAN

/* Definition for CAN's NVIC */
#define CANx_RX_IRQn                   USB_LP_CAN_RX0_IRQn
#define CANx_RX_IRQHandler             USB_LP_CAN_RX0_IRQHandler

/* Can Objects G170 */
#define PDO_TX_G170_OBJ_ID            1
#define SDO_RX_G170_OBJ_ID            5
#define SDO_TX_G170_OBJ_ID            6

/* Can Objects SYS */
#define PDO_RX_SYS_OBJ_ID             2
#define SDO_TX_SYS_OBJ_ID             3
#define SDO_RX_SYS_OBJ_ID             4

/* Masks */
#define ID_PDO_00                     0x0100
#define ID_SDO_00                     0x0200
#define PDO_MASK_FILT                 ID_PDO_00
#define SDO_RX_SYS_MASK_FILT          ID_SDO_00
#define SDO_BIT_AGGIUNTO              0x0400
#define SDO_RX_G170_MASK_FILT         (SDO_RX_SYS_MASK_FILT | SDO_BIT_AGGIUNTO)

/* Exported variables ------------------------------------------------------- */

extern CAN_HandleTypeDef hcan;
extern CAN_TxHeaderTypeDef can_tx_header;
extern CAN_RxHeaderTypeDef can_rx_header;
extern uint8_t can_tx[CAN_DATA_LENGTH];
extern uint8_t can_rx[CAN_DATA_LENGTH];
extern uint32_t can_tx_mailbox;
extern uint8_t usart_rx_chksum_err;
extern uint16_t promise_sdo;

/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

void MX_CAN1_Init(void);

#endif /* _CAN_H_ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
