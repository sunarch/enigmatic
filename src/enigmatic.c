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
#include "view-ascii.h"
#include "view-morse.h"
#include "wheels.h"
#include "wheels-display.h"
#include "wheels-offsets.h"


#ifdef DEBUG
#include "util-debug.h"
#endif


// MACRO VALUES ////////////////////////////////////////////////////////////////

#define  BUFFER_LENGTH_COMMAND     32
#define  BUFFER_LENGTH_MESSAGE   1024

#define  COMMAND_LENGTH_STRING  8

// PRIVATE VARIABLES ///////////////////////////////////////////////////////////

static char command [BUFFER_LENGTH_COMMAND] = "start";
static char message [BUFFER_LENGTH_MESSAGE] = ".";
static char crypto  [BUFFER_LENGTH_MESSAGE] = ".";


// COMMAND NAMES and HANDLERS //////////////////////////////////////////////////

static void command_empty(void)
{
        printf("No command provided.\n");
}


static const char COMMAND_MESSAGE       [COMMAND_LENGTH_STRING] = "message";
static const char COMMAND_MESSAGE_SHORT [COMMAND_LENGTH_STRING] = "msg";
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
                message[strlen(message) - 1] = '\0';
        }

        printf("MSG:  \"%s\"\n", message);

        message_process(message, crypto);

        printf("CMSG: \"%s\"\n", crypto);
}


static const char COMMAND_ASCII [COMMAND_LENGTH_STRING] = "ascii";
static void command_ascii(void)
{
        printf("MSG:  ");
        ascii_print(message, 6);
        printf("CMSG: ");
        ascii_print(crypto, 6);
}


static const char COMMAND_MORSE [COMMAND_LENGTH_STRING] = "morse";
static void command_morse(void)
{
        printf("MSG:  \"%s\"\n", message);
        printf("CMSG: ");
        morse_print(crypto, 6);
}


static const char COMMAND_CONFIG [COMMAND_LENGTH_STRING] = "config";
static void command_config(void)
{
        display_config();
}


static const char COMMAND_APPLY [COMMAND_LENGTH_STRING] = "apply";
static void command_apply(void)
{
        wheels_apply_prompt();
}


static const char COMMAND_RESET [COMMAND_LENGTH_STRING] = "reset";
static void command_reset(void)
{
        offsets_reset();
        printf("Wheel offsets reset.\n");
}


static void command_unknown(void)
{
        printf("Command not recognized.\n");
}


static const char COMMAND_EXIT [COMMAND_LENGTH_STRING] = "exit";


static const char COMMAND_HELP [COMMAND_LENGTH_STRING] = "help";
static void command_help(void)
{
        printf("Commands:");
        printf(" %s", COMMAND_HELP);
        printf(", %s/%s", COMMAND_MESSAGE, COMMAND_MESSAGE_SHORT);
        printf(", %s", COMMAND_ASCII);
        printf(", %s", COMMAND_MORSE);
        printf(", %s", COMMAND_CONFIG);
        printf(", %s", COMMAND_APPLY);
        printf(", %s", COMMAND_RESET);
        printf(", %s", COMMAND_EXIT);
        printf("\n");
}


// INPUT ///////////////////////////////////////////////////////////////////////

void command_prompt(char *command_buffer)
{
        printf("Enigmatic $ ");

        if (fgets(command_buffer, BUFFER_LENGTH_COMMAND, stdin) == NULL) {
                printf("Failed to get command input in buffer with length %i\n", BUFFER_LENGTH_COMMAND);
                printf("Exiting...\n");
                exit(RETURN_CODE_ERROR);
        }

        // remove trailing newline, if there
        if ((strlen(command_buffer) > 0) && (command_buffer[strlen(command_buffer) - 1] == '\n')) {
                command_buffer[strlen(command_buffer) - 1] = '\0';
        }

#ifdef DEBUG
        debug_print_prefix();
        printf("Command: '%s'\n", command_buffer);
#endif
}


// ENTRY POINT /////////////////////////////////////////////////////////////////

int main(void)
{
        printf("Welcome to Enigmatic - an Enigma emulator\n");

        wheels_apply_default();

        while (true) {

                command_prompt(command);

                if (strlen(command) == 0) {
                        command_empty();
                        continue;
                }

                     if (strcmp(command, COMMAND_HELP)          == STRCMP_EQUAL) { command_help();    }
                else if (strcmp(command, COMMAND_MESSAGE)       == STRCMP_EQUAL) { command_message(); }
                else if (strcmp(command, COMMAND_MESSAGE_SHORT) == STRCMP_EQUAL) { command_message(); }
                else if (strcmp(command, COMMAND_ASCII)         == STRCMP_EQUAL) { command_ascii();   }
                else if (strcmp(command, COMMAND_MORSE)         == STRCMP_EQUAL) { command_morse();   }
                else if (strcmp(command, COMMAND_CONFIG)        == STRCMP_EQUAL) { command_config();  }
                else if (strcmp(command, COMMAND_APPLY)         == STRCMP_EQUAL) { command_apply();   }
                else if (strcmp(command, COMMAND_RESET)         == STRCMP_EQUAL) { command_reset();   }
                else if (strcmp(command, COMMAND_EXIT)          == STRCMP_EQUAL) { break;             }
                else                                                             { command_unknown(); }
        }

        printf("Thank you for using Enigmatic!\n");

        return RETURN_CODE_SUCCESS;
}
