/**
  ******************************************************************************
  * @file    can.c
  * @brief   This file provides code for the configuration
  *          of the CAN instances.
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

#define __MAIN__
#include "can.h"
#include "usart.h"
#include "main.h"
#include "globals.h"
#include "param_process_data.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

uint8_t ubKeyNumber = 0x0;
CAN_HandleTypeDef hcan;
CAN_TxHeaderTypeDef can_tx_header;
CAN_RxHeaderTypeDef can_rx_header;
uint8_t can_tx[CAN_DATA_LENGTH];
uint8_t can_rx[CAN_DATA_LENGTH];
uint32_t can_tx_mailbox;
uint8_t en_can_rx = 1;
uint32_t can_rx_cnt = 0;
uint32_t can_pdo_rx_cnt = 0;
uint32_t can_sdo_rx_cnt = 0;
uint32_t can_inv_rx_cnt = 0;

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/* USART2 init function */
void MX_CAN1_Init(void)
{
    CAN_FilterTypeDef  sFilterConfig;

    /* Configure the CAN peripheral */
    hcan.Instance = CANx;  
    hcan.Init.TimeTriggeredMode = DISABLE;
    hcan.Init.AutoBusOff = DISABLE;
    hcan.Init.AutoWakeUp = DISABLE;
    hcan.Init.AutoRetransmission = ENABLE;
    hcan.Init.ReceiveFifoLocked = DISABLE;
    hcan.Init.TransmitFifoPriority = DISABLE;
    hcan.Init.Mode = CAN_MODE_NORMAL;
    hcan.Init.SyncJumpWidth = CAN_SJW_3TQ;
    hcan.Init.TimeSeg1 = CAN_BS1_8TQ;
    hcan.Init.TimeSeg2 = CAN_BS2_1TQ;
    hcan.Init.Prescaler = 4;
    if (HAL_CAN_Init(&hcan) != HAL_OK)
    {
        Error_Handler();
    }

    /* Configure the CAN Filter */
    sFilterConfig.FilterBank = 0;
    sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
    sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
    sFilterConfig.FilterIdHigh = 0x0000;
    sFilterConfig.FilterIdLow = 0x0000;
    sFilterConfig.FilterMaskIdHigh = 0x0000;
    sFilterConfig.FilterMaskIdLow = 0x0000;
    sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
    sFilterConfig.FilterActivation = ENABLE;
    sFilterConfig.SlaveStartFilterBank = 14;
    if (HAL_CAN_ConfigFilter(&hcan, &sFilterConfig) != HAL_OK)
    {
        Error_Handler();
    }

    /* Start the CAN peripheral */
    if (HAL_CAN_Start(&hcan) != HAL_OK)
    {
        Error_Handler();
    }

    /* Activate CAN RX notification */
    if (HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO0_MSG_PENDING)!= HAL_OK)
    {
        Error_Handler();
    }
}

/**
  * @brief CAN MSP Initialization
  *        This function configures the hardware resources used:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  *           - NVIC configuration for DMA interrupt request enable
  * @param hcan: CAN handle pointer
  * @retval None
  */
void HAL_CAN_MspInit(CAN_HandleTypeDef *hcan)
{
    GPIO_InitTypeDef   GPIO_InitStruct; 
    
    /* CAN1 Periph clock enable */
    CANx_CLK_ENABLE();
    
    /* Enable GPIO clock */
    CANx_GPIO_CLK_ENABLE(); 
    
    /* CAN1 TX GPIO pin configuration */
    GPIO_InitStruct.Pin = CANx_TX_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Alternate =  CANx_TX_AF;    
    HAL_GPIO_Init(CANx_TX_GPIO_PORT, &GPIO_InitStruct); 
    
    /* CAN1 RX GPIO pin configuration */
    GPIO_InitStruct.Pin = CANx_RX_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Alternate =  CANx_RX_AF;    
    HAL_GPIO_Init(CANx_RX_GPIO_PORT, &GPIO_InitStruct); 
    
    /* NVIC configuration for CAN1 Reception complete interrupt */
    HAL_NVIC_SetPriority(CANx_RX_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(CANx_RX_IRQn);
}

/**
  * @brief CAN MSP De-Initialization
  *        This function frees the hardware resources used:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO to their default state
  * @param hcan: CAN handle pointer
  * @retval None
  */
void HAL_CAN_MspDeInit(CAN_HandleTypeDef *hcan)
{
    /* Reset peripherals */
    CANx_FORCE_RESET();
    CANx_RELEASE_RESET();
    
    /* De-initialize the CAN1 Tx/Rx GPIO pin */
    HAL_GPIO_DeInit(CANx_TX_GPIO_PORT, CANx_TX_PIN);
    HAL_GPIO_DeInit(CANx_RX_GPIO_PORT, CANx_RX_PIN);  

    /* Disable the NVIC for CAN reception */
    HAL_NVIC_DisableIRQ(CANx_RX_IRQn);
}

/**
  * @brief  Rx Fifo 0 message pending callback
  * @param  hcan: pointer to a CAN_HandleTypeDef structure that contains
  *         the configuration information for the specified CAN.
  * @retval None
  */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	uint16_t idx = 0;

	/* Get RX message */
	if (HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &can_rx_header, can_rx) != HAL_OK)
		Error_Handler();
	can_rx_cnt++;

	if ((can_rx_header.DLC == CAN_DATA_LENGTH) && (en_can_rx))
	{
		/* Check ID of received can packet and take properly action */
		switch (can_rx_header.StdId & 0x0000FF00)
		{
		/* Store PDO */
		case (uint32_t)(ID_PDO_00):
			can_pdo_rx_cnt++;
			idx = (uint16_t)can_rx_header.StdId - ID_PDO_00;
			memcpy(process_data[idx].val, &(can_rx[0]), process_data[idx].num_byte);
			if (idx == 0)
				BSP_LED_Toggle(LED3);
			break;
		/* Store PDO */
		case (uint32_t)(ID_SDO_00):
			can_sdo_rx_cnt++;
			idx = (uint16_t)can_rx_header.StdId - ID_SDO_00;
			memcpy(param_data[idx].val, &(can_rx[0]), param_data[idx].num_byte);
			if (promise_sdo == (uint16_t)can_rx_header.StdId)
				en_usart_tx_sdo = 1;

			break;
		/* Ignore */
		default:
			can_inv_rx_cnt++;
			//send_usart_code = 0;
			break;
		}

		if (can_pdo_rx_cnt > 2*PDO_LENGTH)
		{
			en_usart_tx = 1;
			//en_can_rx = 0;
		}
	}
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
