/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <stdio.h>

#include "alphabet.h"
#include "alphabet-common.h"
#include "wheels.h"
#include "wheels-common.h"
#include "wheels-display.h"
#include "wheels-offsets.h"
#include "wheels-settings.h"

#ifdef DEBUG
    #include "debug.h"
#endif


// cells ///////////////////////////////////////////////////////////////////////

static void display_cell_wheel_name(unsigned short wheel_number)
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


static void display_cell_rule(unsigned short position, signed short rule)
{
    char representation = abc_lower(calculate_index_after_wiring_rule(position, rule));

    if (rule < -9) {
        printf(" ");
    }
    else if (rule < 0 || rule > 9) {
        printf("  ");
    }
    else {
        printf("   ");
    }

    printf("%d  (%c) |", rule, representation);
}


// rows ////////////////////////////////////////////////////////////////////////

static void display_row_header(unsigned short direction, unsigned short wheel_count)
{
    unsigned short wheel_index;

    printf("| position |");

    if (direction == WHEEL_MODE_FRONT) {
        for (wheel_index = 1; wheel_index <= wheel_count; ++wheel_index) {
            display_cell_wheel_name(wheel_index);
        }
        display_cell_wheel_name(UKW_INDEX);
    }
    else if (direction == WHEEL_MODE_REVERSE) {
        display_cell_wheel_name(UKW_INDEX);
        for (wheel_index = wheel_count; wheel_index >= 1; --wheel_index) {
            display_cell_wheel_name(wheel_index);
        }
    }

    printf("\n");
}


static void display_row_offsets(unsigned short direction, unsigned short wheel_count)
{
    unsigned short wheel_index;

    printf("| offsets: |");

    if (direction == WHEEL_MODE_FRONT) {
        for (wheel_index = 1; wheel_index <= wheel_count; ++wheel_index) {
            display_cell_offset(wheel_index, offsets_get(wheel_index));
        }
        display_cell_offset(UKW_INDEX, offsets_get(UKW_INDEX));
    }
    else if (direction == WHEEL_MODE_REVERSE) {
        display_cell_offset(UKW_INDEX, offsets_get(UKW_INDEX));
        for (wheel_index = wheel_count; wheel_index >= 1; --wheel_index) {
            display_cell_offset(wheel_index, offsets_get(wheel_index));
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


static void display_row_rules(unsigned short direction,
                              unsigned short wheel_count,
                              unsigned short position)
{
    unsigned short wheel_index;
    signed short rule;

    printf("|");

    display_cell_rule(0, (signed short) position);

    if (direction == WHEEL_MODE_FRONT) {
        for (wheel_index = 1; wheel_index <= wheel_count; ++wheel_index) {
            rule = get_wheel_wiring_rule(WHEEL_MODE_FRONT, wheel_index, position);
            display_cell_rule(position, rule);
        }
        rule = get_wheel_wiring_rule(WHEEL_MODE_UKW, UKW_INDEX, position);
        display_cell_rule(position, rule);
    }
    else if (direction == WHEEL_MODE_REVERSE) {
        rule = get_wheel_wiring_rule(WHEEL_MODE_UKW, UKW_INDEX, position);
        display_cell_rule(position, rule);
        for (wheel_index = wheel_count; wheel_index >= 1; --wheel_index) {
            rule = get_wheel_wiring_rule(WHEEL_MODE_REVERSE, wheel_index, position);
            display_cell_rule(position, rule);
        }
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

    unsigned short position;

    // header row
    display_row_header(direction, wheel_count);

    // separator
    display_row_separator(wheel_count);

    // offsets
    display_row_offsets(direction, wheel_count);

    // separator
    display_row_separator(wheel_count);

    // lines
    for (position = 0; position < ABC_LENGTH; ++position) {
        display_row_rules(direction, wheel_count, position);
    }
}


// main ////////////////////////////////////////////////////////////////////////

void display_config(void)
{
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
}
