#include <stm32f4xx.h>

#include <utils/exti_utils.h>

#ifndef BRIGHTNESS_BUTTON_LINE

    #define BRIGHTNESS_BUTTON_LINE 0
    #pragma message "Line for brightness button wasn't specified. Default value is 0"

#endif

#define EXTI_HANDLER_NAME GET_EXTI_HANDLER_NAME(BRIGHTNESS_BUTTON_LINE)
#define EXTI_LINE_NAME GET_EXTI_LINE_NAME(BRIGHTNESS_BUTTON_LINE)

#define BUTTON_DELAY_MS 1000

extern uint32_t systimer_timestamp;
static uint32_t delay = 0;
char brightnessButtonFlag = 0;

void EXTI_HANDLER_NAME(void) {
    
    if (EXTI_GetITStatus(EXTI_LINE_NAME) != RESET){
        
        EXTI_ClearITPendingBit(EXTI_LINE_NAME);
        
        if(delay - systimer_timestamp < BUTTON_DELAY_MS){
         
            return;
        }
        
        delay = systimer_timestamp + BUTTON_DELAY_MS;
        
        brightnessButtonFlag = 1;
    }
}
