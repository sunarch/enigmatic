/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef ENIGMATIC_WHEELS_H
#define ENIGMATIC_WHEELS_H

// SETTERS /////////////////////////////////////////////////////////////////////

extern void wheels_apply_default(void);
extern void wheels_apply_prompt(void);

// CALCULATORS /////////////////////////////////////////////////////////////////

extern unsigned short calculate_index_after_wiring_rule(unsigned short index_before,
                                                        signed short wiring_rule);

extern char get_wheel_output(unsigned short wheel_number,
                             unsigned short mode,
                             char input_char);

#endif // ndef ENIGMATIC_WHEELS_H
