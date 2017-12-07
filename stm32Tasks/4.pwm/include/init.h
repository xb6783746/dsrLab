#ifndef INIT
#define INIT

#include <stm32f4xx.h>

#define TIMER_FREQ 100000
#define PWM_FREQ 100
#define PULSE 30

void initLeds(void);
void initTimer(void);
void initPwm(void);
void initInterrupts(void);

#endif
