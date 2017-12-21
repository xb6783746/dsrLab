#include <systimer.h>

uint32_t systimer_timestamp;

void SysTick_Handler (void){

   systimer_timestamp++;
}

void systimerInit(void){
    
    systimer_timestamp = 0;

    //SysTick_Config(SystemCoreClock / SYSTIMER_FREQ);
    RCC_ClocksTypeDef RCC_Clocks;
    RCC_GetClocksFreq(&RCC_Clocks);
    SysTick_Config(RCC_Clocks.HCLK_Frequency / SYSTIMER_FREQ);
}
