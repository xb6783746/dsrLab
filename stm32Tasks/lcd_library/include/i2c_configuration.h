#ifndef I2C_CONFIGURATION
#define I2C_CONFIGURATION

#ifdef USE_I2C1

    #define I2C               I2C1
    #define I2C_BUS           RCC_APB1Periph_I2C1
    #define I2C_GPIO_BUS      RCC_AHB1Periph_GPIOB
    #define I2C_GPIO          GPIOB
    #define I2C_PINS          (GPIO_Pin_6 | GPIO_Pin_7)
    #define I2C_GPIO_AF       GPIO_AF_I2C1
    #define I2C_PINSRC_CLK    GPIO_PinSource6
    #define I21_PINSRC_SDA    GPIO_PinSource7

#elif defined USE_I2C2

    #define I2C               I2C2
    #define I2C_BUS           RCC_APB1Periph_I2C2
    #define I2C_GPIO_BUS      RCC_AHB1Periph_GPIOB
    #define I2C_GPIO          GPIOB
    #define I2C_PINS          (GPIO_Pin_10 | GPIO_Pin_11)
    #define I2C_GPIO_AF       GPIO_AF_I2C2
    #define I2C_PINSRC_CLK    GPIO_PinSource10    
    #define I2C_PINSRC_SDA    GPIO_PinSource11

#else

    #error "I2C is not defined"
#endif

#define LCD_I2C_ADDRESS (0x27)
#define LCD_I2C_FREQUENCY 400000
#define LCD_OWN_ADDRESS  0x15
#endif
