# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

.DEFAULT_GOAL = linux-release

# change recipe prefix from TAB to ">" #
.RECIPEPREFIX = >

# directories and executable file name #########################################

SOURCE_DIR = src
OBJECT_DIR = gen-obj
OBJECT_DIR_DEBUG = gen-obj-debug
ASM_DIR = gen-asm
ASM_DIR_DEBUG = gen-asm-debug
EXEC_DIR = gen-bin

EXEC_NAME = enigmatic
EXEC_NAME_DEBUG = enigmatic-debug

# compiler #####################################################################

# compiler for C sources #
C_COMPILER = gcc

# basic flags ##################################################################

# flags for both object and executable targets (C standard) #
#C_FLAG_STD = -std=c90 -Wc90-c99-compat # c90 | c89 | iso9899:1990 | -ansi || gnu90 | gnu89
#C_FLAG_STD = -std=iso9899:199409 -Wc90-c99-compat
C_FLAGS_STD = -std=c99 -Wc99-c11-compat # iso9899:1999 || gnu99
#C_FLAG_STD = -std=c11 # -Wc11-c2x-compat # iso9899:2011 || gnu11
#C_FLAG_STD = -std=c17 # c18 | iso9899:2017 | iso9899:2018 || gnu17 | gnu18
#C_FLAG_STD = -std=c2x # || gnu2x

# flags for both object and executable targets #
C_FLAGS_WARNING = -Wall -Wextra -Wpedantic \
                  -Waggregate-return \
                  -Wbad-function-cast \
                  -Wcast-align \
                  -Wcast-qual \
                  -Wconversion \
                  -Wfloat-equal \
                  -Wpointer-arith \
                  -Wredundant-decls \
                  -Wshadow \
                  -Wstrict-prototypes \
                  -Wswitch-default \
                  -Wswitch-enum \
                  -Wundef \
                  -Wunreachable-code \
                  -Wwrite-strings
# to upgrade warnings to errors: -Werror

# flag components ##############################################################

C_FLAG_DEBUG = -g
C_FLAG_ENIGMATIC_DEBUG = -DDEBUG=true

C_FLAGS_DEBUG = $(C_FLAG_DEBUG) $(C_FLAG_ENIGMATIC_DEBUG)

C_FLAG_ASSEMBLY = -S
C_FLAG_NO_LINKING = -c
# Run-time buffer overflow detection, requires -O2
C_FLAG_RT_BOF_DET = -D_FORTIFY_SOURCE=2
# recommended optimization
C_FLAG_O_REC = -O2
# optimizations that don't interfere with debugging
C_FLAG_O_DEBUG = -Og

# Position Independent Executable (PIE)
C_FLAG_PIE_NO = -no-pie

# flag groups ##################################################################

# flags only for assembly targets #
C_FLAGS_ASM_RELEASE = $(C_FLAG_ASSEMBLY)
C_FLAGS_ASM_DEBUG = $(C_FLAG_ASSEMBLY) $(C_FLAGS_DEBUG)

# flags only for object targets #
C_FLAGS_OBJS_RELEASE = $(C_FLAG_NO_LINKING) $(C_FLAG_O_REC)
C_FLAGS_OBJS_DEBUG = $(C_FLAG_NO_LINKING) $(C_FLAG_O_DEBUG) $(C_FLAGS_DEBUG)

# flags only for executable target #
C_FLAGS_EXEC_RELEASE = $(C_FLAG_PIE_NO) $(C_FLAG_RT_BOF_DET)
C_FLAGS_EXEC_DEBUG = $(C_FLAG_PIE_NO)  $(C_FLAGS_DEBUG)

# linker flags (only for executable target) #
LD_FLAGS =

# file groups ##################################################################

# determine the list of object files for the executable #
SOURCES := $(wildcard $(SOURCE_DIR)/*.c)
GEN_OBJS := $(patsubst $(SOURCE_DIR)/%.c,$(OBJECT_DIR)/%.o,$(SOURCES))
GEN_OBJS_DEBUG := $(patsubst $(SOURCE_DIR)/%.c,$(OBJECT_DIR_DEBUG)/%-debug.o,$(SOURCES))
GEN_ASM := $(patsubst $(SOURCE_DIR)/%.c,$(ASM_DIR)/%.s,$(SOURCES))
GEN_ASM_DEBUG := $(patsubst $(SOURCE_DIR)/%.c,$(ASM_DIR_DEBUG)/%-debug.s,$(SOURCES))

# RULES - release ##############################################################

$(ASM_DIR)/%.s : $(SOURCE_DIR)/%.c
>   $(C_COMPILER) $< -o $@ \
        $(C_FLAGS_STD) \
        $(C_FLAGS_WARNING) \
        $(C_FLAGS_ASM_RELEASE) \

$(OBJECT_DIR)/%.o : $(SOURCE_DIR)/%.c
>   $(C_COMPILER) $< -o $@ \
        $(C_FLAGS_STD) \
        $(C_FLAGS_WARNING) \
        $(C_FLAGS_OBJS_RELEASE) \

$(EXEC_DIR)/$(EXEC_NAME) : $(GEN_OBJS)
>   $(C_COMPILER) -o $@ $^ \
        $(C_FLAGS_STD) \
        $(C_FLAGS_WARNING) \
        $(C_FLAGS_EXEC_RELEASE) \
        $(LD_FLAGS) \

# RULES - debug ################################################################

$(ASM_DIR_DEBUG)/%-debug.s : $(SOURCE_DIR)/%.c
>   $(C_COMPILER) $< -o $@ \
        $(C_FLAGS_STD) \
        $(C_FLAGS_WARNING) \
        $(C_FLAGS_ASM_DEBUG) \

$(OBJECT_DIR_DEBUG)/%-debug.o : $(SOURCE_DIR)/%.c
>   $(C_COMPILER) $< -o $@ \
        $(C_FLAGS_STD) \
        $(C_FLAGS_WARNING) \
        $(C_FLAGS_OBJS_DEBUG) \

$(EXEC_DIR)/$(EXEC_NAME_DEBUG) : $(GEN_OBJS_DEBUG)
>   $(C_COMPILER) -o $@ $^ \
        $(C_FLAGS_STD) \
        $(C_FLAGS_WARNING) \
        $(C_FLAGS_EXEC_DEBUG) \
        $(LD_FLAGS) \

################################################################################

.PHONY:

# action groups: Linux #########################################################

linux-setup:
>   mkdir -p $(ASM_DIR)
>   mkdir -p $(OBJECT_DIR)
>   mkdir -p $(EXEC_DIR)

linux-setup-debug:
>   mkdir -p $(ASM_DIR_DEBUG)
>   mkdir -p $(OBJECT_DIR_DEBUG)
>   mkdir -p $(EXEC_DIR)

linux-clean: linux-clean-release linux-clean-debug
>   rmdir $(EXEC_DIR)

linux-clean-release:
>   rm $(ASM_DIR)/*.s
>   rmdir $(ASM_DIR)
>   rm $(OBJECT_DIR)/*.o
>   rmdir $(OBJECT_DIR)
>   rm $(EXEC_DIR)/$(EXEC_NAME)

linux-clean-debug:
>   rm $(ASM_DIR_DEBUG)/*.s
>   rmdir $(ASM_DIR_DEBUG)
>   rm $(OBJECT_DIR_DEBUG)/*.o
>   rmdir $(OBJECT_DIR_DEBUG)
>   rm $(EXEC_DIR)/$(EXEC_NAME_DEBUG)

# action groups: Windows #######################################################

windows-setup:
>   @ if not exist $(ASM_DIR) md $(ASM_DIR)
>   @ if not exist $(OBJECT_DIR) md $(OBJECT_DIR)
>   @ if not exist $(EXEC_DIR) md $(EXEC_DIR)

windows-setup-debug:
>   @ if not exist $(ASM_DIR_DEBUG) md $(ASM_DIR_DEBUG)
>   @ if not exist $(OBJECT_DIR_DEBUG) md $(OBJECT_DIR_DEBUG)
>   @ if not exist $(EXEC_DIR) md $(EXEC_DIR)

windows-clean: windows-clean-release windows-clean-debug
>   rmdir $(EXEC_DIR)

windows-clean-release:
>   del $(ASM_DIR)\*.s
>   rmdir $(ASM_DIR)
>   del $(OBJECT_DIR)\*.o
>   rmdir $(OBJECT_DIR)
>   del $(EXEC_DIR)\$(EXEC_NAME).exe

windows-clean-debug:
>   del $(ASM_DIR_DEBUG)\*.s
>   rmdir $(ASM_DIR_DEBUG)
>   del $(OBJECT_DIR_DEBUG)\*.o
>   rmdir $(OBJECT_DIR_DEBUG)
>   del $(EXEC_DIR)\$(EXEC_NAME_DEBUG).exe

# targets ######################################################################

windows: windows-release windows-debug

windows-release : windows-setup $(EXEC_DIR)/$(EXEC_NAME) $(GEN_ASM)

windows-debug: windows-setup-debug $(EXEC_DIR)/$(EXEC_NAME_DEBUG) $(GEN_ASM_DEBUG)

linux: linux-release linux-debug

linux-release : linux-setup $(EXEC_DIR)/$(EXEC_NAME) $(GEN_ASM)

linux-debug: linux-setup-debug $(EXEC_DIR)/$(EXEC_NAME_DEBUG) $(GEN_ASM_DEBUG)

# END ##########################################################################
