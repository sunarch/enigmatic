//
// Created by anemeth on 2023.07.04..
//

#include <stdio.h>
#include <stdlib.h>

#include "alphabet.h"

// PROGRAM CONSTANTS ///////////////////////////////////////////////////////////

const char ABC_UPPER [ABC_LENGTH_STRING] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char ABC_LOWER [ABC_LENGTH_STRING] = "abcdefghijklmnopqrstuvwxyz";

// PROGRAM CONSTANT ACCESSORS //////////////////////////////////////////////////

char abc_upper(unsigned int index)
{
    if (index > ABC_LENGTH) {
        printf("Tried to access index outside alphabet: '%d'\n", index);
        printf("Exiting...\n");
        exit(1);
    };
    return ABC_UPPER[index];
}

char abc_lower(unsigned int index)
{
    if (index > ABC_LENGTH) {
        printf("Tried to access index outside alphabet: '%d'\n", index);
        printf("Exiting...\n");
        exit(1);
    };
    return ABC_LOWER[index];
}
