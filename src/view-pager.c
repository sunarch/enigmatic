/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "view-pager.h"


// PRIVATE /////////////////////////////////////////////////////////////////////

static void pager_line_match_indent(unsigned short indent_length)
{
    for (unsigned short index = 0; index < indent_length; index++) {
        printf(" ");
    }
}


static int pager_print_line(char *p_text,
                            int starting_index,
                            int part_max_length,
                            void (*pf_print_formatted)(char))
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


// GENERAL /////////////////////////////////////////////////////////////////////

static int pager_print_part(char *p_text,
                            unsigned short indent_length,
                            int starting_index,
                            int part_max_length,
                            void (*pf_print_char_label)(void),
                            void (*pf_print_char_formatted)(char),
                            void (*pf_print_code_label)(void),
                            void (*pf_print_code_formatted)(char))
{
    int continue_index_1;
    int continue_index_2;

    pager_line_match_indent(indent_length);
    pf_print_char_label();
    continue_index_1 = pager_print_line(p_text, starting_index, part_max_length, pf_print_char_formatted);

    pager_line_match_indent(indent_length);
    pf_print_code_label();
    continue_index_2 = pager_print_line(p_text, starting_index, part_max_length, pf_print_code_formatted);

    if (continue_index_2 != continue_index_1) {
        printf("Pager print part counted chars (%d) and codes (%d) differently: \n", continue_index_1, continue_index_2);
        printf("Exiting...\n");
        exit(RETURN_CODE_ERROR);
    }

    return continue_index_2;
}


void pager_print(char *p_text,
                 unsigned short indent_length,
                 int part_max_length,
                 void (*pf_print_char_label)(void),
                 void (*pf_print_char_formatted)(char),
                 void (*pf_print_code_label)(void),
                 void (*pf_print_code_formatted)(char))
{
    int current_index = 0;

    while (current_index != -1) {
        printf("\n");
        current_index = pager_print_part(p_text,
                                         indent_length,
                                         current_index,
                                         part_max_length,
                                         pf_print_char_label,
                                         pf_print_char_formatted,
                                         pf_print_code_label,
                                         pf_print_code_formatted);
    }
}
