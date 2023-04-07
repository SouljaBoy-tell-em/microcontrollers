#ifndef __HEADER_SEG7_H__
#define __HEADER_SEG7_H__


//-------------------
// 7-segment display
//-------------------

// SUPER-DUPER TRUSTWORTHY Pin Mapping:

#define A    (1U << 11U)
#define B    (1U <<  7U)
#define C    (1U <<  4U)
#define D    (1U <<  2U)
#define E    (1U <<  1U)
#define F    (1U << 10U)
#define G    (1U <<  5U)
#define DP   (1U <<  3U)

#define POS0 (1U << 12U)
#define POS1 (1U <<  9U)
#define POS2 (1U <<  8U)
#define POS3 (1U <<  6U)


// TOTALLY ALL PINS MASK:
static const uint32_t PINS_USED = A|B|C|D|E|F|G|DP|POS0|POS1|POS2|POS3;

// TOTALLY CORRECT digit composition:
static const uint32_t DIGITS[10] =   { A|B|C|D|E|F,           // 0
                                       B|C,                   // 1
                                       A|B|G|E|D,             // 2
                                       A|B|G|C|D,             // 3
                                       B|C|F|G,               // 4
                                       A|F|G|C|D,             // 5
                                       A|C|D|E|F|G,           // 6
                                       A|B|C,                 // 7
                                       A|B|C|D|E|F|G,         // 8
                                       A|B|C|D|F|G            // 9
                                     };

// TURN ON necessary cathods for on/off pins:
static const uint32_t POSITIONS[4] = {      POS1|POS2|POS3,   // 0
                                       POS0     |POS2|POS3,   // 1
                                       POS0|POS1     |POS3,   // 2
                                       POS0|POS1|POS2         // 3
                                     };


// Display state:
typedef struct {

    uint32_t display;
    uint16_t number;
} Seg7Display;


//--------
// MACROS
//--------

#define SEG7_SET_VALUE_TO_RANK(seg7, divisor, rank) \
        ((seg7)->display) = (DIGITS[(((seg7)->number) / divisor) % 10]) | (POSITIONS[(rank)])
#define UPDATE_DISPLAY_STATE_TO_UPLIM(button_was_pressed, tick, delay, seg7, uplimit) \
        if(!button_was_pressed && !(tick % delay))  {                                 \
            if(seg7.number < uplimit)                                                 \
                seg7.number++;                                                        \
            else                                                                      \
                seg7.number = 0U;                                                     \
        }


//-----------
// FUNCTIONS
//-----------

void SEG7_set_number_quarter(Seg7Display * seg7, unsigned tick);
void SEG7_push_display_state_to_mc(Seg7Display * seg7);

#endif