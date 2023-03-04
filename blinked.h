void board_clocking_init(void) {

    // (1) Clock HSE and wait for oscillations to setup.
    MODIFY_REG(*REG_RCC_CR, =,                CR_START);
    SET_MODE  (*REG_RCC_CR, CR_STAB,           CR_STAB);

    // (2) Configure PLL:
    // PREDIV output: HSE/2 = 4 MHz
    MODIFY_REG(*REG_RCC_CFGR2, |=,          AHB_PREDIV);

    // (3) Select PREDIV output as PLL input (4 MHz):
    MODIFY_REG(*REG_RCC_CFGR, |=,             CR_START);

    // (4) Set PLLMUL to 12:
    // SYSCLK frequency = 48 MHz
    MODIFY_REG(*REG_RCC_CFGR, |=,             PLLMUL12);

    // (5) Enable PLL:
    MODIFY_REG(*REG_RCC_CR, |=,              CR_START1);
    SET_MODE  (*REG_RCC_CR, CR_STAB,           CR_STAB);

    // (6) Configure AHB frequency to 48 MHz:
    MODIFY_REG(*REG_RCC_CFGR, |=,           AHB_PREDIV);

    // (7) Select PLL as SYSCLK source:
    MODIFY_REG(*REG_RCC_CFGR, |=,           AHB_TO_PLL);
    SET_MODE  (*REG_RCC_CFGR, CFGR_STAB_1, CFGR_STAB_2);

    // (8) Set APB frequency to 24 MHz
    MODIFY_REG(*REG_RCC_CFGR, |=,          CFGR_TO_APB);
}


void board_gpio_init(void) {

    // (1) Enable GPIOC clocking:
    MODIFY_REG(*REG_RCC_AHBENR, |=,       AHBENR_START);

    // (2) Configure PC8 & PC9 mode:
    MODIFY_REG(*GPIOC_MODER,    |=, CONFIGURE_PC8_MODE);
    MODIFY_REG(*GPIOC_MODER,    |=, CONFIGURE_PC9_MODE);

    // (3) Configure PC8 & PC9 type:
    MODIFY_REG(*GPIOC_TYPER,    |=, CONFIGURE_PC8_TYPE);
    MODIFY_REG(*GPIOC_TYPER,    |=, CONFIGURE_PC9_TYPE);
}

void delay_3000_1000ms(void) {

    uint32_t sec = 0;
    for (sec = 0; sec < 1000U * ONE_MILLISECOND; ++sec) {

        // Insert NOP for power consumption:
        __asm__ volatile("nop");
    }
}