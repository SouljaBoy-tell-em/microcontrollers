#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

//---------------
// RCC Registers
//---------------

#define REG_RCC_CR     (volatile uint32_t*)(uintptr_t)0x40021000U // Clock Control Register
#define REG_RCC_CFGR   (volatile uint32_t*)(uintptr_t)0x40021004U // PLL Configuration Register
#define REG_RCC_AHBENR (volatile uint32_t*)(uintptr_t)0x40021014U // AHB1 Peripheral Clock Enable Register
#define REG_RCC_CFGR2  (volatile uint32_t*)(uintptr_t)0x4002102CU // Clock configuration register 2

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

//-------------------
// 7-segment display
//-------------------

// SUPER-DUPER TRUSTWORTHY Pin Mapping:
#define A  0x0800U
#define B  0x0080U
#define C  0x0010U
#define D  0x0004U
#define E  0x0002U
#define F  0x0400U
#define G  0x0020U
#define DP 0x0008U

#define POS0 0x0040U
#define POS1 0x0100U
#define POS2 0x0200U
#define POS3 0x1000U



//-------
// MASKS
//-------

#define AHB_TO_PLL                               0b10U
#define AHB_PREDIV                               0b11U
#define GPIOA_MODER_CONFIGURATE_MASK        0x1555554U
#define PA0_CONFIGURATE_MASK                     0b11U
#define REG_RCC_AHBENR_PA1_PA12_OUTPUT_MASK   (1 << 17)
#define REG_RCC_CFGR_START                 0x00010000U
#define REG_RCC_CFGR_TO_APB              (0b111U << 8U)
#define REG_RCC_CFGR_STAB1                        0xCU
#define REG_RCC_CR_STAB1                    (1U << 25U)
#define SYSCLK_TO_PLLMUL                   (15U << 18U)


//--------
// CONSTS
//--------

#define GPIOA_CONFIGURATE_MODE_VALUE         0x1555554U
#define HSI_SRC                              (1U << 15U)
#define PULL_DOWN                                 0b10U
#define REG_RCC_AHBENR_PA1_PA12_OUTPUT_VALUE    0x20000
#define REG_RCC_CR_STAB                      (1U << 17U) // the end meaning for oscillations to setup.


//--------
// MACROS
//--------

#define WHILE_STATE_ESTABLISHMENT(reg, bit) while((((*reg)) & (bit)) != (bit))

#define SET_BIT_ON(reg, bit)  (*(reg) |= 1U << (bit))       // set bit in register to 1

#define MODIFY_REG(reg, modifymask, value) \
        (*(reg) = ((*(reg) & (~(modifymask))) | (value & modifymask)))

#define REG_RCC_AHBENR_CONFIGURATE_PA1_PA12_OUTPUT(reg, bit) \
        MODIFY_REG((reg), REG_RCC_AHBENR_PA1_PA12_OUTPUT_MASK, bit)

#define GPIOA_MODER_SET(reg, bit) \
        MODIFY_REG((reg), GPIOA_MODER_CONFIGURATE_MASK, bit)

#define GPIOA_TYPER_SET(reg, bit) ((*reg) = (bit))

#define GPIOA_MODER_CONFIGURATE_PA0_BUTTON(reg, bit) \
        MODIFY_REG((reg), PA0_CONFIGURATE_MASK, bit)

#define GPIOA_PUPDR_CONFIGURATE_PA0_MODE(reg, bit) \
        MODIFY_REG((reg), PA0_CONFIGURATE_MASK, bit)     
                                                        // 0 - PULL_NO;
                                                        // 1 - PULL_UP;
                                                        // 2 - PULL_DOWN;
                                                        // 3 - RESERVED;

#define REG_RCC_CR_CLOCK_HSE_ON(reg) (SET_BIT_ON(reg, 16U))
#define REG_RCC_CFGR2_CONFIGURATE_PLL(reg, div) (MODIFY_REG((reg), AHB_PREDIV, ((div) - 1))) 
#define REG_RCC_CFGR_SELECT_PLL_DIV(reg, div) (MODIFY_REG((reg), REG_RCC_CFGR_START, div))
#define REG_RCC_CFGR_SELECT_PLL_MUL(reg, mul) (MODIFY_REG((reg), SYSCLK_TO_PLLMUL, ((mul) - 2U) << 18))
#define REG_RCC_CR_ENABLE_PLL(reg) (SET_BIT_ON((reg), 24))
#define REG_RCC_CFGR_CONFIGURATE_AHB(reg, bit) (MODIFY_REG((reg), AHB_PREDIV, (bit) << 4))
#define REG_RCC_CFGR_SELECT_PLL_SYSCLK(reg, bit) (MODIFY_REG((reg), AHB_PREDIV, (bit)))
#define REG_RCC_CFGR_SET_APB_FREQ(reg) (MODIFY_REG((reg), REG_RCC_CFGR_TO_APB, (0b100 << 8)))


static const uint32_t PINS_USED = A|B|C|D|E|F|G|DP|POS0|POS1|POS2|POS3;

// TOTALLY CORRECT digit composition:
static const uint32_t DIGITS[10] =
{
    A|B|C|D|E|F,   // 0
    B|C,           // 1
    A|C|D|F|G,     // 2
    A|B|C|D|G,     // 3
    B|C|F|G,       // 4
    A|B|D|E|G,     // 5
    A|C|D|E|F|G,   // 6
    A|B|C,         // 7
    A|B|C|D|E|F|G, // 8
    A|B|C|D|F|G    // 9
};

static const uint32_t POSITIONS[4] =
{
         POS1|POS2|POS3, // 0
    POS0     |POS2|POS3, // 1
    POS0|POS1     |POS3, // 2
    POS0|POS1|POS2       // 3
};

// Display state:
struct Seg7Display
{
    uint32_t display;
    uint16_t number;
};

void SEG7_set_number_quarter(struct Seg7Display* seg7, unsigned tick)
{
    uint32_t divisors[4] = {1, 10, 100, 1000};

    unsigned quarter = tick % 4;
    unsigned divisor = divisors[quarter];

    seg7->display = DIGITS[(seg7->number / divisor) % 10] | POSITIONS[quarter];
}

// Write changes to microcontroller:
void SEG7_push_display_state_to_mc(struct Seg7Display* seg7)
{
    uint32_t surrounding_state = ~PINS_USED & *GPIOA_ODR;
    uint32_t to_write = PINS_USED & seg7->display;

    *GPIOA_ODR = surrounding_state | to_write;
}

//-------------------
// RCC configuration
//-------------------

#define CPU_FREQENCY 48000000U // CPU frequency: 48 MHz
#define ONE_MILLISECOND CPU_FREQENCY/1000U

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
    //WHILE_STATE_ESTABLISHMENT(REG_RCC_CR, REG_RCC_CR_STAB1);

    // (6) Configure AHB frequency to 48 MHz:
    REG_RCC_CFGR_CONFIGURATE_AHB(REG_RCC_CFGR, 0);

    // (7) Select PLL as SYSCLK source:
    REG_RCC_CFGR_SELECT_PLL_SYSCLK(REG_RCC_CFGR, AHB_TO_PLL);
    //WHILE_STATE_ESTABLISHMENT(REG_RCC_CFGR, REG_RCC_CFGR_STAB1);

    // (8) Set APB frequency to 24 MHz
    REG_RCC_CFGR_SET_APB_FREQ(REG_RCC_CFGR);
}

void to_get_more_accuracy_pay_2202_2013_2410_3805_1ms() {
    
    for (uint32_t i = 0; i < ONE_MILLISECOND/3U; ++i) {
        // Insert NOP for power consumption:
        __asm__ volatile("nop");
    }
}

//--------------------
// GPIO configuration
//--------------------

void board_gpio_init() {

    // (1) Configure PA1-PA12 as output:
    REG_RCC_AHBENR_CONFIGURATE_PA1_PA12_OUTPUT(REG_RCC_AHBENR, REG_RCC_AHBENR_PA1_PA12_OUTPUT_VALUE);

    // Configure mode register:
    GPIOA_MODER_SET(GPIOA_MODER, GPIOA_CONFIGURATE_MODE_VALUE);

    // Configure type register:
    GPIOA_TYPER_SET(GPIOA_TYPER, 0U);

    // (2) Configure PA0 as button:
    GPIOA_MODER_CONFIGURATE_PA0_BUTTON(GPIOA_MODER, 0U);

    // Configure PA0 as pull-down pin:
    GPIOA_PUPDR_CONFIGURATE_PA0_MODE(GPIOA_PUPDR, PULL_DOWN);
}

//------
// Main
//------

int main() {

    board_clocking_init();

    board_gpio_init();

    // Init display rendering:
    struct Seg7Display seg7 =
    {
        .number = 0
    };

    uint32_t tick = 0;
    bool button_was_pressed = 0U;
    uint32_t saturation = 0U;
    while (1)
    {
        // Update button state:
        bool active = *GPIOA_IDR & (1U << 0U);

        if (active)
        {
            if (saturation < 5U)
            {
                saturation += 1U;
            }
            else
            {
                button_was_pressed = 1U;
            }
        }
        else
        {
            saturation = 0U;
        }

        // Update display state:
        if (!button_was_pressed && (tick % 10U) == 0U)
        {
            if (seg7.number < 9999U)
            {
                seg7.number = seg7.number + 1U;
            }
        }

        // Render display state:
        SEG7_set_number_quarter(&seg7, tick);

        SEG7_push_display_state_to_mc(&seg7);

        // Adjust ticks every ms:
        to_get_more_accuracy_pay_2202_2013_2410_3805_1ms();
        tick += 1;
    }
}
