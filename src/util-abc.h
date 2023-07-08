/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef ENIGMATIC_UTIL_ABC_H
#define ENIGMATIC_UTIL_ABC_H

#include <stdbool.h>

// GETTERS /////////////////////////////////////////////////////////////////////

extern char abc_char_upper_from_index(unsigned int index);
extern char abc_char_lower_from_index(unsigned int index);

// SEARCH //////////////////////////////////////////////////////////////////////

extern short abc_index_from_char_upper(char character);
extern short abc_index_from_char_lower(char character);

// CHECK ///////////////////////////////////////////////////////////////////////

extern bool abc_is_valid_char_upper(char character);
extern bool abc_is_valid_char_lower(char character);
extern bool abc_is_valid_char(char character);

#endif // ndef ENIGMATIC_UTIL_ABC_H
