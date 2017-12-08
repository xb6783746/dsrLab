#include <button_event_handler.h>

extern char brightnessButtonFlag;
extern char channelButtonFlag;

static Channel* order;
static int orderCount;
static char step;

static char currBrightness;
static uint32_t currChannel;

void initButtonEventHandler(){

    step = 10;

    orderCount = 3;
    order = (Channel*)malloc(orderCount * sizeof(Channel));

    order[0] = Red;
    order[1] = Green;
    order[2] = Blue;

    currBrightness = 0;
    currChannel = 0;
}

void processButtonEvents(void){
    
    if(brightnessButtonFlag){
        
        brightnessButtonFlag = 0;
        
        currBrightness = (currBrightness + step) % 100;
        
        setBrightness(order[currChannel], currBrightness);  
    }

    if(channelButtonFlag){
        
        channelButtonFlag = 0;

        setBrightness(order[currChannel], 0);

        currChannel = (currChannel + 1) % orderCount;
        
        setBrightness(order[currChannel], currBrightness);
    }    
}

void setOrder(Channel* orderArr, uint32_t count){
    
    order = orderArr;
    orderCount = count;
}

void setStep(char val){

    step = val;
}

