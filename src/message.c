/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdbool.h>
#include <string.h>

#include "alphabet.h"
#include "message.h"
#include "wheels.h"
#include "wheels-common.h"
#include "wheels-offsets.h"
#include "wheels-settings.h"

#ifdef DEBUG
    #include <stdio.h>

    #include "debug.h"
#endif


// MACRO VALUES ////////////////////////////////////////////////////////////////

#define  REPLACEMENT_CHAR  '_'


// CALCULATORS /////////////////////////////////////////////////////////////////

static char message_character_front_pass(char character, unsigned short wheel_count)
{
#ifdef DEBUG
    debug_prefix();
    debug_indent_print();
    printf("first-to-last pass / front pass\n");
#endif

    for (unsigned short i = 1; i <= wheel_count; ++i) {
        character = get_wheel_output(i, WHEEL_MODE_FRONT, character);
    }

    return character;
}


static char message_character_ukw_pass(char character)
{
#ifdef DEBUG
    debug_prefix();
    debug_indent_print();
    printf("UKW pass (same front and reverse)\n");
#endif

    character = get_wheel_output(UKW_INDEX, WHEEL_MODE_UKW, character);

    return character;
}


static char message_character_reverse_pass(char character, unsigned short wheel_count)
{
#ifdef DEBUG
    debug_prefix();
    debug_indent_print();
    printf("last-to-first pass / reverse pass\n");
#endif

    for (unsigned short i = wheel_count; i >= 1; --i) {
        character = get_wheel_output(i, WHEEL_MODE_REVERSE, character);
    }

    return character;
}


static char message_process_character(char character, unsigned short wheel_count)
{
#ifdef DEBUG
    printf("Process character '%c' over '%u' wheels\n", character, wheel_count);
    debug_indent_increment();
#endif

    // preprocess character: uppercase to lowercase, skip special

    bool letter_is_alphabetic = true;

    if (!is_alphabetic_lower(character)) {
        short index_upper = abc_index_upper(character);

        if (index_upper < 0) { // not uppercase letter
            letter_is_alphabetic = false;
        }
        else {
            letter_is_alphabetic = true;
            character = abc_lower((unsigned short) index_upper);
        }
    }

    if (!letter_is_alphabetic) {
        // only allow a period of the non-alphabetic characters
        // change all other characters to underscores
        if (character != '.') {
            character = REPLACEMENT_CHAR;
        }
    }

    if(letter_is_alphabetic) {
        character = message_character_front_pass(character, wheel_count);
        character = message_character_ukw_pass(character);
        character = message_character_reverse_pass(character, wheel_count);
    }

#ifdef DEBUG
    debug_indent_decrement();
#endif

    return character;
}


char * message_process(char *p_input_string,
                       char *p_output_string)
{
#ifdef DEBUG
    debug_prefix();
    printf("Process message\n");
#endif

    unsigned short wheel_count = get_used_wheel_count();

    unsigned long msg_len = strlen(p_input_string);

    char current_char;

    for (unsigned long n = 0; n < msg_len; ++n) {

        current_char = p_input_string[n];

        // start of character processing
    #ifdef DEBUG
        debug_prefix();
        printf("(");
        debug_number_unsigned_hundred((unsigned short) (n + 1));
        printf("./");
        debug_number_unsigned_hundred((unsigned short) msg_len);
        printf(") ");
    #endif

        current_char = message_process_character(current_char, wheel_count);

        if (current_char != REPLACEMENT_CHAR) {
            // advance wheels only after processed chars
            offsets_advance();
        }

        // move current char into output string
        // for both processed and unprocessed chars
        p_output_string[n] = current_char;

    }

    // add null terminator to output string
    p_output_string[msg_len] = '\0';

    return p_output_string;
}
