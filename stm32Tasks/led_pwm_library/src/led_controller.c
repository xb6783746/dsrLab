#include <led_api.h>
#include <internal/pwm_controller.h>

#include <stm32f4xx.h>
#include <math.h>

#ifndef GAMMA_CORRECTION_PARAMETER

#define GAMMA_CORRECTION_PARAMETER 2.2
#endif

/**
 * @file src/led_controller.c
 *
 * Functions for controlling RGB led.
 *
 * Functions sets gamma-corected values of brightness.
 * \f$ realValue = 255 * (\frac{x}{255})^\gamma \f$, where value of \f$ \gamma \f$ can be defined as
 * GAMMA_CORRECTION_PARAMETER. Default value is 2.2
 */

int __errno;

/**
 * @brief Function for gamma-correcting
 *
 * @return \f$ 255 * (\frac{val}{255})^\gamma \f$, where \f$ \gamma \f$ is GAMMA_CORRECTION_PARAMETER
 */
static char gammaCorrection(char val){
    
    double tmp = val / 255.0;
    
    return (char)(pow(tmp, GAMMA_CORRECTION_PARAMETER) * 255);
}

void setRGB(char r, char g, char b){
    
    char correctedR = gammaCorrection(r);
    char correctedG = gammaCorrection(g);
    char correctedB = gammaCorrection(b);
    
    setPower(correctedR, correctedG, correctedB);
}

void setBrightness(char brightness, Channel channel){
    
    char ch = 0;
    char value = gammaCorrection(brightness);
    
    switch(channel){
        
        case Red:
            ch = 1;
            break;
        case Green:
            ch = 2;
            break;
        case Blue:
            ch = 3;
            break;
    }
    
    setChannelPower(value, ch);
}
