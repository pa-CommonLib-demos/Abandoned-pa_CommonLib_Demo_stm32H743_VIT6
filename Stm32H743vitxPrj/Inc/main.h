/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
#include "stm32h7xx_hal.h"

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
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define stepperMs1_Pin GPIO_PIN_2
#define stepperMs1_GPIO_Port GPIOE
#define stepperMs2_Pin GPIO_PIN_3
#define stepperMs2_GPIO_Port GPIOE
#define stepperMs3_Pin GPIO_PIN_4
#define stepperMs3_GPIO_Port GPIOE
#define leftArmLimit_Pin GPIO_PIN_5
#define leftArmLimit_GPIO_Port GPIOE
#define rightArmLimit_Pin GPIO_PIN_6
#define rightArmLimit_GPIO_Port GPIOE
#define AS5048_CS_Pin GPIO_PIN_0
#define AS5048_CS_GPIO_Port GPIOC
#define robotStepper_En_2_Pin GPIO_PIN_12
#define robotStepper_En_2_GPIO_Port GPIOC
#define robotStepper_Step_0_Pin GPIO_PIN_0
#define robotStepper_Step_0_GPIO_Port GPIOD
#define robotStepper_Step_1_Pin GPIO_PIN_1
#define robotStepper_Step_1_GPIO_Port GPIOD
#define robotStepper_Step_2_Pin GPIO_PIN_2
#define robotStepper_Step_2_GPIO_Port GPIOD
#define robotStepper_Dir_0_Pin GPIO_PIN_3
#define robotStepper_Dir_0_GPIO_Port GPIOD
#define robotStepper_Dir_1_Pin GPIO_PIN_4
#define robotStepper_Dir_1_GPIO_Port GPIOD
#define robotStepper_Dir_2_Pin GPIO_PIN_5
#define robotStepper_Dir_2_GPIO_Port GPIOD
#define robotStepper_En_0_Pin GPIO_PIN_6
#define robotStepper_En_0_GPIO_Port GPIOD
#define robotStepper_En_1_Pin GPIO_PIN_7
#define robotStepper_En_1_GPIO_Port GPIOD
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
