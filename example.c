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
uint16_t _btn1 = 0; // define value for each button!
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
static void Toggle_LED(void);
void HAL_BtnRelease(uint16_t *_key, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, void (*key_fcn)(void));
void HAL_BtnPress(uint16_t *_btn, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, void (*btn_fcn)(void));
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE END 1 */

  /* USER CODE BEGIN Init */
  /* USER CODE END Init */

  /* USER CODE BEGIN SysInit */
  /* USER CODE END SysInit */

  /* USER CODE BEGIN 2 */
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  HAL_BtnPress(&_btn1, Btn_GPIO_Port, Btn_Pin, Toggle_LED);
	  //HAL_BtnRelease(&_btn1, Btn_GPIO_Port, Btn_Pin, Toggle_LED);

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/* USER CODE BEGIN 4 */

void HAL_BtnRelease(uint16_t *_btn, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, void (*btn_fcn)(void)) {
	register uint16_t btn_event = (GPIOx->IDR & GPIO_Pin);
	if (!*_btn && !btn_event) {
		*_btn = 1;
	} else if (*_btn && btn_event) {
		if (!++*_btn) {
			if (btn_fcn) {
				btn_fcn();
			}
		}
	}
}

void HAL_BtnPress(uint16_t *_btn, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, void (*btn_fcn)(void)) {
  register uint16_t btn_event = (GPIOx->IDR & GPIO_Pin);
  if(!*_btn && !btn_event) {
      *_btn = 1;
      if(btn_fcn) {
    	  btn_fcn();
        }
    } else if(*_btn && btn_event) {
      (*_btn)++;
    }
}

static void Toggle_LED(void) {
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}
/* USER CODE END 4 */
