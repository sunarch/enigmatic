/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef ENIGMATIC_PAGER_H
#define ENIGMATIC_PAGER_H

void pager_print(char *p_text,
                 unsigned short indent_length,
                 int part_max_length,
                 void (*pf_print_char_label)(void),
                 void (*pf_print_char_formatted)(char),
                 void (*pf_print_code_label)(void),
                 void (*pf_print_code_formatted)(char));

#endif // ndef ENIGMATIC_PAGER_H
