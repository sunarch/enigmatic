//
// Created by anemeth on 2023.07.04..
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

short abc_index_upper(char character)
{
    char *p_occurrence = strchr(ABC_UPPER, character);
    if(p_occurrence == NULL) {
        return -1;
    }
    return (short) (p_occurrence - ABC_UPPER);
}

short abc_index_lower(char character)
{
    char *p_occurrence = strchr(ABC_LOWER, character);
    if(p_occurrence == NULL) {
        return -1;
    }
    return (short) (p_occurrence - ABC_LOWER);
}

bool is_alphabetic_upper(char character)
{
    if(abc_index_upper(character) < 0) { return false; }
    else { return true; }
}

bool is_alphabetic_lower(char character)
{
    if(abc_index_lower(character) < 0) { return false; }
    else { return true; }
}

bool is_alphabetic(char character)
{
    return (is_alphabetic_upper(character) || is_alphabetic_lower(character));
}
