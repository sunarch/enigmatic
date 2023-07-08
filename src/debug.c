/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdio.h>

#include "debug.h"
#include "util-pager.h"


// CONSTANTS ///////////////////////////////////////////////////////////////////

#define  PART_MAX_LENGTH  20


// GENERAL - COMMON ////////////////////////////////////////////////////////////

#ifndef DEBUG
static
#endif
void debug_number_unsigned_hundred(unsigned short number)
{
    printf("'");

    if (number < 100) { printf(" "); }
    if (number <  10) { printf(" "); }

    printf("%u'", number);
}


// PRIVATE /////////////////////////////////////////////////////////////////////

static void ascii_item_char_label(void)
{
    printf("       ");
}


static void ascii_item_char_formatted(char character)
{
    printf("  '%c' ", character);
}


static void ascii_item_code_label(void)
{
    printf("ASCII: ");
}


static void ascii_item_code_formatted(char character)
{
    printf(" ");
    debug_number_unsigned_hundred((unsigned short) character);
}


// GENERAL /////////////////////////////////////////////////////////////////////

void debug_print_as_ascii(char *p_text, unsigned short indent_length)
{
    pager_print(p_text,
                indent_length,
                PART_MAX_LENGTH,
                &ascii_item_char_label,
                &ascii_item_char_formatted,
                &ascii_item_code_label,
                &ascii_item_code_formatted);
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


void debug_prefix(void)
{
    printf("[DEBUG] ");
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
