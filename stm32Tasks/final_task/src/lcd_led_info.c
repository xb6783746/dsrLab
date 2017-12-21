#include <lcd_led_info.h>
#include <lcd_api.h>

static char channels[3];

static void printText(void);
static void printString(char* str);

void lcdLedInfoInit(void){
    
    channels[Red] = 'R';
    channels[Green] = 'G';
    channels[Blue] = 'B';
    
    lcdInit();
    
    lcdSetDisplaySettings(1,1,0);
    
    lcdPrintChar('e');
    printText();
}

void lcdLedInfoSetCurrentChannel(Channel channel){
    
    lcdSetPosition(0, 12);
    lcdPrintChar(channels[channel]);
}

void lcdLedInfoSetValues(uint8_t r, uint8_t g, uint8_t b){
    
    char buff[7];
    
    lcdSetPosition(1, 8);
    
    uint32_t val = (r << 16) + (g << 8) + b;
    sprintf(buff, "%X", val);
    
    printString(buff);
}

static void printText(void){
    
    lcdSetPosition(0, 0);
    printString("CurrChannel");
    
    lcdSetPosition(1, 0);
    printString("Color: #");
}

static void printString(char* str){
 
    while(*str){
        
        lcdPrintChar(*str);
        str++;
    }
}
