/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#ifndef _UTIL_DEBUG_H_
#define _UTIL_DEBUG_H_

#ifdef DEBUG

void debug_print_indent(void);
void inc_debug_indent(void);
void dec_debug_indent(void);

void print_as_ascii(char *p_text);

#endif

#endif
