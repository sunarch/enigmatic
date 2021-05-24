/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include <stdio.h>

#include "util-debug.h"

#ifdef DEBUG

signed short debug_indent_level = 0;

void print_debug_indent() {
    if (debug_indent_level > 0) {
        for (unsigned short n = 1; n <= debug_indent_level; ++n) {
            printf("|   ");
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

void print_as_ascii(char *p_text) {
    int i=0;
    printf("ASCII: ");
    while(p_text[i]!='\0'){
        printf("'%c'/'%d' ", p_text[i], p_text[i]);
        i++;
    }
    printf("\n");
}

#endif
