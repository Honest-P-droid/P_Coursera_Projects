#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************
#Setting Default Platform as HOST
PLATFORM ?= HOST

include sources.mk

#Common Flags
CFLAGS= -Wall -Werror -g -O0 -std=c99
CPPFLAGS= -D$(PLATFORM) $(INCLUDES)

# Architecture Specific Flags
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs

# Platform Selection
ifeq ($(PLATFORM), HOST)
CC = gcc
LD = ld
SIZE = size
LDFLAGS =
OBJDUMP = objdump
endif

ifeq ($(PLATFORM), MSP432)
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
SIZE = arm-none-eabi-size
LDFLAGS = -T $(LINKER_FILE)
OBJDUMP = arm-none-eabi-objdump
CFLAGS += -mcpu=$(CPU) -mthumb -march=$(ARCH) \
	  -mfloat-abi=hard -mfpu=fpv4-sp-d16 \
	  --specs=$(SPECS) \
	  -Wno-error=attributes
endif

OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
TARGET = c1m2

#C to object (.c -> .o)
%.o : %.c
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -MD -MP -o $@

#C to preprocessed (.c -> .i)
%.i : %.c
	$(CC) -E $(CFLAGS) $< $(CPPFLAGS) -o $@

#C to assembly (.c -> .asm)
%.asm : %.c
	$(CC) -S $(CFLAGS) $< $(CPPFLAGS) -o $@

#Disassembler
$(TARGET).asm : $(TARGET).out
	$(OBJDUMP) -d $< > $@

#Phony Targets (i.e, Targets that execute regardless of whether it exists or not)
.PHONY : compile-all clean build

compile-all : $(OBJS)

build : $(TARGET).out
	$(SIZE) $(TARGET).out

#Map file target generation (Map file displays memory locations after linking)
$(TARGET).out : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@ -Wl,-Map=$(TARGET).map

#Clean target generation (Removes preprocessed, assembly, dependency, map, and object files)
clean :
	rm -f *.o *.d *.i *.asm *.out *.map

-include $(DEPS)
