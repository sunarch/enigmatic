/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <stdio.h>

#include "alphabet.h"
#include "wheels.h"
#include "wheels-display.h"
#include "wheels-settings.h"
#include "usage.h"

#ifdef DEBUG
    #include "debug.h"
#endif

// cells ///////////////////////////////////////////////////////////////////////

static void print_aligned_wheel_header(unsigned short wheel_number)
{
    if (wheel_number == UKW_INDEX) {
        printf("    UKW   |");
    }
    else {
        printf(" wheel ");
        if (wheel_number < 10) {
            printf(" ");
        }
        printf("%u |", wheel_number);
    }
}

static void display_cell_offset(unsigned short wheel_number, unsigned short offset)
{
    if (wheel_number == UKW_INDEX) {
        printf("          |");
    }
    else {
        printf(" +     ");
        if (offset < 10) {
            printf(" ");
        }
        printf("%u |", offset);
    }
}

static void print_aligned_rule(signed short rule)
{
    if (rule < -9) {
        printf(" ");
    }
    else if (rule < 0 || rule > 9) {
        printf("  ");
    }
    else {
        printf("   ");
    }

    printf("%d", rule);
}

static void print_aligned_index_letter(unsigned short pos, signed short rule)
{
    printf("  (%c) |", abc_lower(calculate_index_after_wiring_rule(pos, rule)));
}

// rows ////////////////////////////////////////////////////////////////////////

static void display_row_header(unsigned short direction, unsigned short wheel_count)
{
    unsigned short wheel_index;

    printf("|");
    printf(" position |");

    if (direction == WHEEL_MODE_FRONT) {
        for (wheel_index = 1; wheel_index <= wheel_count; ++wheel_index) {
            print_aligned_wheel_header(wheel_index);
        }
        print_aligned_wheel_header(UKW_INDEX);
    }
    else if (direction == WHEEL_MODE_REVERSE) {
        print_aligned_wheel_header(UKW_INDEX);
        for (wheel_index = wheel_count; wheel_index >= 1; --wheel_index) {
            print_aligned_wheel_header(wheel_index);
        }
    }

    printf("\n");
}

static void display_row_offsets(unsigned short direction, unsigned short wheel_count)
{
    unsigned short wheel_index;

    printf("|");
    printf(" offsets: |");

    if (direction == WHEEL_MODE_FRONT) {
        for (wheel_index = 1; wheel_index <= wheel_count; ++wheel_index) {
            display_cell_offset(wheel_index, get_wheel_offset(wheel_index));
        }
        display_cell_offset(UKW_INDEX, get_wheel_offset(UKW_INDEX));
    }
    else if (direction == WHEEL_MODE_REVERSE) {
        display_cell_offset(UKW_INDEX, get_wheel_offset(UKW_INDEX));
        for (wheel_index = wheel_count; wheel_index >= 1; --wheel_index) {
            display_cell_offset(wheel_index, get_wheel_offset(wheel_index));
        }
    }

    printf("\n");
}

static void display_row_separator(unsigned short wheel_count)
{
    unsigned short wheel_index;

    printf("|");

    for (wheel_index = 0; wheel_index <= wheel_count + 1; ++wheel_index) {
        printf(" -------- |");
    }

    printf("\n");
}

// section /////////////////////////////////////////////////////////////////////

static void display_section(unsigned short direction, unsigned short wheel_count)
{
    if (direction != WHEEL_MODE_FRONT && direction != WHEEL_MODE_REVERSE) {
        printf("Config section type error.");
        return;
    }

    signed short rules[11];
    unsigned short position, wheel_index;

    // header row
    display_row_header(direction, wheel_count);

    // separator
    display_row_separator(wheel_count);

    // offsets
    display_row_offsets(direction, wheel_count);

    // separator
    display_row_separator(wheel_count);

    // lines

    for (position = 0; position < 26; ++position) {

        if (direction == WHEEL_MODE_FRONT) {
            collect_wheel_wiring_rules_front_for_position(position, rules);
        }
        else if (direction == WHEEL_MODE_REVERSE) {
            collect_wheel_wiring_rules_reverse_for_position(position, rules);
        }

        printf("|");

        print_aligned_rule(position);
        printf("  (%c) |", abc_lower(position));  // position

        if (direction == WHEEL_MODE_FRONT) {
            // regular wheels
            for (wheel_index = 1; wheel_index <= wheel_count; ++wheel_index) {
                print_aligned_rule(rules[wheel_index]);
                print_aligned_index_letter(position, rules[wheel_index]);
            }
            // UKW
            print_aligned_rule(rules[UKW_INDEX]);
            print_aligned_index_letter(position, rules[UKW_INDEX]);
        }
        else if (direction == WHEEL_MODE_REVERSE) {
            // UKW
            print_aligned_rule(rules[UKW_INDEX]);
            print_aligned_index_letter(position, rules[UKW_INDEX]);
            // regular wheels
            for (wheel_index = wheel_count; wheel_index >= 1; --wheel_index) {
                print_aligned_rule(rules[wheel_index]);
                print_aligned_index_letter(position, rules[wheel_index]);
            }
        }

        printf("\n");
    }
}

// main ////////////////////////////////////////////////////////////////////////

void display_config(void)
{
    #ifdef DEBUG
        debug_indent_increment(); // to function outer level
        debug_indent_print();
        printf("START of configuration\n");
        debug_indent_increment(); // to function inner level
    #endif

    unsigned short wheel_count = get_used_wheel_count();

    printf("\n");

    printf("used wheel count: %u\n", wheel_count);
    printf("\n");

    // front -------------------------------------------------------------------

    printf("wiring rules front:\n");
    printf("\n");

    display_section(WHEEL_MODE_FRONT, wheel_count);
    printf("\n");

    // reverse -----------------------------------------------------------------

    printf("wiring rules reverse:\n");
    printf("\n");

    display_section(WHEEL_MODE_REVERSE, wheel_count);
    printf("\n");

    #ifdef DEBUG
        debug_indent_decrement(); // to function outer level
        debug_indent_print();
        printf("END of configuration\n");
        debug_indent_decrement(); // to caller level
    #endif
}
