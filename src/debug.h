/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef ENIGMATIC_UTIL_DEBUG_H
#define ENIGMATIC_UTIL_DEBUG_H

extern void debug_print_as_ascii(char *p_text);

#ifdef DEBUG

extern void debug_indent_print(void);
extern void debug_indent_increment(void);
extern void debug_indent_decrement(void);

#endif // def DEBUG

#endif // ndef ENIGMATIC_UTIL_DEBUG_H
