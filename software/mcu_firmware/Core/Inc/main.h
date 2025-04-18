/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ADC_VOUT_Pin GPIO_PIN_2
#define ADC_VOUT_GPIO_Port GPIOA
#define TIM_BUZZER_Pin GPIO_PIN_5
#define TIM_BUZZER_GPIO_Port GPIOA
#define ADC_VIN_Pin GPIO_PIN_6
#define ADC_VIN_GPIO_Port GPIOA
#define GPIO_LOAD1_Pin GPIO_PIN_7
#define GPIO_LOAD1_GPIO_Port GPIOA
#define GPIO_LOAD2_Pin GPIO_PIN_0
#define GPIO_LOAD2_GPIO_Port GPIOB
#define GPIO_BUCK_DISABLE_Pin GPIO_PIN_15
#define GPIO_BUCK_DISABLE_GPIO_Port GPIOA
#define GPIO_FB_DIVIDER_ADD_Pin GPIO_PIN_3
#define GPIO_FB_DIVIDER_ADD_GPIO_Port GPIOB
#define GPIO_BTN_L1_Pin GPIO_PIN_6
#define GPIO_BTN_L1_GPIO_Port GPIOB
#define GPIO_BTN_L2_Pin GPIO_PIN_7
#define GPIO_BTN_L2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
