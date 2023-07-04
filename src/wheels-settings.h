/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef ENIGMATIC_WHEELS_SETTINGS_H
#define ENIGMATIC_WHEELS_SETTINGS_H

// GENERAL CONSTANTS ///////////////////////////////////////////////////////////

#define  MAX_WHEEL_COUNT  10
#define  UKW_INDEX  0

// GENERAL VARIABLES ///////////////////////////////////////////////////////////

extern signed short wheel_wiring_rules_front[11][26];
extern signed short wheel_wiring_rules_reverse[11][26];

// INTERNAL VARIABLES - ACCESSORS //////////////////////////////////////////////

extern unsigned short get_used_wheel_count(void);

// Rotor wheels (wiring, turnover points, c-o info, name) //////////////////////
// Reflectors (UKW) ////////////////////////////////////////////////////////////

extern void apply_settings_default(void);

extern void apply_settings_argentina(void);
extern void apply_settings_army(void);
extern void apply_settings_bletchley(void);
extern void apply_settings_commercial(void);
extern void apply_settings_hungary(void);
extern void apply_settings_navy(void);
extern void apply_settings_norway(void);
extern void apply_settings_railway(void);
extern void apply_settings_services(void);
extern void apply_settings_swiss(void);
extern void apply_settings_tirpitz(void);
extern void apply_settings_zaehlwerk(void);

#endif //ENIGMATIC_WHEELS_SETTINGS_H
