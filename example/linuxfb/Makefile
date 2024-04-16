###### Makefile ######

######################################
# target
######################################
TARGET = test


######################################
# building variables
######################################
# debug build?
DEBUG = 0
# optimization
OPT = -O2#-flto

######################################
# source
######################################
SGL_DIR = ../../source
# C sources
C_SOURCES =  \
framebuffer.c \
$(wildcard $(TARGET)/*.c)  \
$(wildcard $(SGL_DIR)/*.c)  \
$(wildcard $(SGL_DIR)/core/*.c)  \
$(wildcard $(SGL_DIR)/draw/*.c)  \
$(wildcard $(SGL_DIR)/fonts/*.c)  \
$(wildcard $(SGL_DIR)/widget/*.c)  \


# C defines
C_DEFS = -D
# AS includes
AS_INCLUDES = 

# C includes
C_INCLUDES =     \
-I.              \
-I$(TARGET)    \
-I$(SGL_DIR)    \
-I$(SGL_DIR)/core    \
-I$(SGL_DIR)/draw  \
-I$(SGL_DIR)/fonts   \
-I$(SGL_DIR)/widget   \


BUILD_DIR    := obj
#######################################
# Compiler Setting
#######################################
PREFIX =aarch64-linux-
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
AR = $(PREFIX)ar
SZ = $(PREFIX)size
OD = $(PREFIX)objdump
HEX =$(CP) -O ihex
BIN =$(CP) -O binary -S

LIB_DIR = \
-Llibsdl/lib  \
-Llibsdl/bin  \

LIBS    = \

LIB_OPT =

CFLAGS := -Wall  $(C_INCLUDES)  

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2 
endif

# libraries
#LIBS = -lc_nano -lm
LDFLAGS = $(OPT)   $(LIB_DIR) $(LIB_OPT) $(LIBS)

# default action: build all
all: $(TARGET).exe

#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))


$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	@echo "CC $<"
	@$(CC) -c $(CFLAGS) -MMD -MP \
		-MF  $(BUILD_DIR)/$(notdir $(<:.c=.d)) \
		-Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(TARGET).exe: $(OBJECTS) Makefile
	@echo "LD $@"
	@$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	@echo "SIZE $@"
	@$(SZ)  $@

$(BUILD_DIR):
	mkdir $@

#######################################
# clean up
#######################################

clean:
	rm -fR $(BUILD_DIR)