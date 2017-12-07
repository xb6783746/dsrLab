#ifndef INIT
#define INIT

#include <stm32f4xx.h>

#define TIMER_FREQ 100000
#define PWM_FREQ 100
#define PULSE 30

#define ARR_VAL (TIMER_FREQ / PWM_FREQ)

#define BUTTON_PIN GPIO_Pin_0
#define CHANNEL_BUTTON_PUN GPIO_Pin_1

void initLeds(void);
void initTimer(void);
void initPwm(void);
void initInterrupts(void);
void initButtons(void);

#endif
