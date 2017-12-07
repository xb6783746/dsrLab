#ifndef LED_PWM_API
#define LED_PWM_API

#include <led_pwm_common_structures.h>

void initLedsPWM(); 

void setRGB(char r, char g, char b);
void setBrightness(char brightness, Channel channel);
#endif
