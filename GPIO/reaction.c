#include "headers/header_reaction.h"
#include "headers/header_seg7.h"

#include "src/bits.h"
#include "src/registers.h"
#include "src/gpio.h"
#include "src/seg7.h"
#include "src/reaction.h"



int main() {

    // Init display rendering:
    Seg7Display seg7        = { .display = 0, .number = 0};
    bool active             =                        false;
    bool button_was_pressed =                        false;
    uint32_t saturation     =                           0U;
    uint32_t tick           =                           0U;

    board_clocking_init();
    board_gpio_init();



    while (true) {

        // Update button state:
        GPIO_IDR_GET_VALUE_PA0_INPUT(active, GPIOA_IDR, 0U);

        // Contact bounce prevention:
        TURN_ON_CONTACT_DEBOUNCER(active, saturation, button_was_pressed);

        // Update display state, while button wasn't pressed
        // not equal UPLIMIT:
        UPDATE_DISPLAY_STATE_TO_UPLIM(button_was_pressed, tick, 10, seg7, UPLIMIT);

        // Render display state:
        SEG7_set_number_quarter(&seg7, tick);
        SEG7_push_display_state_to_mc(&seg7);

        // Adjust ticks every ms:
        to_get_more_accuracy_pay();
        tick++;
    }
}
