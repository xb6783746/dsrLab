#ifndef STM32F4DISC_LEDS
#define STM32F4DISC_LEDS

typedef enum {
 
    DISC_RedLed, DISC_GreenLed, DISC_BlueLed, DISC_OrangeLed
} Stm32f4disc_leds_enum;

void initStm32DiscLeds(void);

void switchLed(Stm32f4disc_leds_enum led, char state);
#endif
