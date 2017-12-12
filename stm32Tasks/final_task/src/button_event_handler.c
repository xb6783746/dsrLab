#include <button_event_handler.h>
#include <led_api.h>

#define CHANNEL_COUNT 3
#define STEP 10

extern char brightnessButtonFlag;
extern char channelButtonFlag;

static Channel order[CHANNEL_COUNT];

static char currBrightness;
static uint32_t currChannel;

void initButtonEventHandler(){

    order[0] = Red;
    order[1] = Green;
    order[2] = Blue;

    currBrightness = 255;
    currChannel = 0;
    
    brightnessButtonFlag = 0;
    channelButtonFlag = 0;
    
    setRGB(0, 0, 0);
    setBrightness(currBrightness, order[currChannel]); 
}

void processButtonEvents(void){
    
    if(brightnessButtonFlag){
        
        brightnessButtonFlag = 0;
        
        currBrightness = (currBrightness + STEP) % 255;
        
        setBrightness(currBrightness, order[currChannel]);  
    }

    if(channelButtonFlag){
        
        channelButtonFlag = 0;

        setBrightness(0, order[currChannel]);

        currChannel = (currChannel + 1) % CHANNEL_COUNT;
        
        setBrightness(currBrightness, order[currChannel]);
    }    
}
