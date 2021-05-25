/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#ifndef _WHEELS_H_
#define _WHEELS_H_

extern const char ABC_UPP [27];  // ordered Alphabet
extern const char ABC_LOW [27];  // ordered Alphabet

// Rotor wheels (wiring, turnover points, c-o info, name) //////////////////////
// Reflectors (UKW) ////////////////////////////////////////////////////////////

void apply_settings_services(void);
void apply_settings_army(void);
void apply_settings_navy(void);
void apply_settings_commercial(void);
void apply_settings_swiss(void);
void apply_settings_norway(void);
void apply_settings_railway(void);
void apply_settings_tirpitz(void);
void apply_settings_zaehlwerk(void);
void apply_settings_hungary(void);
void apply_settings_argentina(void);
void apply_settings_bletchley(void);
void apply_settings_default(void);

// PROGRAM VARIABLES ///////////////////////////////////////////////////////////

#define  MAX_WHEEL_COUNT  10
#define  UKW_INDEX  0

// OTHER FUNCTIONS /////////////////////////////////////////////////////////////

unsigned short get_wheel_offset(unsigned short wheelNumber);
void set_wheel_offset(unsigned short wheelNumber, unsigned short new_offset);
void reset_wheel_offsets(void);

signed short *get_wheel_wiring_rules_front(unsigned short wheel_number);
signed short *get_wheel_wiring_rules_reverse(unsigned short wheel_number);

unsigned short get_used_wheel_count(void);

#endif
