#ifndef BUTTON_EVENT_HANDLER
#define BUTTON_EVENT_HANDLER

#include <stm32f4xx.h>
#include <led_pwm_api.h>

void initButtonEventHandler(void);
void processButtonEvents(void);
void setOrder(Channel* orderArr, uint32_t count);
void setStep(char step);
#endif
