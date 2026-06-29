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

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
PLATFORM ?= HOST
include sources.mk

CFLAGS= -Wall -Werror -g
CPPFLAGS= -D$(PLATFORM) $(INCLUDES)

# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs

# Platform Overrides 
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

#C to Object
%.o : %.c
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -MD -MP -o $@

#C to preprocessed
%.i : %.c
	$(CC) -E $(CFLAGS) $< $(CPPFLAGS) -o $@

#C to assembly
%.asm : %.c
	$(CC) -S $(CFLAGS) $< $(CPPFLAGS) -o $@

$(TARGET).asm : $(TARGET).out
	$(OBJDUMP) -d $< > $@

.PHONY : compile-all clean build debug

debug :
	@echo "SIZE = [$(SIZE)]"
	@echo "TARGET = [$(TARGET)]"

compile-all : $(OBJS)

build : $(TARGET).out
	$(SIZE) $(TARGET).out

$(TARGET).out : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@ -Wl,-Map=$(TARGET).map

clean : 
	rm -f *.o *.d *.i *.asm *.out *.map

-include $(DEPS)
