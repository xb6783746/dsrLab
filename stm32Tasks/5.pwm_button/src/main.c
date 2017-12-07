#include <main.h>
#include <init.h>
#include <systimer.h>
#include <led.h>

extern char brightnessButtonFlag;
extern char channelButtonFlag;

#define BR_LEVEL_COUNT 6

int getStep(int index, int levelCount);
void init(void);

int currIndex;
int currChannel;

int brLevels[BR_LEVEL_COUNT];
Channel channels[3];

int getStep(int index, int levelCount){
    
    return 100 / levelCount;
}

void init(void){
    
    currIndex = 0;
    currChannel = 0;
    
    brLevels[0] = 0;
    
    int i;
    for(i = 1; i < BR_LEVEL_COUNT; i++){
    
        brLevels[i] = brLevels[i - 1] + getStep(i, BR_LEVEL_COUNT);
    }
    
    channels[0] = Red;
    channels[1] = Green;
    channels[2] = Blue;
    
    initLeds();
    initButtons();
    initTimer();
    initPwm();
    initInterrupts();
    systimerInit();
    
    TIM_Cmd(TIM1, ENABLE);
    
    switchChannel(Red, 1);
    switchChannel(Green, 0);
    switchChannel(Blue, 0);
}

int main(void)
{
    init();
    
    while (1) {
      
        if(brightnessButtonFlag){
            
            brightnessButtonFlag = 0;
            
            currIndex = (currIndex + 1) % BR_LEVEL_COUNT;
            
            setBrightness(brLevels[currIndex], channels[currChannel]);
        }
        
         if(channelButtonFlag){
            
            channelButtonFlag = 0;
            
            switchChannel(channels[currChannel], 0);
                          
            currChannel = (currChannel + 1) % 3;
            
            setBrightness(brLevels[currIndex], channels[currChannel]);
        }
    }

}
