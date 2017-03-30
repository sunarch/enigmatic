
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "enigma.h"
#include "util_debug.h"

char command [] = "start";
char *pCommand = command;

char argument [] = "none";
char *pArgument = argument;

int main (void) {
    #ifdef DEBUG
        print_debug_indent();
        printf("Program starting...\n");
    #endif

    printf("Welcome to Enigma!\n"); // welcome message

    // apply default settings
    apply_settings_default();

    while (true) {

        printf("Engima $ "); // command prompt

        //scanf("%[^\n]%*c", pCommand);
        if (fgets(pCommand, 100, stdin) == NULL) {
            printf("Failed check with (fgets(pCommand, 100, stdin) == NULL)\n");
            printf("Exiting...\n");
            exit(1);
        };
        /* Remove trailing newline, if there. */
        if ((strlen(pCommand) > 0) && (pCommand[strlen(pCommand) - 1] == '\n')) {
            pCommand[strlen(pCommand) - 1] = '\0';
        }

        printf("COMMAND ENTERED: %s\n", pCommand);

        if (strcmp(command, "msg") == 0 || strcmp(command, "message") == 0) {
            printf("Enter message: "); // argument prompt

            //scanf("%[^\n]%*c", pArgument);
            if (fgets(pArgument, 100, stdin) == NULL) {
                printf("Failed check with (fgets(pArgument, 100, stdin) == NULL)\n");
                printf("Exiting...\n");
                exit(1);
            };

            /* Remove trailing newline, if there. */
            if ((strlen(pArgument) > 0) && (pArgument[strlen(pArgument) - 1] == '\n')) {
                pArgument[strlen (pArgument) - 1] = '\0';
            }

            printf("MSG: %s\n", pArgument);
            printf("CMSG: %s\n", process_message(pArgument));
        }
        else if (strcmp(command, "config") == 0) {
            printf("View config? (y/n): "); // argument prompt

            //scanf("%[^\n]%*c", pArgument);
            if (fgets(pArgument, 100, stdin) == NULL) {
                printf("Failed check with (fgets(pArgument, 100, stdin) == NULL)\n");
                printf("Exiting...\n");
                exit(1);
            };
            /* Remove trailing newline, if there. */
            if ((strlen(pArgument) > 0) && (pArgument[strlen(pArgument) - 1] == '\n')) {
                pArgument[strlen(pArgument) - 1] = '\0';
            }

            if (strcmp(pArgument, "y") == 0 || strcmp(pArgument, "Y") == 0) {
                print_config();
            }
        }
        else if (strcmp(command, "help") == 0) {
            printf("Commands: help, msg/message, exit/quit\n");
        }
        else if (strcmp(command, "exit") == 0) {
            break; // exit program loop
        }
        else if (strcmp(command, "quit") == 0) {
            break; // exit program loop
        }
        else {
            printf("Command not recognized.\n");
        }
    }

    #ifdef DEBUG
        print_debug_indent();
        printf("Program finished without errors.\n");
        print_debug_indent();
        printf("Shutting down...\n");
    #endif

    return 0;
}
