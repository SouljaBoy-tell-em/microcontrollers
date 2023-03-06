#ifndef __GPIO_H__
#define __GPIO_H__


//----------------
// GPIO Registers
//----------------

#define GPIOC_MODER        (volatile uint32_t * )(uintptr_t)0x48000800U // GPIO port mode register
#define GPIOC_TYPER        (volatile uint32_t * )(uintptr_t)0x48000804U // GPIO port output type register
#define GPIOC_PORT_OUT     (volatile uint32_t * )(uintptr_t)0x48000814U // GPIO port OUTPUT register
#define GPIOC_PORT_BIT_SET (volatile uint32_t * )(uintptr_t)0x48000818U // GPIO set or reset register


//--------
// MACROS
//--------

#define GPIO_BIT_SET_BLINKING_OFF(reg, bit) (SET_BIT_ON(reg, (bit + 16))) // reactivate bit, that makes to blink diode
#define GPIO_BIT_SET_BLINKING_ON(reg, bit) (SET_BIT_ON(reg, bit)) // activate bit, that makes to blink diode
#define GPIOC_MODER_SET(reg, bit) (SET_BIT_ON((reg), 2 * (bit)))
#define GPIOC_TYPER_SET(reg, bit) (SET_BIT_OFF((reg), (bit)))

#endif