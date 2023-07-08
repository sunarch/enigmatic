/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdio.h>

#include "util-debug.h"
#include "view-ascii.h"
#include "view-pager.h"


// CONSTANTS ///////////////////////////////////////////////////////////////////

#define  PART_MAX_LENGTH  20

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

void ascii_print(char *p_text, unsigned short indent_length)
{
    pager_print(p_text,
                indent_length,
                PART_MAX_LENGTH,
                &ascii_item_char_label,
                &ascii_item_char_formatted,
                &ascii_item_code_label,
                &ascii_item_code_formatted);
}
