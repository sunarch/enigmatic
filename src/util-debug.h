/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#ifndef _UTIL_DEBUG_H_
#define _UTIL_DEBUG_H_

// DEBUG macro
// if defined, debugging is on, else it is off
#define  DEBUG


#ifdef DEBUG

void print_debug_indent(void);
void inc_debug_indent(void);
void dec_debug_indent(void);

#endif

#endif
