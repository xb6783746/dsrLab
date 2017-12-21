#include <stm32f4xx.h>
#include "i2c_wrapper.h"

#include <lcd_api.h>

#include <i2c_configuration.h>

#define BIT(x) (1 << (x))

#define LcdClearScreenCommand 0b00000001
#define LcdShiftBaseCommand   0b00000100
#define LcdDisplayBaseCommand 0b00001000
#define LcdSystemBaseCommand  0b00100000
#define LcdWriteSGRAMAddrCommand 0b01000000
#define LcdWriteDDRAMAddrCommand 0b10000000

typedef enum {

    Command, Data
} LcdPacketType;

typedef struct lcd_packet_s
{
    uint8_t lcdp_rs  : 1;
    uint8_t lcdp_rw  : 1;
    uint8_t lcdp_e   : 1;
    uint8_t lcdp_led : 1;
    uint8_t lcdp_d4  : 1;
    uint8_t lcdp_d5  : 1;
    uint8_t lcdp_d6  : 1;
    uint8_t lcdp_d7  : 1;
} lcd_packet_t;

static uint8_t lines[4];
static uint32_t gs_delay_multiplyer = 0;

static void lcdSend(LcdPacketType type, uint8_t payload);

static void lcdSendPacket(lcd_packet_t* packet);
static void lcdResetPacket(lcd_packet_t* packet);

static void lcdInitGpio(void);
static void lcdInitI2C(void);
static void initDisplay(void);
static void lcdEnableFourBitMode(void);

static void lcdSetSGRAMPosition(uint8_t addr);

static void initDelay(void);
static void s_delay_us(uint32_t us);
static void s_delay_ms(uint32_t ms);

void lcdInit() {

    lines[0] = 0;
    lines[1] = 0x40;
    lines[2] = 0x14;
    lines[3] = 0x54;

    initDelay();

    lcdInitGpio();
    lcdInitI2C();

    initDisplay();
}

void lcdClearScreen(){

    lcdSend(Command, LcdClearScreenCommand);
}

void lcdInitCursor(void){

    uint8_t command = LcdShiftBaseCommand;

    command |= BIT(1);

    lcdSend(Command, command);
}

void lcdSetDisplaySettings(char displOn, char cursorOn, char blinkOn){

    uint8_t command = LcdDisplayBaseCommand;

    if(displOn){
        
        command |= BIT(2);
    }
    
    if(cursorOn){
        
        command |= BIT(1);
    }
    
    if(blinkOn){
        
        command |= 1;
    }

    lcdSend(Command, command);

}

void lcdSetPosition(uint8_t row, uint8_t column){

    uint8_t addr = lines[row] + column;

    uint8_t command = LcdWriteDDRAMAddrCommand | addr;

    lcdSend(Command, command);
}

void lcdDefineSymbol(uint8_t number, uint8_t symbol[8]){
    
    uint8_t addr = number * 8;
    
    lcdSetSGRAMPosition(addr);
    
    for(int i = 0; i < 8; i++){
        
        lcdSend(Data, symbol[i]);
    }
}

void lcdPrintChar(char c){

    lcdSend(Data, (uint8_t)c);
}

static void lcdInitGpio(void)
{
    GPIO_InitTypeDef gpio_init;
    GPIO_StructInit(&gpio_init);

    RCC_AHB1PeriphClockCmd(I2C_GPIO_BUS, ENABLE);

    gpio_init.GPIO_Pin   = I2C_PINS;
    gpio_init.GPIO_Mode  = GPIO_Mode_AF;
    gpio_init.GPIO_OType = GPIO_OType_OD;
    gpio_init.GPIO_PuPd  = GPIO_PuPd_UP;
    gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(I2C_GPIO, &gpio_init);

    GPIO_PinAFConfig(I2C_GPIO, I2C_PINSRC_CLK, I2C_GPIO_AF);
    GPIO_PinAFConfig(I2C_GPIO, I2C_PINSRC_SDA, I2C_GPIO_AF);

    return;
}

static void lcdInitI2C(void)
{
    I2C_InitTypeDef i2c_init;
    I2C_StructInit(&i2c_init);

    RCC_APB1PeriphClockCmd(I2C_BUS, ENABLE);

    i2c_init.I2C_ClockSpeed = LCD_I2C_FREQUENCY; /* 400 kHz */
    i2c_init.I2C_Mode = I2C_Mode_I2C;
    i2c_init.I2C_DutyCycle = I2C_DutyCycle_2;
    i2c_init.I2C_Ack = I2C_Ack_Disable;
    i2c_init.I2C_OwnAddress1 = LCD_OWN_ADDRESS;
    i2c_init.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    I2C_Init(I2C, &i2c_init);

    I2C_Cmd(I2C, ENABLE);

    return;
}

static void initDisplay() {

    I2C_write_byte(I2C, LCD_I2C_ADDRESS, 0x00);

    lcdEnableFourBitMode();
    
    lcdClearScreen();

    s_delay_ms(20);

    lcdInitCursor();

    s_delay_us(50);

}

static void lcdEnableFourBitMode()
{
    lcd_packet_t packet;

    lcdResetPacket(&packet);

    packet.lcdp_d5 = 1;
    packet.lcdp_d4 = 0;

    lcdSendPacket(&packet);
    
}

static void initDelay(void)
{
    RCC_ClocksTypeDef rcc_clocks;

    RCC_GetClocksFreq(&rcc_clocks);

    gs_delay_multiplyer = rcc_clocks.HCLK_Frequency / 4000000;

}

static void lcdSetSGRAMPosition(uint8_t addr){

    uint8_t command = LcdWriteSGRAMAddrCommand | addr;

    lcdSend(Command, command);
}

static void lcdSendPacket(lcd_packet_t * packet)
{
    uint8_t * packet_payload = (uint8_t *)packet;

    packet->lcdp_led = 1;
    packet->lcdp_e = 1;

    I2C_write_byte(I2C, LCD_I2C_ADDRESS, *packet_payload);

    s_delay_us(1000);

    packet->lcdp_e = 0;

    I2C_write_byte(I2C, LCD_I2C_ADDRESS, *packet_payload);
}

static void lcdSend(LcdPacketType type, uint8_t payload){

    lcd_packet_t packet;

    lcdResetPacket(&packet);

    packet.lcdp_rw = 0;
    packet.lcdp_rs = type == Command? 0 : 1;

    packet.lcdp_d7 = (payload >> 7) & 0x01;
    packet.lcdp_d6 = (payload >> 6) & 0x01;
    packet.lcdp_d5 = (payload >> 5) & 0x01;
    packet.lcdp_d4 = (payload >> 4) & 0x01;
    lcdSendPacket(&packet);

    packet.lcdp_d7 = (payload >> 3) & 0x01;
    packet.lcdp_d6 = (payload >> 2) & 0x01;
    packet.lcdp_d5 = (payload >> 1) & 0x01;
    packet.lcdp_d4 =  payload & 0x01;
    lcdSendPacket(&packet);
}

static void lcdResetPacket(lcd_packet_t * packet)
{
    uint8_t reset_packet = 0;

    *packet = *((lcd_packet_t *)&reset_packet);
}

static void s_delay_us(uint32_t us)
{
    us = us * gs_delay_multiplyer - 10;
    while (us--);
}

static void s_delay_ms(uint32_t ms)
{
    ms = 1000 * ms * gs_delay_multiplyer - 10;
    while (ms--);
}

