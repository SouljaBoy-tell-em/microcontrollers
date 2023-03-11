//---------------
// RCC Registers
//---------------

#define REG_RCC_CR      (volatile uint32_t * )(uintptr_t)0x40021000U // Clock Control Register
#define REG_RCC_CFGR    (volatile uint32_t * )(uintptr_t)0x40021004U // PLL Configuration Register
#define REG_RCC_AHBENR  (volatile uint32_t * )(uintptr_t)0x40021014U // AHB1 Peripheral Clock Enable Register
#define REG_RCC_CFGR2   (volatile uint32_t * )(uintptr_t)0x4002102CU // Clock configuration register 2


//--------
// MACROS
//--------

#define REG_RCC_CR_CLOCK_HSE_ON(reg) (SET_BIT_ON(reg, 16U))
#define REG_RCC_CFGR2_CONFIGURATE_PLL(reg, div) (MODIFY_REG((reg), AHB_PREDIV, ((div) - 1))) 
#define REG_RCC_CFGR_SELECT_PLL_DIV(reg, div) (MODIFY_REG((reg), REG_RCC_CFGR_START, div))
#define REG_RCC_CFGR_SELECT_PLL_MUL(reg, mul) (MODIFY_REG((reg), SYSCLK_TO_PLLMUL, ((mul) - 2U) << 18))
#define REG_RCC_CR_ENABLE_PLL(reg) (SET_BIT_ON((reg), 24))
#define REG_RCC_CFGR_CONFIGURATE_AHB(reg, bit) (MODIFY_REG((reg), AHB_PREDIV, (bit) << 4))
#define REG_RCC_CFGR_SELECT_PLL_SYSCLK(reg, bit) (MODIFY_REG((reg), AHB_PREDIV, (bit)))
#define REG_RCC_CFGR_SET_APB_FREQ(reg) (MODIFY_REG((reg), REG_RCC_CFGR_TO_APB, (0b100 << 8)))