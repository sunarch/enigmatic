/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <stdio.h>

#include "disp-config.h"
#include "wheels.h"
#include "usage.h"
#include "util-debug.h"

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
    printf("  (%c) |", ABC_LOW[calculate_index_after_wiring_rule(pos, rule)]);
}

static void print_config_section(unsigned short direction, unsigned short wheel_count)
{
    if (direction != WHEEL_MODE_FRONT && direction != WHEEL_MODE_REVERSE) {
        printf("Config section type error.");
        return;
    }

    signed short rules[11];
    unsigned short i_pos, i_col, i_wheel;

    // header row

    printf("|");

    printf(" position |");

    if (direction == WHEEL_MODE_REVERSE) {
        printf("    UKW   |");
    }

    for (i_wheel = 1; i_wheel <= wheel_count; ++i_wheel) {
        printf(" wheel ");
        if (i_wheel < 10) {
            printf(" ");
        }
        printf("%u |", i_wheel);
    }

    if (direction == WHEEL_MODE_FRONT) {
        printf("    UKW   |");
    }

    printf("\n");

    // separator

    printf("|");

    for (i_col = 0; i_col <= wheel_count + 1; ++i_col) {
        printf(" -------- |");
    }

    printf("\n");

    // lines

    for (i_pos = 0; i_pos < 26; ++i_pos) {

        if (direction == WHEEL_MODE_REVERSE) {
            collect_wheel_wiring_rules_reverse_for_position(i_pos, rules);
        }
        else if (direction == WHEEL_MODE_FRONT) {
            collect_wheel_wiring_rules_front_for_position(i_pos, rules);
        }

        printf("|");

        print_aligned_rule(i_pos);
        printf("  (%c) |", ABC_LOW[i_pos]);  // position

        // UKW
        if (direction == WHEEL_MODE_REVERSE) {
            print_aligned_rule(rules[0]);
            print_aligned_index_letter(i_pos, rules[0]);
        }

        for (i_wheel = 1; i_wheel <= wheel_count; ++i_wheel) {
            print_aligned_rule(rules[i_wheel]);
            print_aligned_index_letter(i_pos, rules[i_wheel]);
        }

        // UKW
        if (direction == WHEEL_MODE_FRONT) {
            print_aligned_rule(rules[0]);
            print_aligned_index_letter(i_pos, rules[0]);
        }

        printf("\n");
    }
}

void print_config(void)
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

    print_config_section(WHEEL_MODE_FRONT, wheel_count);
    printf("\n");

    // reverse -----------------------------------------------------------------

    printf("wiring rules reverse:\n");
    printf("\n");

    print_config_section(WHEEL_MODE_REVERSE, wheel_count);
    printf("\n");

    #ifdef DEBUG
        debug_indent_decrement(); // to function outer level
        debug_indent_print();
        printf("END of configuration\n");
        debug_indent_decrement(); // to caller level
    #endif
}
