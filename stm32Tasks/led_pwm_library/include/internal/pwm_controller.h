#ifndef PWM_CONTROLLER
#define PWM_CONTROLLER

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
 * @param channel Timer channel. Can be one of 1, 2, 3
 */
void setChannelPower(char val, char channel);

/**
 * @brief Sets duty cycles for all channels
 * 
 * Duty cycle (%) is \f$ \frac{x}{255} * 100 \f$
 * 
 */
void setPower(char ch1, char ch2, char ch3);

#endif
