#ifndef __FUNC_HEAD_BLINKED_H__
#define __FUNC_HEAD_BLINKED_H__


#include <stdint.h>
#include <stdbool.h>


//----------------
// CONSTS & MASKS
//----------------

#define AHB_TO_PLL                              0b10U
#define AHB_PREDIV                              0b11U
#define SYSCLK_TO_PLLMUL                   (15U << 18)


//----------------
// MACRO COMMANDS:
//----------------

#define BLINKINGDIODE(num)                                   \
        GPIO_BIT_SET_BLINKING_ON(GPIOC_PORT_BIT_SET,  num);  \
        TIMEDELAY(100);                                      \
        delay_3000_1000ms();                                 \
        GPIO_BIT_SET_BLINKING_OFF(GPIOC_PORT_BIT_SET, num);  \
        TIMEDELAY(100);                                      \
        delay_3000_1000ms();

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