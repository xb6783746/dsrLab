#ifndef LCD_API
#define LCD_API

#include <stdint.h>

void lcdInit(void);

void lcdClearScreen(void);
void lcdInitCursor(void);
void lcdSetDisplaySettings(char displOn, char cursorOn, char blinkOn);
void lcdSetPosition(uint8_t row, uint8_t column);

void lcdDefineSymbol(uint8_t number, uint8_t symbol[8]);

void lcdPrintChar(char c);

#endif
