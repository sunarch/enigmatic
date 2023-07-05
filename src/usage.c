/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alphabet.h"
#include "alphabet-common.h"
#include "common.h"
#include "usage.h"
#include "wheels.h"
#include "wheels-common.h"
#include "wheels-offsets.h"
#include "wheels-settings.h"

#ifdef DEBUG
    #include "debug.h"
#endif

// MACRO VALUES ////////////////////////////////////////////////////////////////

#define  REPLACEMENT_CHAR  '_'

// CALCULATORS /////////////////////////////////////////////////////////////////

unsigned short calculate_index_after_wiring_rule(unsigned short index_before,
                                                 signed short wiring_rule)
{

    // default index_after value, to be overwritten in this function
    // any number >= 26 should produce segmentation fault
    unsigned short index_after = 31;

    signed short index_plus_rule = ((signed short) index_before) + wiring_rule;

    // modulo 26
    if (index_plus_rule >= 0) {
        index_plus_rule = index_plus_rule % ABC_LENGTH;
        index_after = (unsigned short) index_plus_rule;
    }
    else {
        index_plus_rule = (signed short) (ABC_LENGTH - (abs(index_plus_rule) % ABC_LENGTH));
        index_after = (unsigned short) index_plus_rule;
    }

    return index_after;
}

static char get_wheel_output(unsigned short wheel_number,
                             unsigned short mode,
                             char input_char)
{
#ifdef DEBUG
    debug_prefix();
    debug_indent_increment();
    debug_indent_print();
    printf("get_wheel_output (wheel ");
    debug_number_unsigned(wheel_number);
    printf(") (mode '%u') ('%c' | ", mode, input_char);
#endif

    // validate wheel_number
    validate_wheel_number(wheel_number);

    char output_char = '?';
    unsigned short wheel_offset = 0;
    unsigned short offset_index = 0;
    signed short wiring_rule = 0;

    short index = abc_index_lower(input_char);
    if(index < 0) {
        printf("Char '%c' not found in alphabet\n", input_char);
        printf("Exiting...\n");
        exit(RETURN_CODE_ERROR);
    }

    // wiring rule from offset index
    wheel_offset = offsets_get(wheel_number);
    offset_index = (index + wheel_offset) % ABC_LENGTH;
#ifdef DEBUG
    debug_number_unsigned(offset_index);
    printf(") ");
#endif

    switch(mode) {
        case WHEEL_MODE_UKW:
            // use the WHEEL_MODE_FRONT method for WHEEL_MODE_UKW
            // front and reverse should be same for UKW
            // no break.
        case WHEEL_MODE_FRONT:
            wiring_rule = get_wheel_wiring_rules_front(wheel_number)[offset_index];
            break;
        case WHEEL_MODE_REVERSE:
            wiring_rule = get_wheel_wiring_rules_reverse(wheel_number)[offset_index];
            break;
        default:
            exit(RETURN_CODE_ERROR);
    }

#ifdef DEBUG
    printf(" -> (");
    debug_number_unsigned(wheel_offset);
    printf(") ");
    debug_number_signed(wiring_rule);
#endif

    // index after wiring rule applied
    //index = (unsigned short) (((signed short) index + wiring_rule) % 26);
    index = calculate_index_after_wiring_rule(index, wiring_rule);
#ifdef DEBUG
    printf(" -> (");
    debug_number_signed(index);
#endif

    // output char
    output_char = abc_lower(index);
#ifdef DEBUG
    printf(" | '%c')\n", output_char);
    debug_indent_decrement();
#endif

    return output_char;
}


static char process_character(char character, unsigned short wheel_count)
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
            character = abc_lower(index_upper);
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

        // first-to-last pass / front pass
    #ifdef DEBUG
        debug_prefix();
        debug_indent_print();
        printf("first-to-last pass / front pass\n");
    #endif
        for (unsigned short n = 1; n <= wheel_count; ++n) {
            character = get_wheel_output(n, WHEEL_MODE_FRONT, character);
        }

        // UKW pass (same front and reverse)
    #ifdef DEBUG
        debug_prefix();
        debug_indent_print();
        printf("UKW pass (same front and reverse)\n");
    #endif
        character = get_wheel_output(UKW_INDEX, WHEEL_MODE_UKW, character);

        // last-to-first pass / reverse pass
    #ifdef DEBUG
        debug_prefix();
        debug_indent_print();
        printf("last-to-first pass / reverse pass\n");
    #endif
        for (unsigned short n = wheel_count; n >= 1; --n) {
            character = get_wheel_output(n, WHEEL_MODE_REVERSE, character);
        }
    }

#ifdef DEBUG
    debug_indent_decrement();
#endif

    return character;
}


char * process_message(char *p_input_string,
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
        debug_number_unsigned_hundred(n + 1);
        printf("./");
        debug_number_unsigned_hundred(msg_len);
        printf(") ");
    #endif

        current_char = process_character(current_char, wheel_count);

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
