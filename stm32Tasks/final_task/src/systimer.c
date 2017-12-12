#include <systimer.h>

uint32_t systimer_timestamp;

void SysTick_Handler (void){

   systimer_timestamp++;
}

void systimerInit(void){
    
    systimer_timestamp = 0;

    SysTick_Config(SystemCoreClock / SYSTIMER_FREQ);
}
