#include <stm32f4disc_leds.h>

#include <stm32f4xx.h>

#define LED_GPIO GPIOD
#define LED_BUS RCC_AHB1Periph_GPIOD

#define RED_LED GPIO_Pin_14
#define GREEN_LED GPIO_Pin_12
#define BLUE_LED GPIO_Pin_15
#define ORANGE_LED GPIO_Pin_13

uint16_t ledMasks[4];

void initStm32DiscLeds(){
    
    ledMasks[DISC_RedLed] = RED_LED;
    ledMasks[DISC_GreenLed] = GREEN_LED;
    ledMasks[DISC_BlueLed] = BLUE_LED;
    ledMasks[DISC_OrangeLed] = ORANGE_LED;
    
    RCC_AHB1PeriphClockCmd(LED_BUS, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Pin = RED_LED | GREEN_LED | BLUE_LED | ORANGE_LED;
    
    GPIO_Init(LED_GPIO, &GPIO_InitStructure);
}

void switchLed(Stm32f4disc_leds_enum led, char state){
    
    uint16_t mask = ledMasks[led];
    
    if(state){
     
        GPIO_SetBits(LED_GPIO, mask);
    } else {
     
        GPIO_ResetBits(LED_GPIO, mask);
    }
}
