#!/usr/bin/env bash

# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.


mkdir -p gen-asm-ref

gcc -g -S -o gen-asm-ref/util-debug.s \
    src/util-debug.c \
    -std=c99 -Wc99-c11-compat \
    -Wpedantic -Wall -Wextra \
    -Wcast-align -Wredundant-decls -Wbad-function-cast -Wstrict-prototypes \

gcc -g -S -o gen-asm-ref/util-validate.s \
    src/util-validate.c \
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
