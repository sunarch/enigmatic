/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdbool.h>
#include <string.h>

#include "message.h"
#include "util-abc.h"
#include "wheels.h"


#ifdef DEBUG
#include <stdio.h>
#include "util-debug.h"
#endif


// MACRO VALUES ////////////////////////////////////////////////////////////////

#define  SEPARATOR_CHARACTER    '.'
#define  REPLACEMENT_CHARACTER  '_'


// CALCULATORS /////////////////////////////////////////////////////////////////

static char message_process_char(char character)
{
#ifdef DEBUG
        printf("Process character '%c'\n", character);
        debug_indent_increment();
#endif

        // preprocess character: uppercase to lowercase, skip special

        bool letter_is_alphabetic = true;

        if (!abc_is_valid_char_lower(character)) {
                short index_upper = abc_index_from_char_upper(character);

                if (index_upper < 0) { // not uppercase letter
                        letter_is_alphabetic = false;
                }
                else {
                        letter_is_alphabetic = true;
                        character = abc_char_lower_from_index((unsigned short) index_upper);
                }
        }

        if (!letter_is_alphabetic) {
                // only allow a period of the non-alphabetic characters
                // change all other characters to underscores
                if (character != SEPARATOR_CHARACTER) {
                        character = REPLACEMENT_CHARACTER;
                }
        }

        if (letter_is_alphabetic) {
                character = wheels_get_output(character);
        }

#ifdef DEBUG
        debug_indent_decrement();
#endif

        return character;
}


void message_process(char *p_input_string,
                     char *p_output_string)
{
#ifdef DEBUG
        debug_print_prefix();
        printf("Process message\n");
#endif

        unsigned long msg_len = strlen(p_input_string);

        char current_char;

        for (unsigned long n = 0; n < msg_len; ++n) {

                current_char = p_input_string[n];

#ifdef DEBUG
                debug_print_prefix();
                printf("(");
                debug_print_number_unsigned_limited((unsigned short) (n + 1), msg_len);
                printf("./");
                debug_print_number_unsigned_limited((unsigned short) msg_len, msg_len);
                printf(") ");
#endif

                p_output_string[n] = message_process_char(current_char);
        }

        // add null terminator to output string
        p_output_string[msg_len] = '\0';
}
