/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef _WHEELS_H_
#define _WHEELS_H_

// Rotor wheels (wiring, turnover points, c-o info, name) //////////////////////
// Reflectors (UKW) ////////////////////////////////////////////////////////////

extern void apply_settings_services(void);
extern void apply_settings_army(void);
extern void apply_settings_navy(void);
extern void apply_settings_commercial(void);
extern void apply_settings_swiss(void);
extern void apply_settings_norway(void);
extern void apply_settings_railway(void);
extern void apply_settings_tirpitz(void);
extern void apply_settings_zaehlwerk(void);
extern void apply_settings_hungary(void);
extern void apply_settings_argentina(void);
extern void apply_settings_bletchley(void);
extern void apply_settings_default(void);

// PROGRAM VARIABLES ///////////////////////////////////////////////////////////

#define  MAX_WHEEL_COUNT  10
#define  UKW_INDEX  0

// OTHER FUNCTIONS /////////////////////////////////////////////////////////////

extern void validate_wheel_number(unsigned short wheel_number,
                                  unsigned short wheel_count);

extern unsigned short get_wheel_offset(unsigned short wheelNumber);

extern void set_wheel_offset(unsigned short wheelNumber,
                             unsigned short new_offset);

extern void reset_wheel_offsets(void);

extern signed short *get_wheel_wiring_rules_front(unsigned short wheel_number);
extern signed short *get_wheel_wiring_rules_reverse(unsigned short wheel_number);

extern unsigned short get_used_wheel_count(void);

void collect_wheel_wiring_rules_front_for_position(unsigned short position, signed short *rules);
void collect_wheel_wiring_rules_reverse_for_position(unsigned short position, signed short *rules);

#endif // ndef _WHEELS_H_
