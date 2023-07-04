/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "usage.h"
#include "wheels.h"
#include "util-validate.h"

#ifdef DEBUG
    #include "util-debug.h"
#endif


unsigned short calculate_index_after_wiring_rule(unsigned short index_before,
                                                        signed short wiring_rule)
{

    // default index_after value, to be overwritten in this function
    // any number >= 26 should produce segmentation fault
    unsigned short index_after = 31;

    signed short index_plus_rule = ((signed short) index_before) + wiring_rule;

    // modulo 26
    if (index_plus_rule >= 0) {
        index_plus_rule = index_plus_rule % 26;
        index_after = (unsigned short) index_plus_rule;
    }
    else {
        index_plus_rule = (signed short) (26 - (abs(index_plus_rule) % 26));
        index_after = (unsigned short) index_plus_rule;
    }

    return index_after;
}

static char get_wheel_output(unsigned short wheel_number,
                             unsigned short mode,
                             char input_char)
{
    #ifdef DEBUG
        debug_indent_increment();  // to function call level
        debug_indent_print();
        printf("FUNC: char get_wheel_output(...) // unsigned short wheel_number = '%u' // unsigned short mode = '%u' // char input_char = '%c'\n", wheel_number, mode, input_char);
        debug_indent_increment();  // to function result level
    #endif

    // validate wheel_number
    validate_wheel_number_any(wheel_number, get_used_wheel_count());

    char output_char = '?';
    char *p_occurence;
    unsigned short index = 0;
    unsigned short wheel_offset = 0;
    unsigned short offset_index = 0;
    signed short wiring_rule = 0;

    // index from input (input char location in wiring alphabet)
    p_occurence = strchr(ABC_LOW, input_char);
    if(p_occurence == NULL) {
        printf("Failed check with (p_occurence == NULL): (%p == NULL)\n", p_occurence);
        printf("Exiting...\n");
        exit(1);
    }
    index = p_occurence - ABC_LOW;
    if (index >= 26) {
        printf("Failed check with (index >= 26): (%u >= 26)\n", index);
        printf("Exiting...\n");
        exit(1);
    }
    #ifdef DEBUG
        debug_indent_print();
        printf("index of input char in alphabet // '%u' // <= input_char\n", index);
    #endif

    // wiring rule from offset index
    wheel_offset = get_wheel_offset(wheel_number);
    offset_index = (index + wheel_offset) % 26;
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
            exit(1);
    }
    #ifdef DEBUG
        debug_indent_print();
        printf("wheel offset for wheel '%u' // '%u'\n", wheel_number, wheel_offset);
        debug_indent_print();
        printf("wiring rule from offset index // '%d'\n", wiring_rule);
    #endif

    // index after wiring rule applied
    //index = (unsigned short) (((signed short) index + wiring_rule) % 26);
    index = calculate_index_after_wiring_rule(index, wiring_rule);
    #ifdef DEBUG
        debug_indent_print();
        printf("index after wiring rule applied // '%u' // => output_char\n", index);
    #endif

    // output char
    output_char = ABC_LOW[index];

    #ifdef DEBUG
        debug_indent_print();
        printf("RETURN // output_char = '%c'\n", output_char);
        debug_indent_decrement();  // to function call level
        debug_indent_decrement();  // to caller level
    #endif

    return output_char;
}

static void turn_wheel(unsigned short wheel_number)
{
    #ifdef DEBUG
        debug_indent_increment();  // to function call level
        debug_indent_print();
        printf("FUNC: void turn_wheel(...) // unsigned short wheel_number = '%u'\n", wheel_number);
    #endif

    // validate wheel_number
    validate_wheel_number_any(wheel_number, get_used_wheel_count());

    // move wheel offset by 1
    set_wheel_offset(wheel_number, ((get_wheel_offset(wheel_number) + 1) % 26));

    #ifdef DEBUG
        // CHECK included in setter function
        debug_indent_decrement();  // to caller level
    #endif
}


static void advance_wheels(void)
{
    #ifdef DEBUG
        debug_indent_increment();  // to function call level
        debug_indent_print();
        printf("FUNC: void advance_wheels(void)\n");
    #endif

    unsigned short wheel_count = get_used_wheel_count();
    unsigned short current_wheel_offset = 0;

    for (unsigned short n = 1; n <= wheel_count; ++n) {
        current_wheel_offset = get_wheel_offset(n);

        if (current_wheel_offset < 25) {
            turn_wheel(n);
            break;
        }
        else if (current_wheel_offset == 25) {
            turn_wheel(n);
            continue;
        }
        else {
            exit(1);
        }
    }

    #ifdef DEBUG
        debug_indent_increment();  // to function result level
        current_wheel_offset = get_wheel_offset(0); // use var current_wheel_offset from this function
        debug_indent_print();
        printf("CHECK: get_wheel_offset(...) // wheel_number = 0 // '%u' // should always be 0 (UKW)\n", current_wheel_offset);
        for (unsigned short n = 1; n <= wheel_count; ++n) {
            current_wheel_offset =  get_wheel_offset(n); // use var current_wheel_offset from this function
            debug_indent_print();
            printf("CHECK: get_wheel_offset(...) // wheel_number = '%u' // '%u'\n", n, current_wheel_offset);
        }
        debug_indent_decrement();  // to function call level
        debug_indent_decrement();  // to caller level
    #endif
}

char * process_message(char *p_input_string,
                       char *p_output_string)
{
    #ifdef DEBUG
        debug_indent_increment(); // to function outer level
        debug_indent_print();
        printf("FUNC: char *process_message(...) // char *p_input_string = '%s'\n", p_input_string);
        debug_indent_increment(); // to function inner level
    #endif

    unsigned short wheel_count = get_used_wheel_count();

    unsigned long msg_len = strlen(p_input_string);

    char current_char = '?';
    bool letter_is_alphabetic = false;

    for (unsigned long n = 0; n < msg_len; ++n) {

        current_char = p_input_string[n];

        // start of character processing
        #ifdef DEBUG
            debug_indent_print();
            printf("%lu./%lu  CHAR to be processed: '%c'\n", (n + 1), (msg_len), current_char);
            debug_indent_increment(); // to character processing inner level
        #endif

        // preprocess character: uppercase to lowercase, skip special
        unsigned short index;
        char *p_occurence;

        p_occurence = strchr(ABC_LOW, current_char);
        if(p_occurence == NULL) { // character not in uppercase alphabet

            p_occurence = strchr(ABC_UPP, current_char);
            if(p_occurence == NULL) { // character not in uppercase alphabet

                // only allow a period of the non-alphabetic characters
                // change all other characters to underscores
                if (current_char != '.') {
                    current_char = '_';
                }
                // put character through without processing
                letter_is_alphabetic = false;
            }
            else { // uppercase character: convert to lowercase
                index = p_occurence - ABC_UPP;
                current_char = ABC_LOW[index];
                letter_is_alphabetic = true;
            }
        }
        else { // lowercase character: proceed normally
            letter_is_alphabetic = true;
        }

        if(letter_is_alphabetic) {

            // first-to-last pass / front pass
            #ifdef DEBUG
                debug_indent_print();
                printf("first-to-last pass / front pass\n");
            #endif
            for (unsigned short n = 1; n <= wheel_count; ++n) {
                current_char = get_wheel_output(n, WHEEL_MODE_FRONT, current_char);
            }

            // UKW pass (same front and reverse)
            #ifdef DEBUG
                debug_indent_print();
                printf("UKW pass (same front and reverse)\n");
            #endif
            current_char = get_wheel_output(UKW_INDEX, WHEEL_MODE_UKW, current_char);

            // last-to-first pass / reverse pass
            #ifdef DEBUG
                debug_indent_print();
                printf("last-to-first pass / reverse pass\n");
            #endif
            for (unsigned short n = wheel_count; n >= 1; --n) {
                current_char = get_wheel_output(n, WHEEL_MODE_REVERSE, current_char);
            }

            // advance wheels only after processed chars
            advance_wheels();
        }

        // end of character processing
        #ifdef DEBUG
            debug_indent_decrement(); // to function inner level
            debug_indent_print();
            printf("%lu./%lu  CHAR after processing: '%c'\n", (n + 1), (msg_len), current_char);
        #endif

        // move current char into output string
        // for both processed and unprocessed chars
        p_output_string[n] = current_char;

    }

    // add null terminator to output string
    p_output_string[msg_len] = '\0';

    #ifdef DEBUG
        debug_indent_print();
        printf("RETURN // p_output_string = '%s'\n", p_output_string);
        debug_indent_decrement(); // to function outer level
        debug_indent_decrement(); // to caller level
    #endif

    return p_output_string;
}
