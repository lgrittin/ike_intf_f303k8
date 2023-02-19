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

struct CMDSTS_BIT {
	uint8_t read_cmd : 1;			// bit0
	uint8_t chksm_rx_err_sts : 7;	// bit1..bit7
};

typedef union CMDSTS {
	uint8_t all;
	struct CMDSTS_BIT bit;
} CMDSTS;

typedef struct {
	uint8_t data_id[2];
	uint8_t data_val[4];
	CMDSTS cmd_sts;
	uint8_t artifact;
	uint8_t checksum;
	uint8_t lf;
} USART_TX_MSG;

typedef union USART_RX_MSG {
	uint8_t all[USART_MSG_LENGTH];
	USART_TX_MSG byte;
} USART_RX_MSG;

/* Exported constants --------------------------------------------------------*/

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
void decode_usart_rx(uint8_t *serial_rx, uint8_t artifact_bitwise);
void send_pdo_usart(void);

/* Exported variables ------------------------------------------------------- */

extern UART_HandleTypeDef huart2;
extern DMA_HandleTypeDef hdma_tx;
extern DMA_HandleTypeDef hdma_rx;
extern USART_TX_MSG usart_tx;
extern USART_RX_MSG usart_rx;
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
extern uint8_t rx[10];

#endif /* __USART_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
