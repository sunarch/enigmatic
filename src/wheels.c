/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wheels.h"
#include "wheels-settings.h"

#ifdef DEBUG
    #include "debug.h"
#endif

// INTERNAL CONSTANTS //////////////////////////////////////////////////////////

#define  BUFFER_LENGTH_APPLY_OPTION  16

// INTERNAL VARIABLES //////////////////////////////////////////////////////////

static unsigned short wheel_offsets[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// settings ////////////////////////////////////////////////////////////////////

void wheels_apply_default(void)
{
    apply_settings_default();
}

void wheels_apply_prompt(void)
{
    reset_wheel_offsets();

    printf("Select option to apply\n:");
    printf("|-> 'argentina'  - G-260 (Abwehr in Argentina)\n");
    printf("|-> 'army'       - M3 (Army, Navy)\n");
    printf("|-> 'bletchley'  - G-312 (Abwehr / Bletchley Park)\n");
    printf("|-> 'commercial' - D (commercial)\n");
    printf("|-> 'hungary'    - G-111 (Hungary / Munich)\n");
    printf("|-> 'navy'       - M3 (Army, Navy)\n");
    printf("|-> 'norway'     - N \"Norenigma\" (Norway)\n");
    printf("|-> 'railway'    - R \"Rocket\" (Railway)\n");
    printf("|-> 'services'   - I \"Services\" (Army, GAF)\n");
    printf("|-> 'swiss'      - K \"Swiss K\" (Swiss)\n");
    printf("|-> 'tirpitz'    - T \"Tirpitz\" (Japan)\n");
    printf("|-> 'zaehlwerk'  - A-865 \"Zählwerk\" (1928)\n");
    printf("Apply option: ");

    static char apply_option[BUFFER_LENGTH_APPLY_OPTION]  = "-";

    // get input
    if (fgets(apply_option, BUFFER_LENGTH_APPLY_OPTION, stdin) == NULL) {
        printf("Failed to get apply option\n");
        printf("Exiting...\n");
        exit(1);
    };

    /* Remove trailing newline, if there. */
    unsigned short apply_option_length = strlen(apply_option);
    if ((apply_option_length > 0) && (apply_option[apply_option_length - 1] == '\n')) {
        apply_option[apply_option_length - 1] = '\0';
    }

    if (strcmp(apply_option, "argentina") == STRCMP_EQUAL) {
        apply_settings_argentina();
    }
    else if (strcmp(apply_option, "army") == STRCMP_EQUAL) {
        apply_settings_army();
    }
    else if (strcmp(apply_option, "bletchley") == STRCMP_EQUAL) {
        apply_settings_bletchley();
    }
    else if (strcmp(apply_option, "commercial") == STRCMP_EQUAL) {
        apply_settings_commercial();
    }
    else if (strcmp(apply_option, "hungary") == STRCMP_EQUAL) {
        apply_settings_hungary();
    }
    else if (strcmp(apply_option, "navy") == STRCMP_EQUAL) {
        apply_settings_navy();
    }
    else if (strcmp(apply_option, "norway") == STRCMP_EQUAL) {
        apply_settings_norway();
    }
    else if (strcmp(apply_option, "railway") == STRCMP_EQUAL) {
        apply_settings_railway();
    }
    else if (strcmp(apply_option, "services") == STRCMP_EQUAL) {
        apply_settings_services();
    }
    else if (strcmp(apply_option, "swiss") == STRCMP_EQUAL) {
        apply_settings_swiss();
    }
    else if (strcmp(apply_option, "tirpitz") == STRCMP_EQUAL) {
        apply_settings_tirpitz();
    }
    else if (strcmp(apply_option, "zaehlwerk") == STRCMP_EQUAL) {
        apply_settings_zaehlwerk();
    }
    else {
        printf("Setting option not recognized: '%s'\n", apply_option);
        apply_settings_default();
    }
}

// OTHER FUNCTIONS /////////////////////////////////////////////////////////////

void validate_wheel_number(unsigned short wheel_number)
{
    unsigned short wheel_count = get_used_wheel_count();

    if (wheel_number > wheel_count) {
        printf("Failed check with (wheel_number > wheel_count): (%u > %u)\n", wheel_number, wheel_count);
        printf("Exiting...\n");
        exit(1);
    }
}

unsigned short get_wheel_offset(unsigned short wheel_number)
{
    // no debug messages in getter functions, include them as checks in calls

    // validate wheel_number
    validate_wheel_number(wheel_number);

    return wheel_offsets[wheel_number];
}

void set_wheel_offset(unsigned short wheel_number,
                      unsigned short new_offset)
{
    #ifdef DEBUG
        debug_indent_increment();  // to function call level
        debug_indent_print();
        printf("FUNC: void set_wheel_offset(...) // unsigned short wheel_number = %u // unsigned short new_offset = %u\n", wheel_number, new_offset);
    #endif

    // validate wheel_number
    validate_wheel_number(wheel_number);

    // change wheel offset
    wheel_offsets[wheel_number] = new_offset % 26;

    #ifdef DEBUG
        debug_indent_increment();  // to function result level
        debug_indent_print();
        printf("CHECK: get_wheel_offset(%u) returns %u\n", wheel_number, get_wheel_offset(wheel_number));
        debug_indent_decrement();  // to function call level
        debug_indent_decrement();  // to caller level
    #endif
}

void reset_wheel_offsets(void)
{
    #ifdef DEBUG
        debug_indent_increment();  // to function call level
        debug_indent_print();
        printf("FUNC: void reset_wheel_offsets(void)\n");
        unsigned short check_value_wheel_offset;
    #endif

    #ifdef DEBUG
        debug_indent_increment();  // to function status level
        debug_indent_print();
        printf("Before reset:\n");
        debug_indent_increment();  // to function result level
        check_value_wheel_offset = get_wheel_offset(0);
        debug_indent_print();
        printf("CHECK: get_wheel_offset(...) // wheel_number = 0 // %u // should always be 0 (UKW)\n", check_value_wheel_offset);
        for (unsigned short n = 1; n <= get_used_wheel_count(); ++n) {
            check_value_wheel_offset =  get_wheel_offset(n);
            debug_indent_print();
            printf("CHECK: get_wheel_offset(...) // wheel_number = %u // %u\n", n, check_value_wheel_offset);
        }
        debug_indent_decrement();  // to function status level
    #endif

    for (unsigned short n = 0; n < 11; ++n) {
        wheel_offsets[n] = 0;
    }

    #ifdef DEBUG
        debug_indent_print();
        printf("After reset:\n");
        debug_indent_increment();  // to function result level
        check_value_wheel_offset = get_wheel_offset(0);
        debug_indent_print();
        printf("CHECK: get_wheel_offset(...) // wheel_number = 0 // %u // should always be 0 (UKW)\n", check_value_wheel_offset);
        for (unsigned short n = 1; n <= get_used_wheel_count(); ++n) {
            check_value_wheel_offset =  get_wheel_offset(n);
            debug_indent_print();
            printf("CHECK: get_wheel_offset(...) // wheel_number = %u // %u\n", n, check_value_wheel_offset);
        }
        debug_indent_decrement();  // to function status level
        debug_indent_decrement();  // to function call level
        debug_indent_decrement();  // to caller level
    #endif
}

signed short *get_wheel_wiring_rules_front(unsigned short wheel_number)
{
    // no debug messages in getter functions, include them as checks in calls

    // validate wheel number
    validate_wheel_number(wheel_number);

    return wheel_wiring_rules_front[wheel_number];
}

signed short *get_wheel_wiring_rules_reverse(unsigned short wheel_number)
{
    // no debug messages in getter functions, include them as checks in calls

    // validate wheel number
    validate_wheel_number(wheel_number);

    return wheel_wiring_rules_reverse[wheel_number];
}

unsigned short wheels_get_count(void)
{
    return get_used_wheel_count();
}

void collect_wheel_wiring_rules_front_for_position(unsigned short position, signed short *rules)
{
    if (position > 25) { return; }

    for (unsigned short i = 0; i < 11; ++i) {
        rules[i] = wheel_wiring_rules_front[i][position];
    }

}

void collect_wheel_wiring_rules_reverse_for_position(unsigned short position, signed short *rules)
{
    if (position > 25) { return; }

    for (unsigned short i = 0; i < 11; ++i) {
        rules[i] = wheel_wiring_rules_reverse[i][position];
    }
}
