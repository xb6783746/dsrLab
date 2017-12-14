#include <button_event_handler.h>
#include <led_api.h>
#include <stm32f4disc_leds.h>

#define CHANNEL_COUNT 3
#define STEP 10

extern char brightnessButtonFlag;
extern char channelButtonFlag;

static Channel extLedsChannels[CHANNEL_COUNT];
static Stm32f4disc_leds_enum leds[CHANNEL_COUNT];

static char currBrightness;
static uint32_t currChannel;

void initButtonEventHandler(){

    initStm32DiscLeds();
    
    extLedsChannels[0] = Red;
    extLedsChannels[1] = Green;
    extLedsChannels[2] = Blue;
    
    leds[0] = DISC_RedLed;
    leds[1] = DISC_GreenLed;
    leds[2] = DISC_BlueLed;

    currBrightness = 255;
    currChannel = 0;
    
    brightnessButtonFlag = 0;
    channelButtonFlag = 0;
    
    setRGB(0, 0, 0);
    setBrightness(currBrightness, extLedsChannels[currChannel]); 
    switchLed(leds[currChannel], 1);
}

void processButtonEvents(void){
    
    if(brightnessButtonFlag){
        
        brightnessButtonFlag = 0;
        
        currBrightness = (currBrightness + STEP) % 255;
        
        setBrightness(currBrightness, extLedsChannels[currChannel]);  
    }

    if(channelButtonFlag){
        
        channelButtonFlag = 0;

        switchLed(leds[currChannel], 0);
        
        currChannel = (currChannel + 1) % CHANNEL_COUNT;
        
        switchLed(leds[currChannel], 1);
    }    
}
