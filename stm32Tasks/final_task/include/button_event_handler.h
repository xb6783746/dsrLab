#ifndef BUTTON_EVENT_HANDLER
#define BUTTON_EVENT_HANDLER

#include <stm32f4xx.h>
#include <led_pwm_common_structures.h>

void initButtonEventHandler(void);
void processButtonEvents(void);
#endif
