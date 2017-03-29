
#include <stdio.h>

#include "util_debug.h"

const unsigned short DEBUG = 1; // 1 for ON, 0 for OFF

signed short debug_indent_level = 0;

void print_debug_indent() {
    if (debug_indent_level > 0) {
        for (unsigned short n = 1; n <= debug_indent_level; ++n) {
            printf("    ");
        }
    }
}

void inc_debug_indent() {
    debug_indent_level += 1;
}

void dec_debug_indent() {
    if (debug_indent_level > 0) {
        debug_indent_level -= 1;
    }
}
