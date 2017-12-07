#include <main.h>
#include <init.h>

#define BUTTON_DELAY 5000000


long ledArr[3];
int num;

int order = 1;
int delay;
    
void TIM2_IRQHandler(void){
    
    if(TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET){
        
        GPIO_ResetBits(GPIOA, ledArr[num]);
        num = (num + order + 3) % 3;

        GPIO_SetBits(GPIOA, ledArr[num]);
        
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

    }
}

void EXTI0_IRQHandler(void) {
    
    if (EXTI_GetITStatus(EXTI_Line0) != RESET){
        
        EXTI_ClearITPendingBit(EXTI_Line0);
        
        order = -order;
    }
}


int main(void)
{
    ledArr[0] = ~GPIO_Pin_8;
    ledArr[1] = ~GPIO_Pin_9;
    ledArr[2] = ~GPIO_Pin_10;
    
    num = 0;
    order = 1;
    delay = 0;
    
    initLeds();
    initButton();
    initInterrupt();
    initTimer();
    
    while (1) {
      
        int i;
        
        
        if(delay > 0){
         
            delay--;
        }

    }

}
