#include <led_api.h>
#include <internal/pwm_controller.h>

#include <stm32f4xx.h>
#include <math.h>

#ifndef GAMMA_CORRECTION_PARAMETER

#define GAMMA_CORRECTION_PARAMETER 3.03
#endif

/**
 * @file src/led_controller.c
 *
 * Functions for controlling RGB led.
 *
 * Functions sets gamma-corected values of brightness.
 * \f$ realValue = 255 * (\frac{x}{255})^\gamma \f$, where value of \f$ \gamma \f$ can be defined as
 * GAMMA_CORRECTION_PARAMETER. Default value is 3.03
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
    
    PWM_Channel ch;
    char value = gammaCorrection(brightness);
    
    switch(channel){
        
        case Red:
            ch = PWM_FirstChannel;
            break;
        case Green:
            ch = PWM_SecondChannel;
            break;
        case Blue:
            ch = PWM_ThirdChannel;
            break;
    }
    
    setChannelPower(value, ch);
}
