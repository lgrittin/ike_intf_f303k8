/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H__
#define __USART_H__

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"
#include "stm32f3xx_nucleo_32.h"
#include "param_process_data.h"

/* Exported types ------------------------------------------------------------*/

typedef struct {
	uint8_t data_id[2];
	uint8_t data_val[4];
	uint8_t sts;
	uint8_t artifact;
	uint8_t checksum;
	uint8_t lf;
} USART_TX_MSG;

/* Exported constants --------------------------------------------------------*/

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
#define USART_QUEUE_LENGTH				25

/* Definition for USARTx clock resources */
#define USARTx                           USART2
#define USARTx_CLK_ENABLE()              __HAL_RCC_USART2_CLK_ENABLE()
#define DMAx_CLK_ENABLE()                __HAL_RCC_DMA1_CLK_ENABLE()
#define USARTx_RX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()
#define USARTx_TX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()

#define USARTx_FORCE_RESET()             __HAL_RCC_USART2_FORCE_RESET()
#define USARTx_RELEASE_RESET()           __HAL_RCC_USART2_RELEASE_RESET()

/* Definition for USARTx Pins */
#define USARTx_TX_PIN                    GPIO_PIN_2
#define USARTx_TX_GPIO_PORT              GPIOA
#define USARTx_TX_AF                     GPIO_AF7_USART2
#define USARTx_RX_PIN                    GPIO_PIN_15
#define USARTx_RX_GPIO_PORT              GPIOA
#define USARTx_RX_AF                     GPIO_AF7_USART2

/* Definition for USARTx's DMA */
#define USARTx_TX_DMA_CHANNEL            DMA1_Channel7
#define USARTx_RX_DMA_CHANNEL            DMA1_Channel6

/* Definition for USARTx's NVIC */
#define USARTx_DMA_TX_IRQn               DMA1_Channel7_IRQn
#define USARTx_DMA_RX_IRQn               DMA1_Channel6_IRQn
#define USARTx_DMA_TX_IRQHandler         DMA1_Channel7_IRQHandler
#define USARTx_DMA_RX_IRQHandler         DMA1_Channel6_IRQHandler

/* Definition for USARTx's NVIC */
#define USARTx_IRQn                      USART2_IRQn
#define USARTx_IRQHandler                USART2_IRQHandler

/* Exported macro ------------------------------------------------------------*/

#define COUNTOF(__BUFFER__)   (sizeof(__BUFFER__) / sizeof(*(__BUFFER__)))

/* Exported functions ------------------------------------------------------- */

void MX_USART2_UART_Init(void);
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart);
void fill_usart_tx(uint8_t *en_artifact, uint8_t *serial_tx, uint8_t val, uint16_t pos,
		uint8_t *checksum);
void calc_artifact(uint8_t *en_artifact, uint8_t *serial_tx, uint8_t val, uint16_t pos);
void calc_chksm(uint8_t *serial_tx, uint8_t *checksum);
void send_pdo_usart(void);

/* Exported variables ------------------------------------------------------- */

extern UART_HandleTypeDef huart2;
extern DMA_HandleTypeDef hdma_tx;
extern DMA_HandleTypeDef hdma_rx;
extern USART_TX_MSG usart_tx;
extern uint8_t usart_rx[USART_MSG_LENGTH];
extern uint32_t usart_tx_msg_cnt;
extern uint32_t usart_rx_msg_cnt;
extern uint8_t usart_rx_chksum_err;
extern uint8_t en_send_can;
extern uint8_t en_usart_tx;
extern uint16_t promise_sdo;
extern uint16_t usart_tx_idx;
extern uint8_t usart_tx_mutex;
extern uint32_t send_usart_cnt_ms;
extern uint32_t send_usart_tim_ms;
extern uint8_t en_usart_tx_sdo;

#endif /* __USART_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
