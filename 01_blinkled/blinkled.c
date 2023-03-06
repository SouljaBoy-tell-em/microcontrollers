#include "head_blinked.h"
#include "registers.h"
#include "bits.h"
#include "gpio.h"
#include "blinked.h"


int main(void) {

#ifndef INSIDE_QEMU

    board_clocking_init();
#endif

    board_gpio_init();

    while (true) {

        GPIO_BIT_SET_BLINKING_ON(GPIOC_PORT_BIT_SET,  8);
        delay_3000_time_delay_ms();
        GPIO_BIT_SET_BLINKING_OFF(GPIOC_PORT_BIT_SET, 8);
        delay_3000_time_delay_ms();

        GPIO_BIT_SET_BLINKING_ON(GPIOC_PORT_BIT_SET,  9);
        delay_3000_time_delay_ms();
        GPIO_BIT_SET_BLINKING_OFF(GPIOC_PORT_BIT_SET, 9);
        delay_3000_time_delay_ms();
    }

    return 0;
}
