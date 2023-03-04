#ifndef __FUNC_H__
#define __FUNC_H__


#include <stdint.h>
#include <stdbool.h>


//----------------
// CONSTS & MASKS
//----------------

#define AHB_TO_PLL                              0b10U
#define AHB_PREDIV                              0b11U
#define HSI_SRC                             (1U << 15)
#define REG_RCC_CFGR_START                0x00010000U
#define REG_RCC_CR_STAB                     (1U << 17)
#define REG_RCC_CR_STAB1                    (1U << 25)
#define REG_RCC_CFGR_STAB_1                      0xCU
#define REG_RCC_CFGR_TO_APB             (0b111U << 8U)
#define SYSCLK_TO_PLLMUL                   (15U << 18)


//---------------
// RCC Registers
//---------------

#define REG_RCC_CR      (volatile uint32_t * )(uintptr_t)0x40021000U // Clock Control Register
#define REG_RCC_CFGR    (volatile uint32_t * )(uintptr_t)0x40021004U // PLL Configuration Register
#define REG_RCC_AHBENR  (volatile uint32_t * )(uintptr_t)0x40021014U // AHB1 Peripheral Clock Enable Register
#define REG_RCC_CFGR2   (volatile uint32_t * )(uintptr_t)0x4002102CU // Clock configuration register 2
#define SET_PIN_ON      (volatile uint32_t * )(uintptr_t)0x48000814U
#define SET_PIN_RESET   (volatile uint32_t * )(uintptr_t)0x48000818U


//----------------
// GPIO Registers
//----------------

#define GPIOC_MODER (volatile uint32_t * )(uintptr_t)0x48000800U // GPIO port mode register
#define GPIOC_TYPER (volatile uint32_t * )(uintptr_t)0x48000804U // GPIO port output type register


//----------------
// MACRO COMMANDS:
//----------------

#define BLINKINGDIODE(num)                              \
        GPIO_BIT_SET_BLINKING_ON(SET_PIN_RESET, num);   \
        TIMEDELAY(100);                                 \
        delay_3000_1000ms();                            \
        GPIO_BIT_SET_BLINKING_OFF(SET_PIN_RESET, num);  \
        TIMEDELAY(100);                                 \
        delay_3000_1000ms();

#define GPIO_BIT_SET_BLINKING_OFF(reg, bit) (SET_BIT_ON(reg, (bit + 16)))
#define GPIO_BIT_SET_BLINKING_ON(reg, bit) (SET_BIT_ON(reg, bit))
#define GPIOC_MODER_SET(reg, bit) (SET_BIT_ON((reg), 2 * (bit)))
#define GPIOC_TYPER_SET(reg, bit) (SET_BIT_OFF((reg), (bit)))
#define MODIFY_REG(reg, modifymask, value) (*(reg) = ((*(reg) & (~(modifymask))) | (value & modifymask)))
#define REG_RCC_CR_CLOCK_HSE_ON(reg) (SET_BIT_ON(reg, 16U))
#define REG_RCC_CFGR2_CONFIGURATE_PLL(reg, div) (MODIFY_REG((reg), AHB_PREDIV, ((div) - 1))) 
#define REG_RCC_CFGR_SELECT_PLL_DIV(reg, div) (MODIFY_REG((reg), REG_RCC_CFGR_START, div))
#define REG_RCC_CFGR_SELECT_PLL_MUL(reg, mul) (MODIFY_REG((reg), SYSCLK_TO_PLLMUL, ((mul) - 2U) << 18))
#define REG_RCC_CR_ENABLE_PLL(reg) (SET_BIT_ON((reg), 24))
#define REG_RCC_CFGR_CONFIGURATE_AHB(reg, bit) (MODIFY_REG((reg), AHB_PREDIV, (bit) << 4))
#define REG_RCC_CFGR_SELECT_PLL_SYSCLK(reg, bit) (MODIFY_REG((reg), AHB_PREDIV, (bit)))
#define REG_RCC_CFGR_SET_APB_FREQ(reg) (MODIFY_REG((reg), REG_RCC_CFGR_TO_APB, (0b100 << 8)))
#define REG_RCC_AHBENR_ENABLE_GPIOC(reg) (SET_BIT_ON((reg), 19))
#define SET_BIT_ON(reg, bit)  (*(reg) |= 1U << (bit))
#define SET_BIT_OFF(reg, bit) (*(reg) &= (~(1U << (bit))))
#define SETTING_STATE(reg, bit) while((*reg) & bit != bit);
#define TIMEDELAY(time) for (int i = 0; i < time * 1000; i++)
    

//------
// Main
//------

#define CPU_FREQENCY 48000000U // CPU frequency: 48 MHz
#define ONE_MILLISECOND CPU_FREQENCY / 1000U


void board_clocking_init(void);
void board_gpio_init(void);
void delay_3000_1000ms(void);

#endif
