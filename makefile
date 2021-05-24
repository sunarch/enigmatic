# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

.DEFAULT_GOAL = linux-release

# change recipe prefix from TAB to ">" #
.RECIPEPREFIX = >

# directories and executable file name #
SOURCE_DIR = src
OBJECT_DIR = gen-obj
OBJECT_DIR_DEBUG = gen-obj-debug
ASM_DIR = gen-asm
ASM_DIR_DEBUG = gen-asm-debug
EXEC_DIR = gen-bin

EXEC_NAME = enigmatic
EXEC_NAME_DEBUG = enigmatic-debug

# compiler for C sources #
C_COMPILER = gcc

# flags for both object and executable targets (C standard) #
#C_FLAG_STD = -std=c90 -Wc90-c99-compat
#C_FLAG_STD = -std=iso9899:199409 -Wc90-c99-compat
C_FLAGS_STD = -std=c99 -Wc99-c11-compat
#C_FLAG_STD = -std=c11

# flags for both object and executable targets #
C_FLAGS_WARNING = -Wpedantic \
                -Wall \
                -Wextra \
                -Wcast-align \
                -Wredundant-decls \
                -Wbad-function-cast \
                -Wstrict-prototypes
C_FLAGS_DEBUG = -g
C_FLAGS_PROG_DEBUG = -DDEBUG=true
C_FLAGS_OPTIMIZE = -Og

# flags only for assembly targets #
C_FLAGS_ASM_ONLY = -S

# flags only for object targets #
C_FLAGS_OBJS_ONLY = -c

# flags only for executable target #
C_FLAGS_EXEC_ONLY = -no-pie

# linker flags (only for executable target) #
LD_FLAGS =

# determine the list of object files for the executable #
SOURCES := $(wildcard $(SOURCE_DIR)/*.c)
GEN_OBJS := $(patsubst $(SOURCE_DIR)/%.c,$(OBJECT_DIR)/%.o,$(SOURCES))
GEN_OBJS_DEBUG := $(patsubst $(SOURCE_DIR)/%.c,$(OBJECT_DIR_DEBUG)/%-debug.o,$(SOURCES))
GEN_ASM := $(patsubst $(SOURCE_DIR)/%.c,$(ASM_DIR)/%.s,$(SOURCES))
GEN_ASM_DEBUG := $(patsubst $(SOURCE_DIR)/%.c,$(ASM_DIR_DEBUG)/%-debug.s,$(SOURCES))

# RULES - release ##############################################################

$(ASM_DIR)/%.s : $(SOURCE_DIR)/%.c
>   $(C_COMPILER) -o $@ \
        $< \
        $(C_FLAGS_STD) \
        $(C_FLAGS_WARNING) \
        $(C_FLAGS_DEBUG) \
        $(C_FLAGS_ASM_ONLY) \

$(OBJECT_DIR)/%.o : $(SOURCE_DIR)/%.c
>   $(C_COMPILER) -o $@ \
        $< \
        $(C_FLAGS_STD) \
        $(C_FLAGS_WARNING) \
        $(C_FLAGS_DEBUG) \
        $(C_FLAGS_OPTIMIZE) \
        $(C_FLAGS_OBJS_ONLY) \

$(EXEC_DIR)/$(EXEC_NAME) : $(GEN_OBJS)
>   $(C_COMPILER) -o $@ \
        $^ \
        $(C_FLAGS_STD) \
        $(C_FLAGS_WARNING) \
        $(C_FLAGS_DEBUG) \
        $(C_FLAGS_OPTIMIZE) \
        $(C_FLAGS_EXEC_ONLY) \
        $(LD_FLAGS) \

# RULES - debug ################################################################

$(ASM_DIR_DEBUG)/%-debug.s : $(SOURCE_DIR)/%.c
>   $(C_COMPILER) -o $@ \
        $< \
        $(C_FLAGS_STD) \
        $(C_FLAGS_WARNING) \
        $(C_FLAGS_DEBUG) \
        $(C_FLAGS_PROG_DEBUG) \
        $(C_FLAGS_ASM_ONLY) \

$(OBJECT_DIR_DEBUG)/%-debug.o : $(SOURCE_DIR)/%.c
>   $(C_COMPILER) -o $@ \
        $< \
        $(C_FLAGS_STD) \
        $(C_FLAGS_WARNING) \
        $(C_FLAGS_DEBUG) \
        $(C_FLAGS_PROG_DEBUG) \
        $(C_FLAGS_OPTIMIZE) \
        $(C_FLAGS_OBJS_ONLY) \

$(EXEC_DIR)/$(EXEC_NAME_DEBUG) : $(GEN_OBJS_DEBUG)
>   $(C_COMPILER) -o $@ \
        $^ \
        $(C_FLAGS_STD) \
        $(C_FLAGS_WARNING) \
        $(C_FLAGS_DEBUG) \
        $(C_FLAGS_PROG_DEBUG) \
        $(C_FLAGS_OPTIMIZE) \
        $(C_FLAGS_EXEC_ONLY) \
        $(LD_FLAGS) \

################################################################################

.PHONY:

linux-setup:
>   mkdir -p $(ASM_DIR)
>   mkdir -p $(OBJECT_DIR)
>   mkdir -p $(EXEC_DIR)

linux-setup-debug:
>   mkdir -p $(ASM_DIR_DEBUG)
>   mkdir -p $(OBJECT_DIR_DEBUG)
>   mkdir -p $(EXEC_DIR)

linux-clean-all: linux-clean linux-clean-debug

linux-clean:
>   rm $(ASM_DIR)/*.s
>   rmdir $(ASM_DIR)
>   rm $(OBJECT_DIR)/*.o
>   rmdir $(OBJECT_DIR)
>   rm $(EXEC_DIR)/*
>   rmdir $(EXEC_DIR)

linux-clean-debug:
>   rm $(ASM_DIR_DEBUG)/*.s
>   rmdir $(ASM_DIR_DEBUG)
>   rm $(OBJECT_DIR_DEBUG)/*.o
>   rmdir $(OBJECT_DIR_DEBUG)
>   rm $(EXEC_DIR)/*
>   rmdir $(EXEC_DIR)

windows-setup:
>   if not exist $(ASM_DIR) md $(ASM_DIR)
>   if not exist $(OBJECT_DIR) md $(OBJECT_DIR)
>   if not exist $(EXEC_DIR) md $(EXEC_DIR)

windows-setup-debug:
>   if not exist $(ASM_DIR_DEBUG) md $(ASM_DIR_DEBUG)
>   if not exist $(OBJECT_DIR_DEBUG) md $(OBJECT_DIR_DEBUG)
>   if not exist $(EXEC_DIR) md $(EXEC_DIR)

windows-clean-all: windows-clean windows-clean-debug

windows-clean:
>   del $(ASM_DIR)\*.s
>   rmdir $(ASM_DIR)
>   del $(OBJECT_DIR)\*.o
>   rmdir $(OBJECT_DIR)
>   del $(EXEC_DIR)\*.exe
>   rmdir $(EXEC_DIR)

windows-clean-debug:
>   del $(ASM_DIR_DEBUG)\*.s
>   rmdir $(ASM_DIR_DEBUG)
>   del $(OBJECT_DIR_DEBUG)\*.o
>   rmdir $(OBJECT_DIR_DEBUG)
>   del $(EXEC_DIR)\*.exe
>   rmdir $(EXEC_DIR)

# targets

windows: windows-release windows-debug

windows-release : windows-setup $(EXEC_DIR)/$(EXEC_NAME) $(GEN_ASM)

windows-debug: windows-setup-debug $(EXEC_DIR)/$(EXEC_NAME_DEBUG) $(GEN_ASM_DEBUG)

linux: linux-release linux-debug

linux-release : linux-setup $(EXEC_DIR)/$(EXEC_NAME) $(GEN_ASM)

linux-debug: linux-setup-debug $(EXEC_DIR)/$(EXEC_NAME_DEBUG) $(GEN_ASM_DEBUG)

# END ##########################################################################
