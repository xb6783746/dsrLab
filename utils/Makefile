
INCLUDE_DIR = ./include
SOURCE_DIR = ./source
OUT_DIR = ./build

CFLAGS = -g -I $(INCLUDE_DIR)

SOURCE = $(notdir $(wildcard $(SOURCE_DIR)/*.c))
OBJS = $(SOURCE:.c=.o)
	
all: $(OUT_DIR) $(OBJS) 
	echo $(OBJS)

$(OUT_DIR):
	mkdir $(OUT_DIR)

%.o:
	$(CC) $(CFLAGS) -o $(OUT_DIR)/$@ -c $(SOURCE_DIR)/$(@:.o=.c)
