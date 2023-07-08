/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdlib.h>

#include "common.h"
#include "util-abc-common.h"
#include "wheels-common.h"
#include "wheels-offsets.h"
#include "wheels-settings.h"

#ifdef DEBUG
    #include <stdio.h>

    #include "util-debug.h"
#endif


// PRIVATE VARIABLES ///////////////////////////////////////////////////////////

static unsigned short wheel_offsets[WHEELS_COUNT_MAX_TOTAL] = { 0 }; // all zeroes


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
    debug_print_prefix();
    printf("offsets_set (wheel '%u') '%u' -> '%u'", wheel_number, offsets_get(wheel_number), new_offset);
#endif

    validate_wheel_number(wheel_number);

    wheel_offsets[wheel_number] = new_offset % ABC_LENGTH;

#ifdef DEBUG
    printf(" | check: '%u'\n", offsets_get(wheel_number));
#endif
}


#ifdef DEBUG
static void offsets_display(void)
{
    printf("offsets: | UKW: '%u'", offsets_get(UKW_INDEX));
    for (unsigned short i = 1; i <= get_used_wheel_count(); ++i) {
        printf(" | '%u': '%u'", i, offsets_get(i));
    }
    printf("\n");
}
#endif


void offsets_reset(void)
{
#ifdef DEBUG
    debug_print_prefix();
    printf("offsets_reset\n");

    debug_print_prefix();
    printf("BEFORE: ");
    offsets_display();
#endif

    for (unsigned short n = 0; n < WHEELS_COUNT_MAX_TOTAL; ++n) {
        wheel_offsets[n] = 0;
    }

#ifdef DEBUG
    debug_print_prefix();
    printf("AFTER:  ");
    offsets_display();
#endif
}


static void offsets_advance_single(unsigned short wheel_number)
{
#ifdef DEBUG
    debug_print_prefix();
    printf("offsets_advance_single (wheel '%u')\n", wheel_number);
#endif

    // validate wheel_number
    validate_wheel_number(wheel_number);

    // move wheel offset by 1
    unsigned short new_offset = (unsigned short) ((offsets_get(wheel_number) + 1) % ABC_LENGTH);
    offsets_set(wheel_number, new_offset);
}


void offsets_advance(void)
{
#ifdef DEBUG
    debug_print_prefix();
    printf("offsets_advance()\n");
#endif

    unsigned short wheel_count = get_used_wheel_count();
    unsigned short current_wheel_offset;

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
}
