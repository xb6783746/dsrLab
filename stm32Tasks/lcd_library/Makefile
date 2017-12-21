ROOT=..

SRC_DIR=src
INCLUDE_DIRS=-I include
OUT_DIR=build

BINARY = liblcd

#todo поикс исходников и в подпапках
PROJECT_SOURCE=$(wildcard $(SRC_DIR)/*.c)
SPL_SOURCE=stm32f4xx_gpio.c stm32f4xx_rcc.c stm32f4xx_exti.c stm32f4xx_i2c.c stm32f4xx_syscfg.c misc.c

PROJECT_OBJS=$(PROJECT_SOURCE:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)

DEFS += -DUSE_I2C2

all: library

include ../Makefile.rules
