/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdbool.h>
#include <stdio.h>

#include "pager.h"


int pager_print_line(char *p_text, int starting_index, int part_max_length, void (*pf_print_formatted)(char))
{
    int part_max_index = starting_index + part_max_length;
    int continue_index = part_max_index;

    int index;
    char current_character;

    index = starting_index;
    while(true) {
        current_character = p_text[index];
        if (current_character == '\0') {
            continue_index = -1;
            break;
        }
        if (index == part_max_index) {
            break;
        }
        pf_print_formatted(current_character);
        index++;
    }
    printf("\n");

    return continue_index;
}
