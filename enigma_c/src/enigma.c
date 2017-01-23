
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "ascii.h"
#include "wheels.h"

char command [] = "start";
char *pCommand = command;

char argument [] = "";
char *pArgument = argument;

int main (void)
{
    printf("Welcome to Enigma!\n"); // welcome message

    while (true) {

        printf("Engima $ "); // command prompt

        scanf("%s", pCommand);
        printf("COMMAND ENTERED: %s\n", pCommand);

        if (strcmp(command, "msg") == 0 || strcmp(command, "message") == 0) {
            printf("Enter message: "); // argument prompt
            scanf("%s", pArgument);
            printf("MSG: %s\n", pArgument);
            printf("CMSG: ");
            for (int n = 0; n < strlen(argument); ++n) {
                printf("%c", process_char(argument[n]));
            }
            printf("\n");
        }
        else if (strcmp(command, "exit") == 0) {
            break;
        }
        else if (strcmp(command, "quit") == 0) {
            break;
        }
        else {
            printf("Command not recognized.\n");
        }

    }

    return 0;
}
