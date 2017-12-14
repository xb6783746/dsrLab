#ifndef PWM_CONTROLLER
#define PWM_CONTROLLER


typedef enum {
    
    PWM_FirstChannel, PWM_SecondChannel, PWM_ThirdChannel
} PWM_Channel;

/**
 * @file internal/pwm_controller.h
 *
 * Functions for low-level PWM controlling
 */

/**
 * @brief Sets duty cycle for specific channel
 *
 * Duty cycle (%) is \f$ \frac{x}{255} * 100 \f$
 *
 * @param val 
 * @param channel
 */
void setChannelPower(char val, PWM_Channel channel);

/**
 * @brief Sets duty cycles for all channels
 * 
 * Duty cycle (%) is \f$ \frac{x}{255} * 100 \f$
 * 
 */
void setPower(char ch1, char ch2, char ch3);

#endif
