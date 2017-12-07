#include <stm32f4xx.h>

#define BUTTON_DELAY_MS 1000

extern uint32_t systimer_timestamp;
static uint32_t delay = 0;
char channelButtonFlag = 0;

void EXTI1_IRQHandler(void) {
    
    if (EXTI_GetITStatus(EXTI_Line1) != RESET){
        
        EXTI_ClearITPendingBit(EXTI_Line1);
        
        if(delay - systimer_timestamp < BUTTON_DELAY_MS){
         
            return;
        }
        
        delay = systimer_timestamp + BUTTON_DELAY_MS;
        
        channelButtonFlag = 1;
    }
}
