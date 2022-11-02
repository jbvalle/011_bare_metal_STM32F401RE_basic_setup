# Binaries
CC = arm-none-eabi-gcc

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
SUP_DIR = startup
DEB_DIR = debug

# Files 
SRC := $(wildcard $(SRC_DIR)/*.c)
SRC += $(wildcard $(SUP_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(SRC_DIR)/$(OBJ_DIR)/%.o, $(SRC))
OBJ := $(patsubst $(SUP_DIR)/%.c, $(SRC_DIR)/$(OBJ_DIR)/%.o, $(OBJ))
LD := $(wildcard $(SUP_DIR)/*.ld)

# FLAGS
MARCH = cortex-m4
CFLAGS = -g -Wall -mcpu=$(MARCH) -mthumb -mfloat-abi=soft -I$(INC_DIR) -ffreestanding -nostartfiles
LFLAGS = -nostdlib -T $(LD) -Wl,-Map=$(DEB_DIR)/main.map

#PATHS
OPENOCD_INTERFACE = /usr/share/openocd/scripts/interface/stlink-v2.cfg
OPENOCD_TARGET = /usr/share/openocd/scripts/target/stm32f4x.cfg

# Targets
TARGET = $(DEB_DIR)/main.elf

all: $(OBJ) $(TARGET)

$(SRC_DIR)/$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | mkobj
	$(CC) $(CFLAGS) -c -o $@ $^

$(SRC_DIR)/$(OBJ_DIR)/%.o : $(SUP_DIR)/%.c | mkobj
	$(CC) $(CFLAGS) -c -o $@ $^

$(TARGET) : $(OBJ) | mkdeb
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^

mkobj:
	mkdir -p $(SRC_DIR)/$(OBJ_DIR)

mkdeb:
	mkdir -p $(DEB_DIR)

flash: FORCE
	openocd -f $(OPENOCD_INTERFACE) -f $(OPENOCD_TARGET) &
	gdb-multiarch $(TARGET) -x $(SUP_DIR)/flash.gdb

debug: FORCE
	openocd -f $(OPENOCD_INTERFACE) -f $(OPENOCD_TARGET) &
	gdb-multiarch $(TARGET) -x $(SUP_DIR)/debug.gdb

edit: FORCE
	vim -S Session.vim

doxy: FORCE
	cd ./docs && doxygen Doxyfile

clean: FORCE
	rm -rf $(SRC_DIR)/$(OBJ_DIR) $(DEB_DIR)

FORCE:

.PHONY = mkobj mkdeb clean FORCE flash debug edit doxy
