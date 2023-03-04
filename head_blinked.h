#ifndef __FUNC_H__
#define __FUNC_H__


#include <stdint.h>
#include <stdbool.h>


//-------
// MASKS
//-------

#define MASK8_ON       1 << 8
#define MASK9_ON       1 << 9
#define MASK8_OFF ~(MASK8_ON)
#define MASK9_OFF ~(MASK9_ON)


//---------------
// RCC Registers
//---------------

#define REG_RCC_CR      (volatile uint32_t * )(uintptr_t)0x40021000U // Clock Control Register
#define REG_RCC_CFGR    (volatile uint32_t * )(uintptr_t)0x40021004U // PLL Configuration Register
#define REG_RCC_AHBENR  (volatile uint32_t * )(uintptr_t)0x40021014U // AHB1 Peripheral Clock Enable Register
#define REG_RCC_CFGR2   (volatile uint32_t * )(uintptr_t)0x4002102CU // Clock configuration register 2
#define SET_PIN        *(volatile uint32_t * )(uintptr_t)0x48000814U


//----------------
// GPIO Registers
//----------------

#define GPIOC_MODER (volatile uint32_t * )(uintptr_t)0x48000800U // GPIO port mode register
#define GPIOC_TYPER (volatile uint32_t * )(uintptr_t)0x48000804U // GPIO port output type register


//----------------
// MACRO COMMANDS:
//----------------

#define TIMEDELAY(time) for (int i = 0; i < time * 1000; i++);

#define MODIFY_REG(reg, modifymask, value)          \
        reg modifymask value

#define BLINKINGDIODE(num)                          \
        MODIFY_REG(SET_PIN, |=, MASK##num##_ON);    \
        TIMEDELAY(100)                              \
        delay_3000_1000ms();                        \
        MODIFY_REG(SET_PIN, &=, MASK##num##_OFF);   \
        TIMEDELAY(100)                              \
        delay_3000_1000ms();

#define SET_MODE(reg, bit, endstate)                \
        while(MODIFY_REG(reg, &, bit) != endstate);

//--------
// CONSTS:
//--------

#define AHB_TO_PLL                      0b10U
#define AHB_PREDIV               0b000U << 4U
#define AHBENR_START                 0x80000U
#define CONFIGURE_PC8_MODE 0b01U   << (2 * 8U)
#define CONFIGURE_PC9_MODE 0b01U   << (2 * 9U)
#define CONFIGURE_PC8_TYPE         0b0U << 8U
#define CONFIGURE_PC9_TYPE         0b0U << 9U 
#define CR_START                  0x00010000U
#define CR_STAB                   0x00020000U
#define CR_STAB1                  0x02000000U
#define CFGR_STAB_1                      0xCU
#define CFGR_STAB_2                      0x8U
#define CFGR_TO_APB              0b001U << 8U
#define CR_START1                 0x01000000U
#define PLL_DEVIDER                        1U
#define PLLMUL12              (12U-2U) << 18U
    

//------
// Main
//------

#define CPU_FREQENCY 48000000U // CPU frequency: 48 MHz
#define ONE_MILLISECOND CPU_FREQENCY / 1000U


void board_clocking_init(void);
void board_gpio_init(void);
void delay_3000_1000ms(void);

#endif