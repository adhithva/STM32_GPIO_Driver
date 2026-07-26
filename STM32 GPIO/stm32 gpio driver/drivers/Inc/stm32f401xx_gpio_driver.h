/*
 * stm32f401xx_gpio_driver.h
 *
 *  Created on: Jul 25, 2026
 *      Author: abhij
 */

#ifndef STM32F401XX_GPIO_DRIVER_H
#define STM32F401XX_GPIO_DRIVER_H

#include "stm32f401xx.h"

/* GPIO Pin Configuration Structure */
typedef struct {
    uint8_t GPIO_PinNumber;       /* @GPIO_PIN_NUMBERS */
    uint8_t GPIO_PinMode;         /* @GPIO_PIN_MODES */
    uint8_t GPIO_PinSpeed;        /* @GPIO_PIN_SPEEDS */
    uint8_t GPIO_PinPuPdControl;  /* @GPIO_PIN_PUPD */
    uint8_t GPIO_PinOPType;       /* @GPIO_PIN_OP_TYPE */
    uint8_t GPIO_PinAltFunMode;
} GPIO_PinConfig_t;

/* GPIO Handle Structure */
typedef struct {
    GPIO_RegDef_t *pGPIOx;
    GPIO_PinConfig_t GPIO_PinConfig;
} GPIO_Handle_t;

/* @GPIO_PIN_NUMBERS */
#define GPIO_PIN_NO_0        0
#define GPIO_PIN_NO_5        5
#define GPIO_PIN_NO_6        6
#define GPIO_PIN_NO_7        7
#define GPIO_PIN_NO_13       13

/* @GPIO_PIN_MODES */
#define GPIO_MODE_IN         0
#define GPIO_MODE_OUT        1
#define GPIO_MODE_ALTFN      2
#define GPIO_MODE_ANALOG     3

/* @GPIO_PIN_OP_TYPE */
#define GPIO_OP_TYPE_PP      0
#define GPIO_OP_TYPE_OD      1

/* @GPIO_PIN_SPEEDS */
#define GPIO_SPEED_LOW       0
#define GPIO_SPEED_MEDIUM    1
#define GPIO_SPEED_FAST      2
#define GPIO_SPEED_HIGH      3

/* @GPIO_PIN_PUPD */
#define GPIO_NO_PUPD         0
#define GPIO_PIN_PU          1
#define GPIO_PIN_PD          2

/* Driver APIs Supported Functions */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnOrDi);
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

#endif /* STM32F401XX_GPIO_DRIVER_H */
