//
// Created by anemeth on 2023.07.04..
//

#ifndef _ALPHABET_H_
#define _ALPHABET_H_

// PROGRAM VALUES //////////////////////////////////////////////////////////////

# define  ABC_LENGTH  26 // English alphabet
# define  ABC_LENGTH_STRING  ABC_LENGTH + 1 // letters + \0

// PROGRAM CONSTANTS ///////////////////////////////////////////////////////////

extern const char ABC_UPPER [ABC_LENGTH_STRING];
extern const char ABC_LOWER [ABC_LENGTH_STRING];

// PROGRAM CONSTANT ACCESSORS //////////////////////////////////////////////////

extern char abc_upper(unsigned int index);
extern char abc_lower(unsigned int index);

#endif // ndef _ALPHABET_H_
