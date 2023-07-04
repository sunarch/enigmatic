/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <stdbool.h>

#ifndef ENIGMATIC_ALPHABET_H
#define ENIGMATIC_ALPHABET_H

// MACRO VALUES ////////////////////////////////////////////////////////////////

# define  ABC_LENGTH  26 // English alphabet
# define  ABC_LENGTH_STRING  ABC_LENGTH + 1 // letters + \0

// PUBLIC CONSTANTS ////////////////////////////////////////////////////////////

extern const char ABC_UPPER [ABC_LENGTH_STRING];
extern const char ABC_LOWER [ABC_LENGTH_STRING];

// GETTERS /////////////////////////////////////////////////////////////////////

extern char abc_upper(unsigned int index);
extern char abc_lower(unsigned int index);

// SEARCH //////////////////////////////////////////////////////////////////////

extern short abc_index_upper(char character);
extern short abc_index_lower(char character);

// CHECK ///////////////////////////////////////////////////////////////////////

extern bool is_alphabetic_upper(char character);
extern bool is_alphabetic_lower(char character);
extern bool is_alphabetic(char character);

#endif // ndef ENIGMATIC_ALPHABET_H
