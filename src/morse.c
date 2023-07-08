/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdio.h>

#include "morse.h"


static void morse_print_char(char character)
{
    switch (character) {
        case 'a':
            printf(".-    ");
            break;
        case 'b':
            printf("-...  ");
            break;
        case 'c':
            printf("-.-.  ");
            break;
        case 'd':
            printf("-..   ");
            break;
        case 'e':
            printf(".     ");
            break;
        case 'f':
            printf("..-.  ");
            break;
        case 'g':
            printf("--.   ");
            break;
        case 'h':
            printf("....  ");
            break;
        case 'i':
            printf("..    ");
            break;
        case 'j':
            printf(".---  ");
            break;
        case 'k':
            printf("-.-   ");
            break;
        case 'l':
            printf(".-..  ");
            break;
        case 'm':
            printf("--    ");
            break;
        case 'n':
            printf("-.    ");
            break;
        case 'o':
            printf("---   ");
            break;
        case 'p':
            printf(".--.  ");
            break;
        case 'q':
            printf("--.-  ");
            break;
        case 'r':
            printf(".-.   ");
            break;
        case 's':
            printf("...   ");
            break;
        case 't':
            printf("-     ");
            break;
        case 'u':
            printf("..-   ");
            break;
        case 'v':
            printf("...-  ");
            break;
        case 'w':
            printf(".--   ");
            break;
        case 'x':
            printf("-..-  ");
            break;
        case 'y':
            printf("-.--  ");
            break;
        case 'z':
            printf("--..  ");
            break;
        case '.':
            printf(".-.-.-");
            break;
        default:
            printf("      ");
            break;
    }
}


void morse_print(char *p_text, unsigned short indent_length)
{
    int index = 0;
    printf("       ");
    while(p_text[index] != '\0') {
        printf(" '%c'   ", p_text[index]);
        index++;
    }
    printf("\n");

    for (index = 0; index < indent_length; index++) {
        printf(" ");
    }

    index = 0;
    printf("MORSE: ");
    while(p_text[index] != '\0') {
        printf(" ");
        morse_print_char(p_text[index]);
        index++;
    }
    printf("\n");
}
