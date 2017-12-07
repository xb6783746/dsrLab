ROOT=../..

SRC_DIR=src
INCLUDE_DIRS=-I include
OUT_DIR=build

PROJECT_SOURCE=$(wildcard $(SRC_DIR)/*.c)

PROJECT_OBJS=$(PROJECT_SOURCE:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)

all: $(PROJECT_OBJS)

include $(ROOT)/Makefile.rules

DEFS += -DSTM32F40_41xxx -DUSE_STM32F4DISC_EVAL \
       -DUSE_EXT_LEDS

