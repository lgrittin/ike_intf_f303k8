/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
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
#include "can.h"
#include "usart.h"
#include "main.h"
#include "globals.h"
#include "param_process_data.h"

/* Private typedef -----------------------------------------------------------*/

typedef struct {
	uint8_t data_id[2];
	uint8_t data_val[4];
	uint8_t sts;
	uint8_t artifact;
	uint8_t checksum;
	uint8_t lf;
} USART_TX_MSG;

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_tx;
DMA_HandleTypeDef hdma_rx;
uint8_t usart_tx[USART_MSG_LENGTH][USART_QUEUE_LENGTH];
uint8_t usart_rx[USART_MSG_LENGTH] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
uint32_t usart_tx_msg_cnt = 0;
uint32_t usart_rx_msg_cnt = 0;
uint8_t usart_rx_chksum_err = 0;
uint8_t en_send_can = 0;
uint16_t promise_sdo = 0x0000;

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/* USART2 init function */
void MX_USART2_UART_Init(void)
{
	uint16_t i, k;
	for (i = 0; i < USART_QUEUE_LENGTH; i++)
	{
		for (j = 0; j < USART_MSG_LENGTH; j++)
		{
			usart_tx[i][j]
		}
	}

	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.OverSampling = UART_OVERSAMPLING_16;
	huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
	huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	if (HAL_UART_Init(&huart2) != HAL_OK)
	{
	  Error_Handler();
	}
}

/**
  * @brief UART MSP Initialization
  *        This function configures the hardware resources used:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  *           - DMA configuration for transmission request by peripheral
  *           - NVIC configuration for DMA interrupt request enable
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspInit(UART_HandleTypeDef* huart)
{

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* Enable GPIO clock */
	USARTx_TX_GPIO_CLK_ENABLE();
	USARTx_RX_GPIO_CLK_ENABLE();

	/* Enable USARTx clock */
	USARTx_CLK_ENABLE();

	/* Enable DMA clock */
	DMAx_CLK_ENABLE();

	/* USART2 GPIO Tx/Rx Configuration */
	GPIO_InitStruct.Pin = USARTx_TX_PIN|USARTx_RX_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Alternate = USARTx_TX_AF;

	HAL_GPIO_Init(USARTx_RX_GPIO_PORT, &GPIO_InitStruct);

	/* Configure the DMA handler for Transmission process */
	hdma_tx.Instance                 = USARTx_TX_DMA_CHANNEL;
	hdma_tx.Init.Direction           = DMA_MEMORY_TO_PERIPH;
	hdma_tx.Init.PeriphInc           = DMA_PINC_DISABLE;
	hdma_tx.Init.MemInc              = DMA_MINC_ENABLE;
	hdma_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
	hdma_tx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
	hdma_tx.Init.Mode                = DMA_NORMAL;
	hdma_tx.Init.Priority            = DMA_PRIORITY_LOW;

	HAL_DMA_Init(&hdma_tx);

	/* Associate the initialized DMA handle to the UART handle */
	__HAL_LINKDMA(huart, hdmatx, hdma_tx);

	/* Configure the DMA handler for reception process */
	hdma_rx.Instance                 = USARTx_RX_DMA_CHANNEL;
	hdma_rx.Init.Direction           = DMA_PERIPH_TO_MEMORY;
	hdma_rx.Init.PeriphInc           = DMA_PINC_DISABLE;
	hdma_rx.Init.MemInc              = DMA_MINC_ENABLE;
	hdma_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
	hdma_rx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
	hdma_rx.Init.Mode                = DMA_NORMAL;
	hdma_rx.Init.Priority            = DMA_PRIORITY_HIGH;

	HAL_DMA_Init(&hdma_rx);

	/* Associate the initialized DMA handle to the the UART handle */
	__HAL_LINKDMA(huart, hdmarx, hdma_rx);

	/* NVIC configuration for DMA transfer complete interrupt (USARTx_TX) */
	HAL_NVIC_SetPriority(USARTx_DMA_TX_IRQn, 0, 1);
	HAL_NVIC_EnableIRQ(USARTx_DMA_TX_IRQn);

	/* NVIC configuration for DMA transfer complete interrupt (USARTx_RX) */
	HAL_NVIC_SetPriority(USARTx_DMA_RX_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(USARTx_DMA_RX_IRQn);

	/* NVIC configuration for USART, to catch the TX complete */
	HAL_NVIC_SetPriority(USARTx_IRQn, 0, 1);
	HAL_NVIC_EnableIRQ(USARTx_IRQn);

}

/**
  * @brief UART MSP De-Initialization
  *        This function frees the hardware resources used:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO, DMA and NVIC configuration to their default state
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspDeInit(UART_HandleTypeDef* huart)
{
	/* Peripheral clock disable */
	USARTx_FORCE_RESET();
	USARTx_RELEASE_RESET();

	/* Configure UART Tx/Rx as alternate function  */
	HAL_GPIO_DeInit(USARTx_TX_GPIO_PORT, USARTx_TX_PIN);
	HAL_GPIO_DeInit(USARTx_RX_GPIO_PORT, USARTx_RX_PIN);

	/* De-Initialize the DMA Channel associated to Tx/Rx process */
	HAL_DMA_DeInit(&hdma_tx);
	HAL_DMA_DeInit(&hdma_rx);

	/* Disable the NVIC for DMA */
	HAL_NVIC_DisableIRQ(USARTx_DMA_TX_IRQn);
	HAL_NVIC_DisableIRQ(USARTx_DMA_RX_IRQn);
}

/**
  * @brief  Tx Transfer completed callback
  * @param  huart: UART handle.
  * @note   This example shows a simple way to report end of DMA Tx transfer, and
  *         you can add your own implementation.
  * @retval None
  */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	usart_tx_msg_cnt++;
}

/**
  * @brief  Rx Transfer completed callback
  * @param  huart: UART handle
  * @note   This example shows a simple way to report end of DMA Rx transfer, and
  *         you can add your own implementation.
  * @retval None
  */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    uint8_t computed_chksm = 0x00;
    uint8_t data_chksm = 0x00;
    uint8_t artifact = 0x00;
    uint8_t data_dec[7] = { 0, 0, 0, 0, 0, 0, 0 };

	if (HAL_UART_Receive_IT(&huart2, (uint8_t*)usart_rx, USART_MSG_LENGTH)!= HAL_OK)
		Error_Handler();
	usart_rx_msg_cnt++;

	/**
	 * USART Msg Structure:
	 *
	 * idx:	[0]   [1]   [2]     [3]     [4]     [5]     [6]   [7]        [8]	 [9]
	 *  	---------------------------------------------------------------------------
	 *  	| ID1 | ID0 | DATA3 | DATA2 | DATA1 | DATA0 | STS | ARTIFACT | CHKSM | LF |
	 *  	---------------------------------------------------------------------------
	 */
	if ((huart->RxXferSize == 10) && (usart_rx[9] == 0x0A))
	{
		computed_chksm = 0xA5 ^ \
				usart_rx[0] ^ \
				usart_rx[1] ^ \
				usart_rx[2] ^ \
				usart_rx[3] ^ \
				usart_rx[4] ^ \
				usart_rx[5] ^ \
				usart_rx[6] ^ \
				usart_rx[7];
		data_chksm = ((usart_rx[8] == 0x1A) ? (0x0A) : (usart_rx[8]));
		if (computed_chksm == data_chksm)
		{
			en_send_can = 1;
			artifact = ((usart_rx[7] == 0x01) ? (0x0A) : (usart_rx[7]));
			data_dec[0] = ((((artifact & 0x80) >> 7) * 0x0A) + (usart_rx[0] * (1 - ((artifact & 0x80) >> 7))));
			data_dec[1] = ((((artifact & 0x40) >> 6) * 0x0A) + (usart_rx[1] * (1 - ((artifact & 0x40) >> 6))));
			data_dec[2] = ((((artifact & 0x20) >> 5) * 0x0A) + (usart_rx[2] * (1 - ((artifact & 0x20) >> 5))));
			data_dec[3] = ((((artifact & 0x10) >> 4) * 0x0A) + (usart_rx[3] * (1 - ((artifact & 0x10) >> 4))));
			data_dec[4] = ((((artifact & 0x08) >> 3) * 0x0A) + (usart_rx[4] * (1 - ((artifact & 0x08) >> 3))));
			data_dec[5] = ((((artifact & 0x04) >> 2) * 0x0A) + (usart_rx[5] * (1 - ((artifact & 0x04) >> 2))));
			data_dec[6] = ((((artifact & 0x02) >> 1) * 0x0A) + (usart_rx[6] * (1 - ((artifact & 0x02) >> 1))));
		}
		else
		{
			usart_rx_chksum_err++;
			en_send_can = 0;
		}
	}
	else
	{
		usart_rx_chksum_err++;
		en_send_can = 0;
	}


    /* Configure Transmission process */
	if (en_send_can)
	{
		can_tx_header.StdId = (uint32_t)((uint16_t)(data_dec[1] & 0x00FF) +
				(uint16_t)((data_dec[0] << 8) & 0xFF00));
	    //can_tx_header.ExtId = 0x01;
		can_tx_header.RTR = CAN_RTR_DATA;
		can_tx_header.IDE = CAN_ID_STD;
		can_tx_header.DLC = CAN_DATA_LENGTH;
		can_tx_header.TransmitGlobalTime = DISABLE;
		can_tx[0] = data_dec[2];
		can_tx[1] = data_dec[3];
		can_tx[2] = data_dec[4];
		can_tx[3] = data_dec[5];
	    if (HAL_CAN_AddTxMessage(&hcan, &can_tx_header, can_tx, &can_tx_mailbox) != HAL_OK)
	    	Error_Handler();
	    promise_sdo = (uint16_t)can_tx_header.StdId;
	}
	else
	{
		usart_rx[0] = 0;
		usart_rx[1] = 0;
		usart_rx[2] = 0;
		usart_rx[3] = 0;
		usart_rx[4] = 0;
		usart_rx[5] = 0;
		usart_rx[6] = 0;
		usart_rx[7] = 0;
		usart_rx[8] = 0;
		usart_rx[9] = 0;
	}
}

/**
  * @brief  UART error callbacks
  * @param  huart: UART handle
  * @note   This example shows a simple way to report transfer error, and you can
  *         add your own implementation.
  * @retval None
  */
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
