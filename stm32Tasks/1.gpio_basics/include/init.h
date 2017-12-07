#ifndef INIT
#define INIT

#include <stm32f4xx.h>

#define LED1_PIN GPIO_Pin_12
#define LED2_PIN GPIO_Pin_13
#define LED3_PIN GPIO_Pin_14
#define LED4_PIN GPIO_Pin_15

#define ALL_LEDS (LED1_PIN) | (LED2_PIN) | (LED3_PIN) | (LED4_PIN)
#define ALL_EXT_LEDS GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10

#define BUTTON_PIN GPIO_Pin_0

void initLeds(void);
void initButton(void);

#endif
