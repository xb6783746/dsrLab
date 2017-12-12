#ifndef LED_API
#define LED_API

#include <led_pwm_common_structures.h>

void setRGB(char r, char g, char b);
void setBrightness(char brightness, Channel channel);

#endif
