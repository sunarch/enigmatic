/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cli-prompt.h"
#include "common.h"


#ifdef DEBUG
#include "util-debug.h"
#endif


// PRIVATE /////////////////////////////////////////////////////////////////////

static void prompt_input(char *buffer, unsigned short buffer_length)
{
        if (fgets(buffer, buffer_length, stdin) == NULL) {
                printf("Failed to get input in buffer with length %d\n", buffer_length);
                printf("Exiting...\n");
                exit(RETURN_CODE_ERROR);
        }

        // remove trailing newline, if there
        if ((strlen(buffer) > 0) && (buffer[strlen(buffer) - 1] == '\n')) {
                buffer[strlen(buffer) - 1] = '\0';
        }
}


// PUBLIC //////////////////////////////////////////////////////////////////////

void prompt_command(char *buffer, unsigned short buffer_length)
{
        printf("Enigmatic $ ");

        prompt_input(buffer, buffer_length);

#ifdef DEBUG
        debug_print_prefix();
        printf("Command: '%s'\n", buffer);
#endif
}


void prompt_message(char *buffer, unsigned short buffer_length)
{
        printf("(max. message size is %d)\n", buffer_length);
        printf("Enter message: ");

        prompt_input(buffer, buffer_length);

        printf("Message: \"%s\"\n", buffer);
}
