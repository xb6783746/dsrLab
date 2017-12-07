#include <main.h>
#include <init.h>


int main(void)
{
    initLeds();
    
    initTimer();
    
    initPwm();
    
    
    TIM_Cmd(TIM1, ENABLE);
    
    while (1) {
      

    }

}
