#ifndef __GPIO_H__
#define __GPIO_H__


//----------------
// GPIO Registers
//----------------

#define GPIOA_MODER (volatile uint32_t*)(uintptr_t)0x48000000U // GPIO port mode register
#define GPIOA_TYPER (volatile uint32_t*)(uintptr_t)0x48000004U // GPIO port output type register
#define GPIOA_PUPDR (volatile uint32_t*)(uintptr_t)0x4800000CU // GPIO port pull-up/pull-down register
#define GPIOA_IDR   (volatile uint32_t*)(uintptr_t)0x48000010U // GPIO port input  data register
#define GPIOA_ODR   (volatile uint32_t*)(uintptr_t)0x48000014U // GPIO port output data register

#define GPIOC_MODER (volatile uint32_t*)(uintptr_t)0x48000800U // GPIO port mode register
#define GPIOC_TYPER (volatile uint32_t*)(uintptr_t)0x48000804U // GPIO port output type register


//--------
// MACROS
//--------

#define GPIOA_IDR_GET_VALUE_PA0_INPUT(active, reg, bit) (active) = (*(reg)) & (1 << (bit))
#define GPIOA_MODER_CONFIGURATE_PA0_BUTTON(reg, bit) MODIFY_REG((reg), PA0_CONFIGURATE_MASK, bit)
#define GPIOA_MODER_SET(reg, bit) MODIFY_REG((reg), GPIOA_MODER_CONFIGURATE_MASK, bit)
#define GPIOA_ODR_SET_VALUE_TO_SEGMENT(reg, bit) MODIFY_REG((reg), PINS_USED, bit)
#define GPIOA_PUPDR_CONFIGURATE_PA0_MODE(reg, bit) \
        MODIFY_REG((reg), PA0_CONFIGURATE_MASK, bit)     
                                                        // 0 - PULL_NO;
                                                        // 1 - PULL_UP;
                                                        // 2 - PULL_DOWN;
                                                        // 3 - RESERVED;
#define GPIOA_TYPER_SET(reg, bit) ((*reg) = (bit))

#endif