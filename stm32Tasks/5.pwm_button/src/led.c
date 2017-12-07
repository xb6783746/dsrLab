#include <led.h>
#include <init.h>

void setBrightness(char brightness, Channel channel){
    
    uint32_t pulse = ARR_VAL * brightness / 100;
    
    switch(channel){
        
        case Red:
            TIM_SetCompare1(TIM1, pulse);
            break;
        case Green:
            TIM_SetCompare2(TIM1, pulse);
            break;
        case Blue:
            TIM_SetCompare3(TIM1, pulse);
            break;
    }
}

void switchChannel(Channel channel, char state){
  

    char brightness = state? 100 : 0;
    
    setBrightness(brightness, channel);
}

