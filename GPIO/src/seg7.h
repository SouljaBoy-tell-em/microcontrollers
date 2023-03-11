#ifndef __SEG7_H__
#define __SEG7_H__


// Write changes to microcontroller:
void SEG7_push_display_state_to_mc(Seg7Display * seg7) {

    GPIOA_ODR_SET_VALUE_TO_SEGMENT(GPIOA_ODR, seg7->display);
}


void SEG7_set_number_quarter(Seg7Display * seg7, unsigned tick) {

    uint32_t divisors[4] =   {1000, 100, 10, 1};
    unsigned rank        =             tick % 4;
    unsigned divisor     =       divisors[rank];

    // Write to value SEG7 value, that will write to microcontroller in 
    // macro for setting VALUE TO SEG7 INDICATOR SEGMENT:
    SEG7_SET_VALUE_TO_RANK(seg7, divisor, rank);
}

#endif