#include <init.h>

#define TIMER_CLK 168000000
//1680
#define PRESCALER (TIMER_CLK / TIMER_FREQ)


void initLeds(void) {
    
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_TIM1);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_TIM1);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_TIM1);
    
    GPIO_InitTypeDef GPIO_InitStructure;
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10;  
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void initButtons(){
 
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
      
    GPIO_InitTypeDef  GPIO_InitStructure;
    
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Pin = BUTTON_PIN | CHANNEL_BUTTON_PUN;
    
    GPIO_Init(GPIOE, &GPIO_InitStructure);
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
    
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource0);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource1);
    
    EXTI_InitTypeDef EXTI_InitStruct;
    
    EXTI_InitStruct.EXTI_Line = EXTI_Line0 | EXTI_Line1;
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_Init(&EXTI_InitStruct);
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

    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
     
    nvicInit.NVIC_IRQChannel = TIM2_IRQn;
    nvicInit.NVIC_IRQChannelPreemptionPriority = 0;
    nvicInit.NVIC_IRQChannelSubPriority = 1;
    nvicInit.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvicInit);
    
    nvicInit.NVIC_IRQChannel = EXTI0_IRQn;
    nvicInit.NVIC_IRQChannelPreemptionPriority = 0x00;
    nvicInit.NVIC_IRQChannelSubPriority = 0x00;
    nvicInit.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvicInit); 
    
    nvicInit.NVIC_IRQChannel = EXTI1_IRQn;
    nvicInit.NVIC_IRQChannelPreemptionPriority = 0x00;
    nvicInit.NVIC_IRQChannelSubPriority = 0x00;
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
    
    TIM_OC2Init(TIM1, &pwmInit);
    TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);
    
    TIM_OC3Init(TIM1, &pwmInit);
    TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);
    
    TIM_CtrlPWMOutputs(TIM1, ENABLE);
}
