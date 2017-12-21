#ifndef LCD_LED_INFO
#define LCD_LED_INFO

#include <stm32f4xx.h>
#include <led_api.h>

void lcdLedInfoInit(void);

void lcdLedInfoSetCurrentChannel(Channel channel);
void lcdLedInfoSetValues(uint8_t r, uint8_t g, uint8_t b);
#endif
