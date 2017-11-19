#include "main.h"
//#include <stm32f4xx_tim.h>

#define SWITCH_DELAY 10000000

#define ALL_LEDS GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10

#define BUTTON_PIN GPIO_Pin_0

#define PRESCALER 84
#define PERIOD 1000000

#define BUTTON_DELAY 5000000

void initLeds(void);
void initTimer(void);
void initButton(void);

void initLeds(void) {
    
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    
    GPIO_InitTypeDef  GPIO_InitStructure;
    
    GPIO_InitStructure.GPIO_Pin = ALL_LEDS;  
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void initTimer(void){
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    
    TIM_TimeBaseInitTypeDef timerInit;
    
    timerInit.TIM_Period = PERIOD;
    timerInit.TIM_Prescaler = PRESCALER - 1;
    timerInit.TIM_ClockDivision = 0;
    timerInit.TIM_CounterMode = TIM_CounterMode_Up;
    
    TIM_TimeBaseInit(TIM2, &timerInit);
    
    //TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM2, ENABLE);
}

void initButton(void){
    
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
      
    GPIO_InitTypeDef  GPIO_InitStructure;
    
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Pin = BUTTON_PIN;
    
    GPIO_Init(GPIOE, &GPIO_InitStructure);
}

int main(void)
{
    
    initTimer();
    initLeds();
    initButton();
  
    long ledArr[] = {~GPIO_Pin_8, ~GPIO_Pin_9, ~GPIO_Pin_10};
    int num = 0;
    
    int order = 1;
    int delay = 0;
    
    while (1) {
      
        int i;
        
    
        if(!TIM_GetCounter(TIM2)){
            
            GPIO_ResetBits(GPIOA, ledArr[num]);
            num = (num + order + 3) % 3;
            
            GPIO_SetBits(GPIOA, ledArr[num]);
        }
        
        
        if(!GPIO_ReadInputDataBit(GPIOE, BUTTON_PIN) && !delay){
            
            order *= -1;
            
            delay = BUTTON_DELAY;
        }
        
        if(delay > 0){
         
            delay--;
        }

    }

}
