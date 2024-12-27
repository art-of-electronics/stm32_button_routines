/** 
 * Project: F103_Buttons_HAL
 * 
 * @file btnFcn.h
 * 
 * @brief Headers for simple button handling
 * 
 * @author _art_of_electronics_
 * @date 2024.12.27
 * @version v1.0
 * 
 * @copyright 2024 _art_of_electronics_
*/

#pragma once 

/*****************************************************************************
                                    INCLUDES
*****************************************************************************/

#include <stdint.h>

#include "main.h"

/*****************************************************************************
                       PUBLIC DEFINES / MACROS / ENUMS
*****************************************************************************/


/*****************************************************************************
                         PUBLIC INTERFACE DECLARATION
*****************************************************************************/

/**@brief Routine for releasing button switch
 *
 * @param [in] btn - button switch counter variable
 * @param [in] GPIOx - port of GPIO button switch
 * @param [in] GPIO_Pin - pin of GPIO button switch
 * @param [in] BtnFcn - function to be executed on button release
 *
 * @return 0 while button pressed, 1 while button not pressed
 */
uint8_t BtnRelease(uint8_t *btn, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, void (*BtnFcn)(void));


/**@brief Routine for pressing button switch
 *
 * @param [in] btn - button switch counter variable
 * @param [in] GPIOx - port of GPIO button switch
 * @param [in] GPIO_Pin - pin of GPIO button switch
 * @param [in] BtnFcn - function to be executed on button press
 *
 * @return 0 while button pressed, 1 while button not pressed
 */
uint8_t BtnPress(uint8_t *btn, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, void (*BtnFcn)(void));

/******************************** END OF FILE *******************************/
