/*****************************
 * 
 *****************************/

#ifndef PWM_H
#define PWM_H

/** To specify units of Hz */
#define Hz(x)   (x)

/** To specify units of kHz */
#define kHz(x)  (x * 1000)

/** To specify units of MHz */
#define MHz(x)  (kHz(x) * 1000)


#include <stdint.h>
#include "board_type.h"

typedef uint16_t prescaler_t;
typedef uint32_t freq_t;

/**
 *  This is here mainly just to help debug and make sure 
 *  that the pin being entered is the correct pin for that 
 *  specific board.
 */
typedef enum PWM_PIN {
    // TODO: Set the PWM pins for the different boards 
    #if BOARD == _UNO
        _3  = 3,
        _5  = 5,
        _6  = 6,
        _9  = 9,
        _10 = 10,
        _11 = 11
    #else // Default to 20 pins to cover most boards currently undefined 
        _0  = 0,
        _1  = 1,
        _2  = 2,
        _3  = 3,
        _4  = 4,
        _5  = 5,
        _6  = 6,
        _7  = 7,
        _8  = 8,
        _9  = 9,
        _10 = 10,
        _11 = 11,
        _12 = 12,
        _13 = 13,
        _14 = 14,
        _15 = 15,
        _16 = 16,
        _17 = 17,
        _20 = 20
    #endif /*BOARD*/
} PWM_PIN;

typedef enum PWM_ADV_MODE {
    PWM_OC0A_DISCONNECT     = 0,
    PWM_OC0A_TOG_COMP_MATCH = 1
} PWM_ADV_MODE;

/**
 * 
 */
typedef enum PWM_MODE {
    PWM_NORMAL              = 0,
    PWM_FAST                = 1,
    PWM_PHASE_CORR          = 2,
    PWM_CLR_TIMER_ON_CMP    = 3,
    PWM_PHASE_FREQ_CORR     = 4,
    PWM_CLEAR_TIMER_ON_COMP = 5
} PWM_MODE;

/**
 * 
 */
typedef enum PWM_OUTPUT {
    PWM_DISABLE     = 0,
    PWM_ENABLE      = 1,
    PWM_INVERTED    = 2,
} PWM_OUTPUT;

/**
 * 
 */
typedef struct PWM_SIG {
    PWM_PIN pin;
    PWM_MODE mode;
    uint8_t inverted;

    // Since there is no reason both the prescaler and the frequency need
    // to be set at the same time, lets make this a union to save memory.
    // Note that more memory will actually be taken up if the prescaler
    // is used instead, but this just saves and extra 2-4 bytes
    union {  
        prescaler_t prescaler;
        freq_t frequency;
    };
} PWM_SIG;

void PWM_init(PWM_SIG PWM);
void setFreq(PWM_PIN pin, freq_t freq);
void setOffset(PWM_PIN pin/*, precent*/);
void setAdvancedMode(PWM_PIN pin, PWM_MODE mode, PWM_ADV_MODE setting);
void setMode(PWM_PIN pin, PWM_MODE mode);
void setDutyCycle(PWM_PIN pin/*, precent*/); // xD duty
void setOutputType(PWM_PIN pin, PWM_OUTPUT type);

#endif /*PWM_H*/