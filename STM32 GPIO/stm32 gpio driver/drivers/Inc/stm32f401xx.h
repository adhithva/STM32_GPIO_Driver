/*
 * stm32f401xx.h
 *
 *  Created on: Jul 25, 2026
 *      Author: abhij
 */

#ifndef STM32F401XX_H
#define STM32F401XX_H

#include <stdint.h>

#define __vo volatile

/* Base addresses of Flash and SRAM */
#define FLASH_BASEADDR      0x08000000UL
#define SRAM1_BASEADDR      0x20000000UL
#define ROM_BASEADDR        0x1FFF0000UL

/* AHB1 Peripheral Base Addresses */
#define PERIPH_BASE         0x40000000UL
#define AHB1PERIPH_BASE     (PERIPH_BASE + 0x00020000UL)

#define GPIOA_BASEADDR      (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASEADDR      (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASEADDR      (AHB1PERIPH_BASE + 0x0800UL)
#define RCC_BASEADDR        (AHB1PERIPH_BASE + 0x3800UL)

/* GPIO Register Map Structure */
typedef struct {
    __vo uint32_t MODER;    /* GPIO port mode register */
    __vo uint32_t OTYPER;   /* GPIO port output type register */
    __vo uint32_t OSPEEDR;  /* GPIO port output speed register */
    __vo uint32_t PUPDR;    /* GPIO port pull-up/pull-down register */
    __vo uint32_t IDR;      /* GPIO port input data register */
    __vo uint32_t ODR;      /* GPIO port output data register */
    __vo uint32_t BSRR;     /* GPIO port bit set/reset register */
    __vo uint32_t LCKR;     /* GPIO port configuration lock register */
    __vo uint32_t AFR[2];   /* GPIO alternate function registers [0]: low, [1]: high */
} GPIO_RegDef_t;

/* RCC Register Map Structure */
typedef struct {
    __vo uint32_t CR;
    __vo uint32_t PLLCFGR;
    __vo uint32_t CFGR;
    __vo uint32_t CIR;
    __vo uint32_t AHB1RSTR;
    __vo uint32_t AHB2RSTR;
    uint32_t      DUMMY[2];
    __vo uint32_t APB1RSTR;
    __vo uint32_t APB2RSTR;
    uint32_t      DUMMY1[2];
    __vo uint32_t AHB1ENR;
    __vo uint32_t AHB2ENR;
    uint32_t      DUMMY2[2];
    __vo uint32_t APB1ENR;
    __vo uint32_t APB2ENR;
} RCC_RegDef_t;

/* Peripheral Definitions */
#define GPIOA               ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB               ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC               ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define RCC                 ((RCC_RegDef_t*)RCC_BASEADDR)

/* Clock Enable Macros for GPIO Peripherals */
#define GPIOA_PCLK_EN()     (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()     (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()     (RCC->AHB1ENR |= (1 << 2))

/* Generic Macros */
#define ENABLE              1
#define DISABLE             0
#define SET                 ENABLE
#define RESET               DISABLE
#define GPIO_PIN_SET        SET
#define GPIO_PIN_RESET      RESET

#endif /* STM32F401XX_H */
