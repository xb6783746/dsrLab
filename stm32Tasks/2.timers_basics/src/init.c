#include <init.h>

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
