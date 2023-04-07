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

#define GPIOC_PORT_BIT_SET (volatile uint32_t * )(uintptr_t)0x48000818U // GPIO set or reset register


//--------
// MACROS
//--------

#define GPIO_BIT_SET_BLINKING_OFF(reg, bit) (SET_BIT_ON(reg, (bit + 16))) // reactivate bit, that makes to blink diode
#define GPIO_BIT_SET_BLINKING_ON(reg, bit) (SET_BIT_ON(reg, bit)) // activate bit, that makes to blink diode
#define GPIO_IDR_GET_VALUE_PA0_INPUT(active, reg, bit) (active) = (*(reg)) & (1 << (bit))
#define GPIO_MODER_CONFIGURATE_PA0_BUTTON(reg, bit) MODIFY_REG((reg), PA0_CONFIGURATE_MASK, bit)
#define GPIO_MODER_CONFIGURATE(reg, bit) MODIFY_REG((reg), GPIOA_MODER_CONFIGURATE_MASK, bit)
#define GPIO_ODR_SET_VALUE_TO_SEGMENT(reg, bit) MODIFY_REG((reg), PINS_USED, bit)
#define GPIO_PUPDR_CONFIGURATE_PA0_MODE(reg, bit) \
        MODIFY_REG((reg), PA0_CONFIGURATE_MASK, bit)     
                                                        // 0 - PULL_NO;
                                                        // 1 - PULL_UP;
                                                        // 2 - PULL_DOWN;
                                                        // 3 - RESERVED;
#define GPIO_MODER_SET(reg, bit) (SET_BIT_ON((reg), 2 * (bit)))
#define GPIO_TYPER_SET(reg, bit) ((*reg) = (bit))

#endif