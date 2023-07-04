/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef ENIGMATIC_WHEELS_H
#define ENIGMATIC_WHEELS_H

// settings ////////////////////////////////////////////////////////////////////

extern void wheels_apply_default(void);
extern void wheels_apply_prompt(void);

// GENERAL CONSTANTS ///////////////////////////////////////////////////////////

#ifndef STRCMP_EQUAL
    #define  STRCMP_EQUAL  0
#endif // ndef STRCMP_EQUAL

#ifndef UKW_INDEX
    #define  UKW_INDEX  0
#endif // ndef UKW_INDEX

// OTHER FUNCTIONS /////////////////////////////////////////////////////////////

extern void validate_wheel_number(unsigned short wheel_number);

extern unsigned short get_wheel_offset(unsigned short wheelNumber);

extern void set_wheel_offset(unsigned short wheelNumber,
                             unsigned short new_offset);

extern void reset_wheel_offsets(void);

extern signed short *get_wheel_wiring_rules_front(unsigned short wheel_number);
extern signed short *get_wheel_wiring_rules_reverse(unsigned short wheel_number);

extern unsigned short wheels_get_count(void);

void collect_wheel_wiring_rules_front_for_position(unsigned short position, signed short *rules);
void collect_wheel_wiring_rules_reverse_for_position(unsigned short position, signed short *rules);

#endif // ndef ENIGMATIC_WHEELS_H
