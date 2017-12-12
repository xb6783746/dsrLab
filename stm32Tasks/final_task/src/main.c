#include <main.h>
#include <init.h>
#include <button_event_handler.h>
#include <pwm_api.h>
#include <led_api.h>

int main(void) {
    
    initLeds();
    initButtons();
    initTimer();
    initInterrupts();
    systimerInit();
    initLedsPWM();
    
    initButtonEventHandler();
    
    while(1){
     
        processButtonEvents();
    }
    
}
