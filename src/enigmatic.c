/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "common.h"
#include "debug.h"
#include "usage.h"
#include "wheels.h"
#include "wheels-display.h"
#include "wheels-offsets.h"

// MACRO VALUES ////////////////////////////////////////////////////////////////

# define  BUFFER_LENGTH_COMMAND     32
# define  BUFFER_LENGTH_MESSAGE   1024

// PRIVATE VARIABLES ///////////////////////////////////////////////////////////

static char command  [BUFFER_LENGTH_COMMAND]  = "start";
static char message  [BUFFER_LENGTH_MESSAGE]  = ".";
static char crypto   [BUFFER_LENGTH_MESSAGE]  = ".";

// ENTRY POINT /////////////////////////////////////////////////////////////////

int main (void)
{
    printf("Welcome to Enigmatic - an Enigma emulator\n"); // welcome message

    // apply default settings
    wheels_apply_default();

    while (true) {

        printf("Enigmatic $ "); // command prompt

        // get input
        if (fgets(command, BUFFER_LENGTH_COMMAND, stdin) == NULL) {
            printf("Failed check with (fgets(command, %i, stdin) == NULL)\n", BUFFER_LENGTH_COMMAND);
            printf("Exiting...\n");
            exit(RETURN_CODE_ERROR);
        };

        /* Remove trailing newline, if there. */
        if ((strlen(command) > 0) && (command[strlen(command) - 1] == '\n')) {
            command[strlen(command) - 1] = '\0';
        }

        if (strlen(command) == 0) {
            continue;
        }

        #ifdef DEBUG
            debug_indent_print();
            printf("COMMAND ENTERED: \"%s\"\n", command);
        #endif

        if (strcmp(command, "help") == STRCMP_EQUAL) {
            printf("Commands: help, msg/message, ascii, config, apply, reset, exit\n");
        }
        else if (strcmp(command, "msg") == STRCMP_EQUAL || strcmp(command, "message") == STRCMP_EQUAL) {
            printf("(max. message size is 1 KiB)\n");
            printf("Enter message: "); // argument prompt

            // get input
            if (fgets(message, BUFFER_LENGTH_MESSAGE, stdin) == NULL) {
                printf("Failed check with (fgets(message, %i, stdin) == NULL)\n", BUFFER_LENGTH_MESSAGE);
                printf("Exiting...\n");
                exit(RETURN_CODE_ERROR);
            };
            /* Remove trailing newline, if there. */
            if ((strlen(message) > 0) && (message[strlen(message) - 1] == '\n')) {
                message[strlen (message) - 1] = '\0';
            }

            printf("MSG:  \"%s\"\n", message);

            process_message(message, crypto);

            printf("CMSG: \"%s\"\n", crypto);
        }
        else if (strcmp(command, "ascii") == STRCMP_EQUAL) {
            printf("MSG:  ");
            debug_print_as_ascii(message);
            printf("CMSG: ");
            debug_print_as_ascii(crypto);
        }
        else if (strcmp(command, "config") == STRCMP_EQUAL) {
            display_config();
        }
        else if (strcmp(command, "apply") == STRCMP_EQUAL) {
            wheels_apply_prompt();
        }
        else if (strcmp(command, "reset") == STRCMP_EQUAL) {
            offsets_reset();
            printf("Wheel offsets reset.\n");
        }
        else if (strcmp(command, "exit") == STRCMP_EQUAL) {
            break; // exit program loop
        }
        else {
            printf("Command not recognized.\n");
        }
    }

    printf("Thank you for using Enigmatic!\n");

    return RETURN_CODE_SUCCESS;
}
