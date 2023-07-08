/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "common.h"
#include "message.h"
#include "util-debug.h"
#include "view-ascii.h"
#include "view-morse.h"
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


// HANDLERS ////////////////////////////////////////////////////////////////////

static void command_empty(void)
{
    printf("No command provided.\n");
}


static void command_help(void)
{
    printf("Commands: help, msg/message, ascii, morse, config, apply, reset, exit\n");
}


static void command_message(void)
{
    printf("(max. message size is 1 KiB)\n");
    printf("Enter message: "); // argument prompt

    // get input
    if (fgets(message, BUFFER_LENGTH_MESSAGE, stdin) == NULL) {
        printf("Failed check with (fgets(message, %i, stdin) == NULL)\n", BUFFER_LENGTH_MESSAGE);
        printf("Exiting...\n");
        exit(RETURN_CODE_ERROR);
    }
    /* Remove trailing newline, if there. */
    if ((strlen(message) > 0) && (message[strlen(message) - 1] == '\n')) {
        message[strlen (message) - 1] = '\0';
    }

    printf("MSG:  \"%s\"\n", message);

    message_process(message, crypto);

    printf("CMSG: \"%s\"\n", crypto);
}


static void command_ascii(void)
{
    printf("MSG:  ");
    ascii_print(message, 6);
    printf("CMSG: ");
    ascii_print(crypto, 6);
}

static void command_morse(void)
{
    printf("MSG:  \"%s\"\n", message);
    printf("CMSG: ");
    morse_print(crypto, 6);
}


static void command_config(void)
{
    display_config();
}


static void command_apply(void)
{
    wheels_apply_prompt();
}


static void command_reset(void)
{
    offsets_reset();
    printf("Wheel offsets reset.\n");
}


static void command_unknown(void)
{
    printf("Command not recognized.\n");
}


// ENTRY POINT /////////////////////////////////////////////////////////////////

int main (void)
{
    printf("Welcome to Enigmatic - an Enigma emulator\n");

    // apply default settings
    wheels_apply_default();

    while (true) {

        printf("Enigmatic $ "); // command prompt

        // get input
        if (fgets(command, BUFFER_LENGTH_COMMAND, stdin) == NULL) {
            printf("Failed check with (fgets(command, %i, stdin) == NULL)\n", BUFFER_LENGTH_COMMAND);
            printf("Exiting...\n");
            exit(RETURN_CODE_ERROR);
        }

        /* Remove trailing newline, if there. */
        if ((strlen(command) > 0) && (command[strlen(command) - 1] == '\n')) {
            command[strlen(command) - 1] = '\0';
        }

        if (strlen(command) == 0) {
            command_empty();
            continue;
        }

        #ifdef DEBUG
            debug_prefix();
            printf("Command: '%s'\n", command);
        #endif

             if (strcmp(command, "help")    == STRCMP_EQUAL) { command_help();    }
        else if (strcmp(command, "message") == STRCMP_EQUAL) { command_message(); }
        else if (strcmp(command, "msg")     == STRCMP_EQUAL) { command_message(); }
        else if (strcmp(command, "ascii")   == STRCMP_EQUAL) { command_ascii();   }
        else if (strcmp(command, "morse")   == STRCMP_EQUAL) { command_morse();   }
        else if (strcmp(command, "config")  == STRCMP_EQUAL) { command_config();  }
        else if (strcmp(command, "apply")   == STRCMP_EQUAL) { command_apply();   }
        else if (strcmp(command, "reset")   == STRCMP_EQUAL) { command_reset();   }
        else if (strcmp(command, "exit")    == STRCMP_EQUAL) { break;             }
        else                                                 { command_unknown(); }
    }

    printf("Thank you for using Enigmatic!\n");

    return RETURN_CODE_SUCCESS;
}
