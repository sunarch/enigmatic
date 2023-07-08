/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef ENIGMATIC_PAGER_H
#define ENIGMATIC_PAGER_H

int pager_print_line(char *p_text, int starting_index, int part_max_length, void (*pf_print_formatted)(char));

#endif // ndef ENIGMATIC_PAGER_H
