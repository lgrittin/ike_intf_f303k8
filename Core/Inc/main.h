/**
  ******************************************************************************
  * @file    main.h
  * @author  Luca Grittini
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
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"
#include "stm32f3xx_nucleo_32.h"
#include "param_process_data.h"
#include "globals.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/**
 * USART Msg Structure:
 *
 * idx:	[0]   [1]   [2]     [3]     [4]     [5]     [6]   [7]        [8]	 [9]
 *  	---------------------------------------------------------------------------
 *  	| ID1 | ID0 | DATA3 | DATA2 | DATA1 | DATA0 | STS | ARTIFACT | CHKSM | LF |
 *  	---------------------------------------------------------------------------
 */
#define CAN_ADDRESS_LENGTH             	2
#define CAN_DATA_LENGTH               	4
#define USART_ARTIFACT					1
#define USART_STS						1
#define USART_CHECKSUM					1
#define USART_LF		              	1
#define USART_MSG_LENGTH              	10/*CAN_ADDRESS_LENGTH + \
									  	CAN_DATA_LENGTH + \
										USART_ARTIFACT + \
										USART_STS + \
										USART_CHECKSUM + \
										USART_LF*/

/* Exported functions ------------------------------------------------------- */
extern void Error_Handler(void);

/* Exported variables ------------------------------------------------------- */
extern UART_HandleTypeDef huart2;
extern DMA_HandleTypeDef hdma_tx;
extern DMA_HandleTypeDef hdma_rx;
extern uint8_t usart_tx[2*USART_MSG_LENGTH];
extern uint8_t usart_rx[USART_MSG_LENGTH];
extern uint32_t usart_tx_msg_cnt;
extern uint32_t usart_rx_msg_cnt;
extern uint8_t usart_rx_chksum_err;
extern uint8_t en_send_can;
extern CAN_HandleTypeDef hcan;
extern CAN_TxHeaderTypeDef can_tx_header;
extern CAN_RxHeaderTypeDef can_rx_header;
extern uint8_t can_tx[CAN_DATA_LENGTH];
extern uint8_t can_rx[CAN_DATA_LENGTH];
extern uint32_t can_tx_mailbox;
extern uint8_t usart_rx_chksum_err;
extern uint16_t promise_sdo;
extern uint32_t cnt;

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
