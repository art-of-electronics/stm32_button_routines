/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    btnFcn.h
  * @brief   This file contains the headers of the button handling routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 _art_of_electronics_.
  * All rights reserved.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef BTNFCN_H
#define BTNFCN_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
 /* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/

void BtnRelease(uint8_t *btn, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, void (*BtnFcn)(void));
void BtnPress(uint8_t *btn, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, void (*BtnFcn)(void));

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

#ifdef __cplusplus
}
#endif

#endif /* BTNFCN_H */
