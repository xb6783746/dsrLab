ROOT=..

SRC_DIR=src
INCLUDE_DIRS=-I include
OUT_DIR=build

BINARY = main

#todo поикс исходников и в подпапках
PROJECT_SOURCE=$(wildcard $(SRC_DIR)/*.c)
SPL_SOURCE=stm32f4xx_gpio.c stm32f4xx_rcc.c

PROJECT_OBJS=$(PROJECT_SOURCE:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)

all: images

include ../Makefile.rules
