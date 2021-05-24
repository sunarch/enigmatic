# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

.DEFAULT_GOAL = linux-release

# change recipe prefix from TAB to ">" #
.RECIPEPREFIX = >

# directories and executable file name #
SOURCE_DIR = src
OBJECT_DIR = gen-obj
ASM_DIR = gen-asm-ref
EXEC_DIR = gen-bin

EXEC_NAME = enigmatic
EXEC_NAME_WINDOWS = enigmatic.exe

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
GEN_ASM := $(patsubst $(SOURCE_DIR)/%.c,$(ASM_DIR)/%.s,$(SOURCES))

# RULES ########################################################################

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

.PHONY:

linux-setup:
>   mkdir -p $(ASM_DIR)
>   mkdir -p $(OBJECT_DIR)
>   mkdir -p $(EXEC_DIR)

linux-clean:
>   rm $(ASM_DIR)/*.s
>   rmdir $(ASM_DIR)
>   rm $(OBJECT_DIR)/*.o
>   rmdir $(OBJECT_DIR)
>   rm $(EXEC_DIR)/$(EXEC_NAME)
>   rmdir $(EXEC_DIR)

windows-setup:
>   if not exist $(ASM_DIR) md $(ASM_DIR)
>   if not exist $(OBJECT_DIR) md $(OBJECT_DIR)
>   if not exist $(EXEC_DIR) md $(EXEC_DIR)

windows-clean:
>   del $(ASM_DIR)\*.s
>   rmdir $(ASM_DIR)
>   del $(OBJECT_DIR)\*.o
>   rmdir $(OBJECT_DIR)
>   del $(EXEC_DIR)\$(EXEC_NAME)
>   rmdir $(EXEC_DIR)

# targets

windows-release : windows-setup $(EXEC_DIR)/$(EXEC_NAME) $(GEN_ASM)

linux-release : linux-setup $(EXEC_DIR)/$(EXEC_NAME) $(GEN_ASM)

# END ##########################################################################
