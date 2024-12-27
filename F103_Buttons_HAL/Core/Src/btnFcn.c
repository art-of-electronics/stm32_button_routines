/**
 * Project: F103_Buttons_HAL
 * 
 * @file btnFcn.c
 * 
 * @brief Nonblocking routines for simple button handling
 * 
 * @author _art_of_electronics_
 * @date 2024.12.27
 * @version v1.0
 * 
 * @copyright 2024 _art_of_electronics_
*/

/*****************************************************************************
                                    INCLUDES
*****************************************************************************/

#include "btnFcn.h"

/*****************************************************************************
                          PRIVATE DEFINES / MACROS
*****************************************************************************/


/*****************************************************************************
                     PRIVATE STRUCTS / ENUMS / VARIABLES
*****************************************************************************/


/*****************************************************************************
                         PRIVATE FUNCTION DECLARATION
*****************************************************************************/


/*****************************************************************************
                           INTERFACE IMPLEMENTATION
*****************************************************************************/

uint8_t BtnRelease(uint8_t *btn, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, void (*BtnFcn)(void))
{
  uint8_t btnEvent = HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);

  if (!*btn && !btnEvent)
  {
    *btn = 1;
  }
  else if (*btn && btnEvent)
  {
    if (!++*btn)
    {
      if (BtnFcn)
      {
        BtnFcn();
      }
    }
  }
  return btnEvent;
}


uint8_t BtnPress(uint8_t *btn, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, void (*BtnFcn)(void))
{
  uint8_t btnEvent = HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);

  if (!(*btn) && !btnEvent)
  {
    *btn = 1;

    if (BtnFcn)
    {
      BtnFcn();
    }
  }
  else if ((*btn) && btnEvent)
  {
    (*btn)++;
  }
  return btnEvent;
}

/*****************************************************************************
                        PRIVATE FUNCTION IMPLEMENTATION
*****************************************************************************/


/******************************** END OF FILE *******************************/
