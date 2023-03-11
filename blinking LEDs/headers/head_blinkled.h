#ifndef __HEAD_BLINKED_H__
#define __HEAD_BLINKED_H__


#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>


//-------
// MASKS
//-------

#define AHB_TO_PLL                              0b10U
#define AHB_PREDIV                              0b11U
#define REG_RCC_CFGR_START                0x00010000U
#define REG_RCC_CFGR_TO_APB             (0b111U << 8U)
#define SYSCLK_TO_PLLMUL                  (15U << 18U)


//--------
// CONSTS
//--------

#define HSI_SRC                             (1U << 15U)
#define REG_RCC_CFGR_SELECT_SYSCLK_SOURCE         0xCU
#define REG_RCC_CR_HSE_ON                   (1U << 17U) // the end meaning for oscillations to setup.
#define REG_RCC_CR_ENABLE_PLL_ON            (1U << 25U)



//----------------
// MACRO COMMANDS:
//----------------

#define WHILE_STATE_ESTABLISHMENT(reg, bit) while((*reg) & (bit) != (bit))
    

//------
// Main
//------

#define CPU_FREQENCY 48000000U  // CPU frequency: 48 MHz
#define ONE_MILLISECOND CPU_FREQENCY / 1000U


//-----------
// FUNCTIONS
//-----------

void board_clocking_init(void);
void board_gpio_init(void);
void delay_3000_time_delay_ms(void);

#endif
