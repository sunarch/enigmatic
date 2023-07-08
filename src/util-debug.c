/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdio.h>


// PRIVATE /////////////////////////////////////////////////////////////////////

static void debug_print_padding_unsigned_number(unsigned short number, unsigned long limit)
{
        unsigned long current_factor = 10;
        while (current_factor < limit) {
                if (number < current_factor) { printf(" "); }
                current_factor *= 10;
        }
}


// GENERAL /////////////////////////////////////////////////////////////////////

void debug_print_number_unsigned_limited(unsigned short number, unsigned long limit)
{
        printf("'");
        debug_print_padding_unsigned_number(number, limit);
        printf("%u'", number);
}


// DEBUG-ONLY //////////////////////////////////////////////////////////////////

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


void debug_print_prefix(void)
{
        printf("[DEBUG] ");
}


void debug_print_number_signed_tens(signed short number)
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
