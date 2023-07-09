/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cli-input.h"
#include "common.h"


#ifdef DEBUG
#include "util-debug.h"
#endif


// PUBLIC //////////////////////////////////////////////////////////////////////

void input_get(char *buffer, unsigned short buffer_length, const char *prompt)
{
        printf("%s ", prompt);

        if (fgets(buffer, buffer_length, stdin) == NULL) {
                printf("Failed to get input in buffer with length %d\n", buffer_length);
                printf("Exiting...\n");
                exit(RETURN_CODE_ERROR);
        }

        // remove trailing newline, if there
        unsigned short buffer_string_length = (unsigned short) strlen(buffer);
        if ((buffer_string_length > 0) && (buffer[buffer_string_length - 1] == '\n')) {
                buffer[buffer_string_length - 1] = '\0';
        }
}
