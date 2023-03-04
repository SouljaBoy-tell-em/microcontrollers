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

        BLINKINGDIODE (8)
        BLINKINGDIODE (9)
    }

    return 0;
}