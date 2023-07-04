/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "enigmatic.h"
#include "usage.h"
#include "wheels.h"
#include "wheels-display.h"
#include "wheels-offsets.h"

#ifdef DEBUG
    #include "debug.h"
#endif

// PRIVATE VARIABLES ///////////////////////////////////////////////////////////

static char command  [BUFFER_LENGTH_COMMAND]  = "start";
static char message  [BUFFER_LENGTH_MESSAGE]  = ".";
static char crypto   [BUFFER_LENGTH_MESSAGE]  = ".";

// ENTRY POINT /////////////////////////////////////////////////////////////////

int main (void)
{
    #ifdef DEBUG
        debug_indent_print();
        printf("Program starting...\n");
    #endif

    printf("Welcome to Enigmatic - an Enigma emulator\n"); // welcome message

    // apply default settings
    wheels_apply_default();

    while (true) {

        printf("Enigmatic $ "); // command prompt

        // get input
        if (fgets(command, BUFFER_LENGTH_COMMAND, stdin) == NULL) {
            printf("Failed check with (fgets(command, %i, stdin) == NULL)\n", BUFFER_LENGTH_COMMAND);
            printf("Exiting...\n");
            exit(1);
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

        if (strcmp(command, "msg") == STRCMP_EQUAL || strcmp(command, "message") == STRCMP_EQUAL) {
            printf("(max. message size is 1 KiB)\n");
            printf("Enter message: "); // argument prompt

            // get input
            if (fgets(message, BUFFER_LENGTH_MESSAGE, stdin) == NULL) {
                printf("Failed check with (fgets(message, %i, stdin) == NULL)\n", BUFFER_LENGTH_MESSAGE);
                printf("Exiting...\n");
                exit(1);
            };
            /* Remove trailing newline, if there. */
            if ((strlen(message) > 0) && (message[strlen(message) - 1] == '\n')) {
                message[strlen (message) - 1] = '\0';
            }

            printf("MSG:  \"%s\"\n", message);

            #ifdef DEBUG
            debug_print_as_ascii(message);
            #endif

            process_message(message, crypto);

            printf("CMSG: \"%s\"\n", crypto);

            #ifdef DEBUG
            debug_print_as_ascii(crypto);
            #endif
        }
        else if (strcmp(command, "apply") == STRCMP_EQUAL) {
            wheels_apply_prompt();
        }
        else if (strcmp(command, "config") == STRCMP_EQUAL) {
            display_config();
        }
        else if (strcmp(command, "reset") == STRCMP_EQUAL) {
            offsets_reset();
            printf("Wheel offsets reset.\n");
        }
        else if (strcmp(command, "help") == STRCMP_EQUAL) {
            printf("Commands: help, msg/message, reset, config, apply, exit\n");
        }
        else if (strcmp(command, "exit") == STRCMP_EQUAL) {
            break; // exit program loop
        }
        else {
            printf("Command not recognized.\n");
        }
    }

    #ifdef DEBUG
        debug_indent_print();
        printf("Program finished without errors.\n");
        debug_indent_print();
        printf("Shutting down...\n");
    #endif

    printf("Thank you for using Enigmatic!\n");

    return 0;
}
