/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdio.h>
#include <string.h>

#include "util-text.h"


void text_print_padding(const char *text, unsigned short max_length)
{
        unsigned short text_length = (unsigned short) strlen(text);
        signed short padding_length = (signed short) (max_length - text_length);

        printf("%*s", padding_length, "");
}
