#include "main.h"

#define SWITCH_DELAY 10000000
#define LED1_PIN GPIO_Pin_12
#define LED2_PIN GPIO_Pin_13
#define LED3_PIN GPIO_Pin_14
#define LED4_PIN GPIO_Pin_15

#define ALL_LEDS (LED1_PIN) | (LED2_PIN) | (LED3_PIN) | (LED4_PIN)
#define ALL_EXT_LEDS GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10

#define BUTTON_PIN GPIO_Pin_0

void initLeds(void);
void initButton(void);

void initLeds(void){
    
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  
    GPIO_InitTypeDef GPIO_InitStructure;
    
    GPIO_InitStructure.GPIO_Pin = ALL_LEDS;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = ALL_EXT_LEDS;  
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void initButton(void){
    
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
      
    GPIO_InitTypeDef GPIO_InitStructure;
      
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Pin = BUTTON_PIN;
    GPIO_Init(GPIOE, &GPIO_InitStructure);
}

int main(void)
{
    
    initLeds();
    initButton();

    long ledArr[] = {~GPIO_Pin_8, ~GPIO_Pin_9, ~GPIO_Pin_10};
    int num = 0;
    
    while (1)
    {
        int i;

        GPIO_ResetBits(GPIOA, ledArr[num]);
        num = (num + 1) % 3;

        GPIO_SetBits(GPIOA, ledArr[num]);
        
        for (i=0; i < SWITCH_DELAY; i++)
        {
            /* empty cycle */
        }

        uint8_t buttonVal = GPIO_ReadInputDataBit(GPIOE, BUTTON_PIN);

        if(buttonVal){

            GPIO_SetBits(GPIOD, LED1_PIN);
        } else {

            GPIO_ResetBits(GPIOD, LED1_PIN);
        }
    }
}
