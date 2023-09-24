/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : example.c
 * @brief          : Main program body with example usage of button routines.
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
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
struct BUTTONS_T {
	uint8_t btn1;
	uint8_t btn2;
	uint8_t btnUp;
	uint8_t btnDn;
} buttons_t; // define variable for each button!
/* USER CODE END PTD */

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
static void ToggleLED(void);
void BtnRelease(uint8_t *btn, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, void (*BtnFcn)(void));
void BtnPress(uint8_t *btn, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, void (*BtnFcn)(void));
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {

	/* USER CODE END 1 */

	/* USER CODE BEGIN Init */
	/* USER CODE END Init */

	/* USER CODE BEGIN SysInit */
	/* USER CODE END SysInit */

	/* USER CODE BEGIN 2 */
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1) {
		//BtnPress(&buttons_t.btnUp, B1_GPIO_Port, B1_Pin, ToggleLED);
		BtnRelease(&buttons_t.btnDn, B1_GPIO_Port, B1_Pin, ToggleLED); //defined for Nucleo board

		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/* USER CODE BEGIN 4 */

void BtnRelease(uint8_t *btn, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin,
		void (*BtnFcn)(void)) {
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

void BtnPress(uint8_t *btn, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin,
		void (*BtnFcn)(void)) {
	register uint16_t rBtnEvent = (GPIOx->IDR & GPIO_Pin);
	if (!*btn && !rBtnEvent) {
		*btn = 1;
		if (BtnFcn) {
			sBtnFcn();
		}
	} else if (*btn && rBtnEvent) {
		(*btn)++;
	}
}

static void ToggleLED(void) {
	HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
}
/* USER CODE END 4 */
