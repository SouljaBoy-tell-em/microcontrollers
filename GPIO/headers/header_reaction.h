#ifndef __HEADER_REACTION_H__
#define __HEADER_REACTION_H__


#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>


//-------
// MASKS
//-------

#define AHB_TO_PLL                                                       0b10U
#define AHB_PREDIV                                                       0b11U
#define GPIOA_MODER_CONFIGURATE_MASK                                0x1555554U
#define PA0_CONFIGURATE_MASK                                             0b11U
#define REG_RCC_AHBENR_PA1_PA12_OUTPUT_MASK                          (1 << 17U)
#define REG_RCC_CFGR_START                                         0x00010000U
#define REG_RCC_CFGR_TO_APB                                      (0b111U << 8U)
#define REG_RCC_CFGR_STAB1                                                0xCU
#define REG_RCC_CR_STAB1                                            (1U << 25U)
#define SYSCLK_TO_PLLMUL                                           (15U << 18U)


//--------
// CONSTS
//--------

#define GPIOA_CONFIGURATE_MODE_VALUE         0x1555554U
#define HSI_SRC                              (1U << 15U)
#define PULL_DOWN                                 0b10U
#define REG_RCC_AHBENR_PA1_PA12_OUTPUT_VALUE   0x20000U
#define REG_RCC_CR_STAB                      (1U << 17U) // the end value for oscillations to setup.
#define DEBOUNCE_END_VALUE                           5U
#define UPLIMIT                                   9999U


#define CPU_FREQENCY 48000000U // CPU frequency: 48 MHz
#define ONE_MILLISECOND CPU_FREQENCY/1000U


//--------
// MACROS
//--------

#define WHILE_STATE_ESTABLISHMENT(reg, bit) while((((*reg)) & (bit)) != (bit))


#define TURN_ON_CONTACT_DEBOUNCER(active, saturation, button_was_pressed) \
        if (active) {                                                     \
            if (saturation < DEBOUNCE_END_VALUE)                          \
                saturation += 1U;                                         \
            else                                                          \
                button_was_pressed = 1U;                                  \
        }                                                                 \
        else                                                              \
            saturation = 0U

//---------------------
// FUNCTION PROTOTYPES
//---------------------

void board_clocking_init(void);
void board_gpio_init(void);
void to_get_more_accuracy_pay(void);

#endif
