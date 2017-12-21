#include <button_event_handler.h>
#include <led_api.h>
#include <stm32f4disc_leds.h>
#include <lcd_led_info.h>

#define CHANNEL_COUNT 3
#define STEP 10

extern char brightnessButtonFlag;
extern char channelButtonFlag;

static Channel extLedsChannels[CHANNEL_COUNT];
static Stm32f4disc_leds_enum leds[CHANNEL_COUNT];

static uint8_t currBrightness[CHANNEL_COUNT];
static uint32_t currChannel;

void initButtonEventHandler(){

    initStm32DiscLeds();
    
    lcdLedInfoInit();
    
    extLedsChannels[0] = Red;
    extLedsChannels[1] = Green;
    extLedsChannels[2] = Blue;
    
    leds[0] = DISC_RedLed;
    leds[1] = DISC_GreenLed;
    leds[2] = DISC_BlueLed;

    currBrightness[0] = 255;
    currBrightness[1] = 0;
    currBrightness[2] = 0;
    
    currChannel = 0;
    
    brightnessButtonFlag = 0;
    channelButtonFlag = 0;
    
    setRGB(0, 0, 0);
    setBrightness(currBrightness[currChannel], extLedsChannels[currChannel]); 
    switchLed(leds[currChannel], 1);
    lcdLedInfoSetCurrentChannel(currChannel);
    lcdLedInfoSetValues(currBrightness[Red], currBrightness[Green], currBrightness[Blue]);
}

void processButtonEvents(void){
    
    if(brightnessButtonFlag){
        
        uint8_t br = currBrightness[currChannel];
        
        currBrightness[currChannel] = (br + STEP) % 255;
        
        setBrightness(currBrightness[currChannel], extLedsChannels[currChannel]); 
        
        lcdLedInfoSetValues(currBrightness[Red], currBrightness[Green], currBrightness[Blue]);
        
        brightnessButtonFlag = 0;
    }

    if(channelButtonFlag){

        switchLed(leds[currChannel], 0);
        
        currChannel = (currChannel + 1) % CHANNEL_COUNT;
        
        switchLed(leds[currChannel], 1);
        lcdLedInfoSetCurrentChannel(currChannel);
        
        channelButtonFlag = 0;
    }    
}
