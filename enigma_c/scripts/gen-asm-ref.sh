#!/bin/sh

mkdir -p gen-asm-ref

gcc -g -S -o gen-asm-ref/util_debug.s \
    src/util_debug.c \
    -std=c99 -Wc99-c11-compat \
    -Wpedantic -Wall -Wextra \
    -Wcast-align -Wredundant-decls -Wbad-function-cast -Wstrict-prototypes \

gcc -g -S -o gen-asm-ref/util_validate.s \
    src/util_validate.c \
    -std=c99 -Wc99-c11-compat \
    -Wpedantic -Wall -Wextra \
    -Wcast-align -Wredundant-decls -Wbad-function-cast -Wstrict-prototypes \

gcc -g -S -o gen-asm-ref/wheels.s \
    src/wheels.c \
    -std=c99 -Wc99-c11-compat \
    -Wpedantic -Wall -Wextra \
    -Wcast-align -Wredundant-decls -Wbad-function-cast -Wstrict-prototypes \

gcc -g -S -o gen-asm-ref/usage.s \
    src/usage.c \
    -std=c99 -Wc99-c11-compat \
    -Wpedantic -Wall -Wextra \
    -Wcast-align -Wredundant-decls -Wbad-function-cast -Wstrict-prototypes \

gcc -g -S -o gen-asm-ref/enigma.s \
    src/enigma.c \
    -std=c99 -Wc99-c11-compat \
    -Wpedantic -Wall -Wextra \
    -Wcast-align -Wredundant-decls -Wbad-function-cast -Wstrict-prototypes \
