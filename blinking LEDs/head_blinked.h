#ifndef __HEAD_BLINKED_H__
#define __HEAD_BLINKED_H__


#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>


//------------------
// MASKS AND CONSTS
//------------------

#define AHB_TO_PLL                              0b10U
#define AHB_PREDIV                              0b11U
#define REG_RCC_CFGR_START                0x00010000U
#define REG_RCC_CR_STAB1                    (1U << 25)
#define REG_RCC_CFGR_STAB_1                      0xCU
#define REG_RCC_CFGR_TO_APB             (0b111U << 8U)
#define SYSCLK_TO_PLLMUL                   (15U << 18)


//--------
// CONSTS
//--------

#define HSI_SRC                             (1U << 15)
#define REG_RCC_CR_STAB                     (1U << 17) // the end meaning for oscillations to setup.



//----------------
// MACRO COMMANDS:
//----------------

#define WHILE_STATE_ESTABLISHMENT(reg, bit) while((*reg) & bit != bit);
    

//------
// Main
//------

#define CPU_FREQENCY 48000000U  // CPU frequency: 48 MHz
#define TIME_DELAY        100U   // delay between blinkings diodes
#define ONE_MILLISECOND CPU_FREQENCY / TIME_DELAY


void board_clocking_init(void);
void board_gpio_init(void);
void delay_3000_time_delay_ms(void);

#endif
