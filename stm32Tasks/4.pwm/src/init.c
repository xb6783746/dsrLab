#include <init.h>

#define TIMER_CLK 168000000
//1680
#define PRESCALER (TIMER_CLK / TIMER_FREQ)

#define ARR_VAL (TIMER_FREQ / PWM_FREQ)


void initLeds(void) {
    
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_TIM1);
    
    GPIO_InitTypeDef GPIO_InitStructure;
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;  
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void initTimer(void){
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
    
    TIM_TimeBaseInitTypeDef timerInit;
    
    TIM_TimeBaseStructInit(&timerInit);
    
    timerInit.TIM_Period = (uint16_t)ARR_VAL;
    timerInit.TIM_Prescaler = PRESCALER - 1;
    timerInit.TIM_ClockDivision = TIM_CKD_DIV1;
    timerInit.TIM_CounterMode = TIM_CounterMode_Up;
    timerInit.TIM_RepetitionCounter = 0;
    
    TIM_TimeBaseInit(TIM1, &timerInit);
    
}

void initInterrupts(void)
{
    NVIC_InitTypeDef nvicInit;

    nvicInit.NVIC_IRQChannel = TIM2_IRQn;
    nvicInit.NVIC_IRQChannelPreemptionPriority = 0;
    nvicInit.NVIC_IRQChannelSubPriority = 1;
    nvicInit.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvicInit);

}

void initPwm(void){
    
    TIM_OCInitTypeDef pwmInit;
    
    TIM_OCStructInit(&pwmInit);
    
    pwmInit.TIM_OCMode = TIM_OCMode_PWM1;
    pwmInit.TIM_OutputState = TIM_OutputState_Enable;
    pwmInit.TIM_OCPolarity = TIM_OCPolarity_Low;
    pwmInit.TIM_Pulse = (uint32_t)(ARR_VAL * PULSE / 100);
    
    TIM_OC1Init(TIM1, &pwmInit);
    TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
    
    TIM_CtrlPWMOutputs(TIM1, ENABLE);
}
