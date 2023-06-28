/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef _USAGE_H_
#define _USAGE_H_

#define  WHEEL_MODE_UKW      0
#define  WHEEL_MODE_FRONT    1
#define  WHEEL_MODE_REVERSE  2

unsigned short calculate_index_after_wiring_rule(unsigned short index_before,
                                                        signed short wiring_rule);

extern char * process_message(char *p_input_string,
                              char *p_output_string);

#endif // ndef _USAGE_H_
