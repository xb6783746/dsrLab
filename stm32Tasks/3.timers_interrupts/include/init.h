#ifndef INIT
#define INIT

#include <stm32f4xx.h>

#define ALL_LEDS GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10

#define BUTTON_PIN GPIO_Pin_0

#define PRESCALER 84
#define PERIOD 1000000

void initLeds(void);
void initTimer(void);
void initInterrupt(void);
void initButton(void);

#endif
