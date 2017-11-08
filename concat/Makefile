
LIB_DIR = ../utils
LIB_INCLUDE_DIR = $(LIB_DIR)/include
LIBS = linked_list.o line_reader.o
LIBS_OUT_DIR = $(LIB_DIR)/build
LIBS_OBJ = $(addprefix $(LIBS_OUT_DIR)/, $(LIBS))

TARGET = concat.out

INCLUDE_DIR = ./include
SOURCE_DIR = ./source
OUT_DIR = ./build

CFLAGS = -g -I $(INCLUDE_DIR) -I $(LIB_INCLUDE_DIR)

SOURCE = $(notdir $(wildcard $(SOURCE_DIR)/*.c))
OBJS = $(SOURCE:.c=.o)

.PHONY: all clean

all: $(OUT_DIR) $(OBJS) libs
	$(CC) $(CFLAGS) -o $(OUT_DIR)/$(TARGET) $(addprefix $(OUT_DIR)/, $(OBJS)) $(LIBS_OBJ)
	
clean:
	rm -r $(OUT_DIR)/*

%.o:
	$(CC) $(CFLAGS) -o $(OUT_DIR)/$@ -c $(SOURCE_DIR)/$(@:.o=.c)
	
$(OUT_DIR):
	mkdir $(OUT_DIR)

libs:
	cd $(LIB_DIR) && $(MAKE)
