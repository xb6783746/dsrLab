ROOT=..

LED_LIB_DIR=$(ROOT)/led_pwm_library

SRC_DIR=src
INCLUDE_DIRS=-I include -I $(LED_LIB_DIR)/include
OUT_DIR=build

BINARY = main

#todo поикс исходников и в подпапках
PROJECT_SOURCE=$(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/handlers/*.c)
SPL_SOURCE=stm32f4xx_gpio.c stm32f4xx_rcc.c stm32f4xx_tim.c stm32f4xx_exti.c stm32f4xx_syscfg.c misc.c

PROJECT_OBJS=$(PROJECT_SOURCE:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)

LIBPATHS=-L $(LED_LIB_DIR)/build

LIBS=ledpwm
LDLIBS=$(addprefix -l, $(LIBS))
DEFS=-DBRIGHTNESS_BUTTON_LINE=0 -DCHANNEL_BUTTON_LINE=1

all: images

ledpwm:
	$(Q)$(CD) $(LED_LIB_DIR)/ && $(MAKE)

include ../Makefile.rules
