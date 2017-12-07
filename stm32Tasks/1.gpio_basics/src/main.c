#include <main.h>
#include <init.h>

#define SWITCH_DELAY 10000000

int main(void)
{
    
    initLeds();
    initButton();

    long ledArr[] = {~GPIO_Pin_8, ~GPIO_Pin_9, ~GPIO_Pin_10};
    int num = 0;
    
    while (1)
    {
        int i;

        GPIO_ResetBits(GPIOA, ledArr[num]);
        
        num = (num + 1) % 3;
        GPIO_SetBits(GPIOA, ledArr[num]);
        
        for (i=0; i < SWITCH_DELAY; i++)
        {
            /* empty cycle */
        }

        uint8_t buttonVal = GPIO_ReadInputDataBit(GPIOE, BUTTON_PIN);

        if(buttonVal){

            GPIO_SetBits(GPIOD, LED1_PIN);
        } else {

            GPIO_ResetBits(GPIOD, LED1_PIN);
        }
    }
}
