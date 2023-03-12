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
<<<<<<< HEAD
#include "main.h"
#include "usart.h"
#include "param_process_data.h"
#include "globals.h"
=======
#include "can.h"
#include "usart.h"
#include "main.h"
#include "globals.h"
#include "param_process_data.h"
>>>>>>> feature/store_sdo

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_tx;
DMA_HandleTypeDef hdma_rx;
USART_TX_MSG usart_tx_dbg;
USART_TX_MSG usart_tx;
USART_RX_MSG usart_rx;
uint32_t usart_tx_msg_cnt = 0;
uint32_t usart_rx_msg_cnt = 0;
uint8_t usart_rx_chksum_err = 0;
uint8_t usart_rx_read_param_cnt = 0;
uint8_t usart_tx_read_param_cnt = 0;
uint8_t en_send_can = 0;
uint16_t promise_sdo = 0x0000;
<<<<<<< HEAD
=======
uint8_t en_usart_tx_sdo = 0;
uint16_t usart_tx_idx = 0;
uint8_t usart_tx_mutex = 0;
uint8_t en_usart_tx = 0;
uint32_t send_usart_cnt_ms = 0;
uint32_t send_usart_tim_ms = 0;
uint8_t rx[10] = {0,0,0,0,0,0,0,0,0,0};
>>>>>>> feature/store_sdo

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/* USART2 init function */
void MX_USART2_UART_Init(void)
{
	send_usart_tim_ms = 5;	// send usart msg every x [ms]

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
	uint8_t computed_chksm = 0xA5;
	uint8_t usart_rx_err = 0;
    uint32_t data_id = 0;

	if (HAL_UART_Receive_DMA(&huart2, usart_rx.all, USART_MSG_LENGTH)!= HAL_OK)
		Error_Handler();
	usart_rx_msg_cnt++;

	/**
	 * USART Msg Structure:
	 *
	 * idx:	[0]   [1]   [2]     [3]     [4]     [5]     [6]		 [7]        [8]	 	[9]
	 *  	------------------------------------------------------------------------------
	 *  	| ID1 | ID0 | DATA3 | DATA2 | DATA1 | DATA0 | CMDSTS | ARTIFACT | CHKSM | LF |
	 *  	------------------------------------------------------------------------------
	 */
	if ((huart->RxXferSize == 10) && (usart_rx.byte.lf == 0x0A))
	{
		/* Compute Checksum of Usart Rx Msg */
		calc_chksm(&usart_rx.byte.data_id[0], &computed_chksm);
		calc_chksm(&usart_rx.byte.data_id[1], &computed_chksm);
		calc_chksm(&usart_rx.byte.data_val[0], &computed_chksm);
		calc_chksm(&usart_rx.byte.data_val[1], &computed_chksm);
		calc_chksm(&usart_rx.byte.data_val[2], &computed_chksm);
		calc_chksm(&usart_rx.byte.data_val[3], &computed_chksm);
		calc_chksm(&usart_rx.byte.cmd_sts.all, &computed_chksm);
		calc_chksm(&usart_rx.byte.artifact, &computed_chksm);

		/* Decode Usart Rx Msg Checksum */
		usart_rx.byte.checksum = ((usart_rx.byte.checksum == 0x1A) ? (0x0A) : (usart_rx.byte.checksum));

		/* Decode Usart Rx Rest of Msg */
		if (computed_chksm == usart_rx.byte.checksum)
		{
			en_send_can = 1;
			usart_rx.byte.artifact = ((usart_rx.byte.artifact == 0x01) ? (0x0A) : (usart_rx.byte.artifact));

			decode_usart_rx(&usart_rx.byte.data_id[0], ((usart_rx.byte.artifact & 0x80) >> 7));
			decode_usart_rx(&usart_rx.byte.data_id[1], ((usart_rx.byte.artifact & 0x40) >> 6));
			decode_usart_rx(&usart_rx.byte.data_val[0], ((usart_rx.byte.artifact & 0x20) >> 5));
			decode_usart_rx(&usart_rx.byte.data_val[1], ((usart_rx.byte.artifact & 0x10) >> 4));
			decode_usart_rx(&usart_rx.byte.data_val[2], ((usart_rx.byte.artifact & 0x08) >> 3));
			decode_usart_rx(&usart_rx.byte.data_val[3], ((usart_rx.byte.artifact & 0x04) >> 2));
			decode_usart_rx(&usart_rx.byte.cmd_sts.all, ((usart_rx.byte.artifact & 0x02) >> 1));
		}
		else
		{
			usart_rx_err = 1;
			usart_rx_chksum_err++;
		}
	}
	else
	{
		usart_rx_err = 1;
		usart_rx_chksum_err++;
	}

	if (!usart_rx_err)
	{
		/* Assign Data ID Locally */
		data_id = (uint32_t)((uint16_t)(usart_rx.byte.data_id[1] & 0x00FF) +
				(uint16_t)((usart_rx.byte.data_id[0] << 8) & 0xFF00));

		/* Read Parameter */
		if (usart_rx.byte.cmd_sts.bit.read_cmd == 1)
		{
			promise_sdo = (uint16_t)data_id;
			usart_rx_read_param_cnt++;
		}
		/* Write Parameter */
		else
		{
			can_tx_header.StdId = data_id;
		    //can_tx_header.ExtId = 0x01;
			can_tx_header.RTR = CAN_RTR_DATA;
			can_tx_header.IDE = CAN_ID_STD;
			can_tx_header.DLC = CAN_DATA_LENGTH;
			can_tx_header.TransmitGlobalTime = DISABLE;
			can_tx[0] = usart_rx.byte.data_val[0];
			can_tx[1] = usart_rx.byte.data_val[1];
			can_tx[2] = usart_rx.byte.data_val[2];
			can_tx[3] = usart_rx.byte.data_val[3];
		    if (HAL_CAN_AddTxMessage(&hcan, &can_tx_header, &can_tx[0], &can_tx_mailbox) != HAL_OK)
		    	Error_Handler();
		    promise_sdo = (uint16_t)data_id;
		}
	}
	else
	{
		usart_rx.byte.data_id[0] = 0;
		usart_rx.byte.data_id[1] = 0;
		usart_rx.byte.data_val[0] = 0;
		usart_rx.byte.data_val[1] = 0;
		usart_rx.byte.data_val[2] = 0;
		usart_rx.byte.data_val[3] = 0;
		usart_rx.byte.cmd_sts.all = 0;
		usart_rx.byte.artifact = 0;
		usart_rx.byte.checksum = 0;
		usart_rx.byte.lf = 0;
	}
}

/**
  * @brief  Send PDO Data through Serial Tx
  * @param  None
  * @note   None
  * @retval None
  */
void send_pdo_usart(void)
{
	uint8_t en_artifact = 0;
	uint8_t chksm = 0xA5;
	uint8_t data_val[4] = {0, 0, 0, 0};
	uint8_t data_id[2] = {0, 0};
	uint16_t idx = 0;
	CMDSTS data_cmd_sts;

	//BSP_LED_On(LED3);

	/**
	 * USART Msg Structure:
	 *
	 * idx:	[0]   [1]   [2]     [3]     [4]     [5]     [6]		 [7]        [8]	 	[9]
	 *  	------------------------------------------------------------------------------
	 *  	| ID1 | ID0 | DATA3 | DATA2 | DATA1 | DATA0 | CMDSTS | ARTIFACT | CHKSM | LF |
	 *  	------------------------------------------------------------------------------
	 */

	/* Build CMDSTS byte */
	data_cmd_sts.bit.read_cmd = 0;
	data_cmd_sts.bit.chksm_rx_err_sts = (usart_rx_chksum_err & 0x7F);

	/* Copy Data Locally */
	if (en_usart_tx_sdo)
	{
		idx = promise_sdo - ID_SDO_00;
		memcpy(&(data_val[0]), param_data[idx].val, param_data[idx].num_byte);
		data_id[0] = (uint8_t)((param_data[idx].id & 0x0000FF00) >> 8);
		data_id[1] = (uint8_t)(param_data[idx].id & 0x000000FF);
		usart_tx_read_param_cnt++;
	}
	else
	{
		memcpy(&(data_val[0]), process_data[usart_tx_idx].val, process_data[usart_tx_idx].num_byte);
		data_id[0] = (uint8_t)((process_data[usart_tx_idx].id & 0x0000FF00) >> 8);
		data_id[1] = (uint8_t)(process_data[usart_tx_idx].id & 0x000000FF);
	}


	/* Fill usart_tx */
	fill_usart_tx(&en_artifact, &usart_tx.data_id[0], data_id[0], 0, &chksm);
	fill_usart_tx(&en_artifact, &usart_tx.data_id[1], data_id[1], 1, &chksm);
	fill_usart_tx(&en_artifact, &usart_tx.data_val[0], data_val[0], 2, &chksm);
	fill_usart_tx(&en_artifact, &usart_tx.data_val[1], data_val[1], 3, &chksm);
	fill_usart_tx(&en_artifact, &usart_tx.data_val[2], data_val[2], 4, &chksm);
	fill_usart_tx(&en_artifact, &usart_tx.data_val[3], data_val[3], 5, &chksm);
	fill_usart_tx(&en_artifact, &usart_tx.cmd_sts.all, data_cmd_sts.all, 6, &chksm);
	fill_usart_tx(&en_artifact, &usart_tx.artifact,
			((en_artifact == 0x0A) ? (0x01) : (en_artifact)), 7, &chksm);
	fill_usart_tx(&en_artifact, &usart_tx.checksum, chksm, 8, &chksm);
	usart_tx.lf = 0x0A;

//	if (en_usart_tx_sdo)
//	{
//		usart_tx_dbg.data_id[0] = usart_tx.data_id[0];
//		usart_tx_dbg.data_id[1] = usart_tx.data_id[1];
//		memcpy(&usart_tx_dbg, &usart_tx, 10);
//	}

	/* Send Msg Tx */
	if(HAL_UART_Transmit_DMA(&huart2, &usart_tx.data_id[0], USART_MSG_LENGTH)!= HAL_OK)
		Error_Handler();

	//BSP_LED_Off(LED3);

	if (en_usart_tx_sdo)
	{
		en_usart_tx_sdo = 0;
		promise_sdo = 0;
	}
	else
	{
		usart_tx_idx++;
		if (usart_tx_idx >= PDO_LENGTH)
			usart_tx_idx = 0;
	}
}

void fill_usart_tx(uint8_t *en_artifact, uint8_t *serial_tx, uint8_t val, uint16_t pos,
		uint8_t *checksum)
{
	calc_artifact(en_artifact, serial_tx, val, pos);
	calc_chksm(serial_tx, checksum);
}

void calc_artifact(uint8_t *en_artifact, uint8_t *serial_tx, uint8_t val, uint16_t pos)
{
	if (val == 0x0A)
	{
		*serial_tx = 0x1A;
		*en_artifact |= (uint8_t)(0x0001 << (7-pos));
	}
	else
		*serial_tx = val;
}

void calc_chksm(uint8_t *serial_tx, uint8_t *checksum)
{
	*checksum ^= *serial_tx;
}

void decode_usart_rx(uint8_t *serial_rx, uint8_t artifact_bitwise)
{
	*serial_rx = (artifact_bitwise * 0x0A) + (*serial_rx * (1 - artifact_bitwise));
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
