/**
 * 
 */

#include "PWM.h"
#include <Arduino.h>

void PWM_init(PWM_SIG PWM){ 
    pinMode(PWM.pin, OUTPUT);
}


void setFreq(PWM_PIN pin, freq_t freq){
    // prescaler = base_clk / (freq*256)
    // frequency = base_clock / prescaler / 256
}

void setOffset(PWM_PIN pin/*, precent*/){

}

void setAdvancedMode(PWM_PIN pin, PWM_MODE mode, PWM_ADV_MODE setting) {
    setMode(pin, mode);
    #if BOARD == UNO
        switch(setting){
            switch(pin){
            case _3:
            case _11:
                // Use timer2
                switch(setting){
                    case PWM_OC0A_TOG_COMP_MATCH:
                        TCCR2B |= (_BV(WGM22));
                        break;
                    case PWM_OC0A_DISCONNECT:
                    default:
                        TCCR2B &= ~(_BV(WGM22));
                        break;
                }
                break;
            case _5:
            case _6:
                // Use timer0
                
                break;
            default:
                // Use timer1
                
                break;
        }
        }
    #endif /*BORAD*/
}

void setMode(PWM_PIN pin, PWM_MODE mode){
    // Here we need to set the Waveform Generation Mode bits(WGM).
    // These control the overall mode of the timer and are split
    // between TCCnA and TCCnB
    #if BOARD == UNO
        switch(pin){
            case _3:
            case _11:
                // Use timer2
                switch (mode){
                    case PWM_NORMAL:
                        TCCR2A &= ~(_BV(WGM21) | _BV(WGM20));
                        break;
                    case PWM_FAST:
                        TCCR2A |= (_BV(WGM21) | _BV(WGM20));
                        break;
                    case PWM_PHASE_CORR:
                        TCCR2A |= (_BV(WGM20));  // Set this bit
                        TCCR2A &= ~(_BV(WGM21)); // Clear this bit
                        break;
                    case PWM_CLEAR_TIMER_ON_COMP:
                    case PWM_PHASE_FREQ_CORR:
                        TCCR2A &= ~(_BV(WGM20)); // Clear this bit
                        TCCR2A |= (_BV(WGM21));  // Set this bit
                        break;
                    default: // Clear all WGM bits
                        TCCR2A &= ~(_BV(WGM21) | _BV(WGM20));
                        break;
                }
                break;
            case _5:
            case _6:
                // Use timer0
                
                break;
            default:
                // Use timer1
                
                break;
        }
    // end UNO
        
    #endif /*BOARD*/
}

void setOutputType(PWM_PIN pin, PWM_OUTPUT type){
    #if BOARD == UNO
        switch(pin)
        {
            case _3:
            case _11:
                // Use timer2
                TCCR2A |= (
                    (type) ? 
                    0 :
                    0
                );
                break;
            case _5:
            case _6:
                // Use timer0
                TCCR2A |= (
                    (type) ? 
                    0 :
                    0
                );
                break;
            default:
                // Use timer1
                TCCR2A |= (
                    (type) ? 
                    0 :
                    0
                );
                break;
        }
    // end UNO
    #endif /*BOARD*/
}

void setDutyCycle(PWM_PIN pin/*, precent*/){ // it says duty xD

}


