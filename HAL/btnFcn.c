/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    btnFcn.c
 * @brief   Nonblocking routines for button handling.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 _art_of_electronics_.
 * All rights reserved.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include "main.h"
#include "btnFcn.h"
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */
/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
/* USER CODE BEGIN EV */
/* USER CODE END EV */

/* USER CODE BEGIN 1 */
/******************************************************************************/
/**
 * @brief This function handles button event upon pressing and releasing.
 */
void BtnRelease(uint8_t *btn, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, void (*BtnFcn)(void)) {
	register uint16_t rBtnEvent = (GPIOx->IDR & GPIO_Pin);
	if (!*btn && !rBtnEvent) {
		*btn = 1;
	} else if (*btn && rBtnEvent) {
		if (!++*btn) {
			if (BtnFcn) {
				BtnFcn();
			}
		}
	}
}

/**
 * @brief This function handles button event upon pressing.
 */
void BtnPress(uint8_t *btn, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, void (*BtnFcn)(void)) {
	register uint16_t rBtnEvent = (GPIOx->IDR & GPIO_Pin);
	if (!*btn && !rBtnEvent) {
		*btn = 1;
		if (BtnFcn) {
			BtnFcn();
		}
	} else if (*btn && rBtnEvent) {
		(*btn)++;
	}
}

/* USER CODE END 1 */
