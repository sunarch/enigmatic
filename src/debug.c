/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <stdio.h>

#include "debug.h"


void debug_print_as_ascii(char *p_text)
{
    int index = 0;
    printf("ASCII: ");
    while(p_text[index] != '\0') {
        printf("'%c'/'%d' ", p_text[index], p_text[index]);
        index++;
    }
    printf("\n");
}


#ifdef DEBUG

static signed short debug_indent_level = 0;


void debug_indent_print(void)
{
    if (debug_indent_level > 0) {
        for (unsigned short n = 1; n <= debug_indent_level; ++n) {
            printf("|   ");
        }
    }
}


void debug_indent_increment(void) {
    debug_indent_level += 1;
}


void debug_indent_decrement(void) {
    if (debug_indent_level > 0) {
        debug_indent_level -= 1;
    }
}


void debug_prefix(void)
{
    printf("[DEBUG] ");
}


void debug_number_unsigned_hundred(unsigned short number)
{
    printf("'");

    if (number < 100) { printf(" "); }
    if (number <  10) { printf(" "); }

    printf("%u'", number);
}


void debug_number_unsigned(unsigned short number)
{
    printf("'");

    if (number < 10) { printf(" "); }

    printf("%u'", number);
}


void debug_number_signed(signed short number)
{
    printf("'");

    if (number < -9) { }
    else if (number < 0 || number > 9) {
        printf(" ");
    }
    else {
        printf("  ");
    }

    printf("%d'", number);
}

#endif
