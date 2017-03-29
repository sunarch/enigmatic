
# change recipe prefix from TAB to ">"
.RECIPEPREFIX = >

# directories and executable file name
SOURCE_DIR = src
OBJECT_DIR = gen-obj
EXEC_DIR = gen-bin
EXEC_NAME = enigma

# compiler for C sources
C_COMPILER = gcc

# flags for both object and executable targets (C standard)
#C_FLAG_STD = -std=c90 -Wc90-c99-compat
#C_FLAG_STD = -std=iso9899:199409 -Wc90-c99-compat
C_FLAGS_STD = -std=c99 -Wc99-c11-compat
#C_FLAG_STD = -std=c11

# flags for both object and executable targets
C_FLAGS_WARNING = -Wpedantic \
                -Wall \
                -Wextra \
                -Wcast-align \
                -Wredundant-decls \
                -Wbad-function-cast \
                -Wstrict-prototypes
C_FLAGS_DEBUG = -g
C_FLAGS_OPTIMIZE = -Og

# flags for only object targets
C_FLAGS_OBJS_ONLY = -c

# flags for only executable targets
C_FLAGS_EXEC_ONLY = -no-pie

# linker flags
LD_FLAGS =

# determine the list of object files for the executable
SOURCES := $(wildcard $(SOURCE_DIR)/*.c)
GEN_OBJS := $(patsubst $(SOURCE_DIR)/%.c,$(OBJECT_DIR)/%.o,$(SOURCES))

# RULES

$(OBJECT_DIR)/%.o : $(SOURCE_DIR)/%.c
>   mkdir -p $(OBJECT_DIR)
>   $(C_COMPILER) -o $@ \
        $< \
        $(C_FLAGS_STD) \
        $(C_FLAGS_WARNING) \
        $(C_FLAGS_DEBUG) \
        $(C_FLAGS_OPTIMIZE) \
        $(C_FLAGS_OBJS_ONLY) \
        $(LD_FLAGS)

$(EXEC_DIR)/$(EXEC_NAME) : $(GEN_OBJS)
>   mkdir -p $(EXEC_DIR)
>   $(C_COMPILER) -o $@ \
        $^ \
        $(C_FLAGS_STD) \
        $(C_FLAGS_WARNING) \
        $(C_FLAGS_DEBUG) \
        $(C_FLAGS_OPTIMIZE) \
        $(C_FLAGS_EXEC_ONLY) \
        $(LD_FLAGS)

.PHONY: clean
clean:
>   rm $(OBJECT_DIR)/*.o
>   rmdir $(OBJECT_DIR)
>   rm $(EXEC_DIR)/$(EXEC_NAME)
>   rmdir $(EXEC_DIR)
