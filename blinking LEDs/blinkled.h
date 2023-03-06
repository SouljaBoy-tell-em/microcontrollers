#ifndef __BLINKLED_H__
#define __BLINKLED_H__


void board_clocking_init(void) {

    // (1) Clock HSE and wait for oscillations to setup.
    REG_RCC_CR_CLOCK_HSE_ON(REG_RCC_CR);
    WHILE_STATE_ESTABLISHMENT(REG_RCC_CR, REG_RCC_CR_STAB);

    // (2) Configure PLL:
    // PREDIV output: HSE/2 = 4 MHz
    REG_RCC_CFGR2_CONFIGURATE_PLL(REG_RCC_CFGR2, 2U);

    // (3) Select PREDIV output as PLL input (4 MHz):
    REG_RCC_CFGR_SELECT_PLL_DIV(REG_RCC_CFGR, HSI_SRC);

    // (4) Set PLLMUL to 12:
    // SYSCLK frequency = 48 MHz
    REG_RCC_CFGR_SELECT_PLL_MUL(REG_RCC_CFGR, 12);

    // (5) Enable PLL:
    REG_RCC_CR_ENABLE_PLL(REG_RCC_CR);
    WHILE_STATE_ESTABLISHMENT(REG_RCC_CR, REG_RCC_CR_STAB1);

    // (6) Configure AHB frequency to 48 MHz:
    REG_RCC_CFGR_CONFIGURATE_AHB(REG_RCC_CFGR, 0);

    // (7) Select PLL as SYSCLK source:
    REG_RCC_CFGR_SELECT_PLL_SYSCLK(REG_RCC_CFGR, AHB_TO_PLL);
    WHILE_STATE_ESTABLISHMENT(REG_RCC_CFGR, REG_RCC_CFGR_STAB_1);

    // (8) Set APB frequency to 24 MHz
    REG_RCC_CFGR_SET_APB_FREQ(REG_RCC_CFGR);
}


void board_gpio_init(void) {

    // (1) Enable GPIOC clocking:
    SET_BIT_ON(REG_RCC_AHBENR,  19);

    // (2) Configure PC8 & PC9 mode:
    GPIOC_MODER_SET(GPIOC_MODER, 8);
    GPIOC_MODER_SET(GPIOC_MODER, 9);

    // (3) Configure PC8 & PC9 type:
    GPIOC_TYPER_SET(GPIOC_TYPER, 8);
    GPIOC_TYPER_SET(GPIOC_TYPER, 9);
}

void delay_3000_time_delay_ms(void) {

    uint32_t sec = 0;
    for (sec = 0; sec < 1000U * ONE_MILLISECOND; ++sec) {

        // Insert NOP for power consumption:
        __asm__ volatile("nop");
    }
}


#endif
