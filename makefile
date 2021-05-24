# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

.DEFAULT_GOAL = linux-release

# change recipe prefix from TAB to ">" #
.RECIPEPREFIX = >

# directories and executable file name #
SOURCE_DIR = src
OBJECT_DIR = gen-obj
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

# flags only for object targets #
C_FLAGS_OBJS_ONLY = -c

# flags only for executable target #
C_FLAGS_EXEC_ONLY = -no-pie

# linker flags (only for executable target) #
LD_FLAGS =

# determine the list of object files for the executable #
SOURCES := $(wildcard $(SOURCE_DIR)/*.c)
GEN_OBJS := $(patsubst $(SOURCE_DIR)/%.c,$(OBJECT_DIR)/%.o,$(SOURCES))

# RULES ########################################################################

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

.PHONY: linux-clean

linux-other: asm-linux

linux-setup:
>   mkdir -p $(OBJECT_DIR)
>   mkdir -p $(EXEC_DIR)

linux-clean: asm-clean-linux
>   rm $(OBJECT_DIR)/*.o
>   rmdir $(OBJECT_DIR)
>   rm $(EXEC_DIR)/$(EXEC_NAME)
>   rmdir $(EXEC_DIR)

asm-linux:
>   scripts/gen-asm-ref.sh

asm-clean-linux:
>   rm gen-asm-ref/*.s
>   rmdir gen-asm-ref

windows-other: asm-windows

windows-setup:
>   if not exist $(OBJECT_DIR) md $(OBJECT_DIR)
>   if not exist $(EXEC_DIR) md $(EXEC_DIR)

windows-clean: asm-clean-windows
>   del $(OBJECT_DIR)\*.o
>   rmdir $(OBJECT_DIR)
>   del $(EXEC_DIR)\$(EXEC_NAME)
>   rmdir $(EXEC_DIR)

asm-windows:
>   scripts\gen-asm-ref.bat

asm-clean-windows:
>   del gen-asm-ref/*.s
>   rmdir gen-asm-ref

# targets

windows-release : windows-setup $(EXEC_DIR)/$(EXEC_NAME) windows-other

linux-release : linux-setup $(EXEC_DIR)/$(EXEC_NAME) linux-other

# END ##########################################################################
