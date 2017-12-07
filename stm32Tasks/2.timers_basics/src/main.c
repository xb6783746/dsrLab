#include <main.h>
#include <init.h>

#define BUTTON_DELAY 5000000

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
