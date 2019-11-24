
#ifndef _UTIL_DEBUG_H_
#define _UTIL_DEBUG_H_

// DEBUG macro
// if defined, debugging is on, else it is off
#define  DEBUG


#ifdef DEBUG

signed short debug_indent_level;

void print_debug_indent(void);
void inc_debug_indent(void);
void dec_debug_indent(void);

#endif

#endif
