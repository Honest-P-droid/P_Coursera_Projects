#Conditional statement for Host file selection
ifeq ($(PLATFORM),HOST)
	SOURCES = memory.c main.c
	INCLUDES = -I ../include/common
endif

#Conditional statement for MSP file selection
ifeq ($(PLATFORM),MSP432)
	SOURCES = main.c memory.c system_msp432p401r.c interrupts_msp432p401r_gcc.c startup_msp432p401r_gcc.c
	INCLUDES = -I ../include/common -I ../include/msp432 -I ../include/CMSIS
endif
 
