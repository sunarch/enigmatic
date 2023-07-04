/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "wheels-offsets.h"
#include "wheels-settings.h"

#ifdef DEBUG
    #include <stdio.h>

    #include "debug.h"
#endif


static unsigned short wheel_offsets[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };


unsigned short offsets_get(unsigned short wheel_number)
{
    validate_wheel_number(wheel_number);

    return wheel_offsets[wheel_number];
}

void offsets_set(unsigned short wheel_number,
                 unsigned short new_offset)
{
#ifdef DEBUG
    debug_indent_increment();  // to function call level
    debug_indent_print();
    printf("FUNC: void offsets_set(...) // unsigned short wheel_number = %u // unsigned short new_offset = %u\n", wheel_number, new_offset);
#endif

    validate_wheel_number(wheel_number);

    wheel_offsets[wheel_number] = new_offset % 26;

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
    check_value_wheel_offset = offsets_get(0);
    debug_indent_print();
    printf("CHECK: offsets_get(...) // wheel_number = 0 // %u // should always be 0 (UKW)\n", check_value_wheel_offset);
    for (unsigned short n = 1; n <= get_used_wheel_count(); ++n) {
        check_value_wheel_offset =  offsets_get(n);
        debug_indent_print();
        printf("CHECK: offsets_get(...) // wheel_number = %u // %u\n", n, check_value_wheel_offset);
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
    check_value_wheel_offset = offsets_get(0);
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
