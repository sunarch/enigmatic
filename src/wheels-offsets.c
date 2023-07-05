/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <stdlib.h>

#include "alphabet-common.h"
#include "common.h"
#include "wheels-common.h"
#include "wheels-offsets.h"
#include "wheels-settings.h"

#ifdef DEBUG
    #include <stdio.h>

    #include "debug.h"
#endif

// PRIVATE VARIABLES ///////////////////////////////////////////////////////////

static unsigned short wheel_offsets[WHEELS_COUNT_MAX_TOTAL] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// GETTERS /////////////////////////////////////////////////////////////////////

unsigned short offsets_get(unsigned short wheel_number)
{
    validate_wheel_number(wheel_number);

    return wheel_offsets[wheel_number];
}

// SETTERS /////////////////////////////////////////////////////////////////////

static void offsets_set(unsigned short wheel_number,
                 unsigned short new_offset)
{
#ifdef DEBUG
    debug_indent_increment();  // to function call level
    debug_indent_print();
    printf("FUNC: void offsets_set(...) // unsigned short wheel_number = %u // unsigned short new_offset = %u\n", wheel_number, new_offset);
#endif

    validate_wheel_number(wheel_number);

    wheel_offsets[wheel_number] = new_offset % ABC_LENGTH;

#ifdef DEBUG
    debug_indent_increment();  // to function result level
    debug_indent_print();
    printf("CHECK: offsets_get(%u) returns %u\n", wheel_number, offsets_get(wheel_number));
    debug_indent_decrement();  // to function call level
    debug_indent_decrement();  // to caller level
#endif
}

void offsets_reset(void)
{
#ifdef DEBUG
    debug_indent_increment();  // to function call level
    debug_indent_print();
    printf("FUNC: void offsets_reset(void)\n");
    unsigned short check_value_wheel_offset;
#endif

#ifdef DEBUG
    debug_indent_increment();  // to function status level
    debug_indent_print();
    printf("Before reset:\n");
    debug_indent_increment();  // to function result level
    check_value_wheel_offset = offsets_get(UKW_INDEX);
    debug_indent_print();
    printf("CHECK: offsets_get(...) // wheel_number = 0 // %u // should always be 0 (UKW)\n", check_value_wheel_offset);
    for (unsigned short n = 1; n <= get_used_wheel_count(); ++n) {
        check_value_wheel_offset =  offsets_get(n);
        debug_indent_print();
        printf("CHECK: offsets_get(...) // wheel_number = %u // %u\n", n, check_value_wheel_offset);
    }
    debug_indent_decrement();  // to function status level
#endif

    for (unsigned short n = 0; n < WHEELS_COUNT_MAX_TOTAL; ++n) {
        wheel_offsets[n] = 0;
    }

#ifdef DEBUG
    debug_indent_print();
    printf("After reset:\n");
    debug_indent_increment();  // to function result level
    check_value_wheel_offset = offsets_get(UKW_INDEX);
    debug_indent_print();
    printf("CHECK: offsets_get(...) // wheel_number = 0 // %u // should always be 0 (UKW)\n", check_value_wheel_offset);
    for (unsigned short n = 1; n <= get_used_wheel_count(); ++n) {
        check_value_wheel_offset =  offsets_get(n);
        debug_indent_print();
        printf("CHECK: offsets_get(...) // wheel_number = %u // %u\n", n, check_value_wheel_offset);
    }
    debug_indent_decrement();  // to function status level
    debug_indent_decrement();  // to function call level
    debug_indent_decrement();  // to caller level
#endif
}

static void offsets_advance_single(unsigned short wheel_number)
{
#ifdef DEBUG
    debug_indent_increment();  // to function call level
        debug_indent_print();
        printf("FUNC: void offsets_advance_single(...) // unsigned short wheel_number = '%u'\n", wheel_number);
#endif

    // validate wheel_number
    validate_wheel_number(wheel_number);

    // move wheel offset by 1
    offsets_set(wheel_number, ((offsets_get(wheel_number) + 1) % ABC_LENGTH));

#ifdef DEBUG
    // CHECK included in setter function
        debug_indent_decrement();  // to caller level
#endif
}


void offsets_advance(void)
{
#ifdef DEBUG
    debug_indent_increment();  // to function call level
        debug_indent_print();
        printf("FUNC: void offsets_advance(void)\n");
#endif

    unsigned short wheel_count = get_used_wheel_count();
    unsigned short current_wheel_offset = 0;

    for (unsigned short n = 1; n <= wheel_count; ++n) {
        current_wheel_offset = offsets_get(n);

        if (current_wheel_offset < ABC_LAST_INDEX) {
            offsets_advance_single(n);
            break;
        }
        else if (current_wheel_offset == ABC_LAST_INDEX) {
            offsets_advance_single(n);
            continue;
        }
        else {
            exit(RETURN_CODE_ERROR);
        }
    }

#ifdef DEBUG
    debug_indent_increment();  // to function result level
        current_wheel_offset = offsets_get(UKW_INDEX); // use var current_wheel_offset from this function
        debug_indent_print();
        printf("CHECK: offsets_get(...) // wheel_number = 0 // '%u' // should always be 0 (UKW)\n", current_wheel_offset);
        for (unsigned short n = 1; n <= wheel_count; ++n) {
            current_wheel_offset =  offsets_get(n); // use var current_wheel_offset from this function
            debug_indent_print();
            printf("CHECK: offsets_get(...) // wheel_number = '%u' // '%u'\n", n, current_wheel_offset);
        }
        debug_indent_decrement();  // to function call level
        debug_indent_decrement();  // to caller level
#endif
}
