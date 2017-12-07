#include <stm32f4xx.h>

#define BUTTON_DELAY_MS 1000

extern uint32_t systimer_timestamp;
static uint32_t delay = 0;
char brightnessButtonFlag = 0;

void EXTI0_IRQHandler(void) {
    
    if (EXTI_GetITStatus(EXTI_Line0) != RESET){
        
        EXTI_ClearITPendingBit(EXTI_Line0);
        
        if(delay - systimer_timestamp < BUTTON_DELAY_MS){
         
            return;
        }
        
        delay = systimer_timestamp + BUTTON_DELAY_MS;
        
        brightnessButtonFlag = 1;
    }
}
