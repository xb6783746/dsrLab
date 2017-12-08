#include <internal/pwm_controller.h>
#include <internal/led_pwm_configuration.h>

#include <stm32f4xx.h>

void setChannelPower(char val, char channel){
    
    uint32_t pulse = ARR_VAL * val / 255;
    
    switch(channel){
        
        case 1:
            TIM_SetCompare1(PWM_TIM, pulse);
            break;
        case 2:
            TIM_SetCompare2(PWM_TIM, pulse);
            break;
        case 3:
            TIM_SetCompare3(PWM_TIM, pulse);
            break;
    }
}

void setPower(char ch1, char ch2, char ch3){
    
    uint32_t pulse = ARR_VAL * ch1 / 255;
    TIM_SetCompare1(PWM_TIM, pulse);
    
    pulse = ARR_VAL * ch2 / 255;
    TIM_SetCompare2(PWM_TIM, pulse);
    
    pulse = ARR_VAL * ch3 / 255;
    TIM_SetCompare3(PWM_TIM, pulse);
    
    
}