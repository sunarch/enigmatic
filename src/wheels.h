/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#ifndef _WHEELS_H_
#define _WHEELS_H_

const char ABC_UPP [27];  // ordered Alphabet
const char ABC_LOW [27];  // ordered Alphabet

// Rotor wheels (wiring, turnover points, c-o info, name) //////////////////////
// Reflectors (UKW) ////////////////////////////////////////////////////////////

// W. I-VIII (I,M3,M4)
// I "Services" (Army, GAF)
// M3 (Army, Navy)
// M4 "Shark" (U-Boats)

const char WALZE_I    [27];  //  'q', 'Q|R', 'I')
const char WALZE_II   [27];  //  'e', 'E|F', 'II')
const char WALZE_III  [27];  //  'v', 'V|W', 'III')
const char WALZE_IV   [27];  //  'j', 'J|K', 'IV')
const char WALZE_V    [27];  //  'z', 'Z|A', 'V')
const char WALZE_VI   [27];  //  'zm', 'Z|A, M|N', 'VI')
const char WALZE_VII  [27];  //  'zm', 'Z|A, M|N', 'VII')
const char WALZE_VIII [27];  //  'zm', 'Z|A, M|N', 'VIII')

const char UKW_A [27];
const char UKW_B [27];
const char UKW_C [27];

    // (M4):

const char UKW_B_DUENN [27];  // UKW B "thin"
const char UKW_C_DUENN [27];  // UKW C "thin"
const char WALZE_BETA  [27];
const char WALZE_GAMMA [27];

void apply_settings_services(void);
void apply_settings_army(void);
void apply_settings_navy(void);

// I-III (D)
// D (commercial)

const char WALZE_1D [27];  //  'y', 'Y|Z', '1D')
const char WALZE_2D [27];  //  'e', 'E|F', '2D')
const char WALZE_3D [27];  //  'n', 'N|O', '3D')

const char UKW_D [27];

void apply_settings_commercial(void);

// I-III (K)
// K "Swiss K" (Swiss)

const char WALZE_1K [27];  //  'y', 'Y|Z', '1K')
const char WALZE_2K [27];  //  'e', 'E|F', '2K')
const char WALZE_3K [27];  //  'n', 'N|O', '3K')

void apply_settings_swiss(void);

// I-V (N)
// N "Norenigma" (Norway)

const char WALZE_1N [27];  //  'q', 'Q|R', '1N')
const char WALZE_2N [27];  //  'e', 'E|F', '2N')
const char WALZE_3N [27];  //  'v', 'V|W', '3N')
const char WALZE_4N [27];  //  'j', 'J|K', '4N')
const char WALZE_5N [27];  //  'z', 'Z|A', '5N')

const char UKW_N [27];

void apply_settings_norway(void);

// I-III (R)
// R "Rocket" (Railway)

const char WALZE_1R [27];  //  'n', 'N|O', '1R')
const char WALZE_2R [27];  //  'e', 'E|F', '2R')
const char WALZE_3R [27];  //  'y', 'Y|Z', '3R')

const char UKW_R [27];

void apply_settings_railway(void);

// I-VIII (T)
// T "Tirpitz" (Japan)

const char WALZE_1T [27];  //  'wzekq', '5 notches', '1T')
const char WALZE_2T [27];  //  'wzflr', '5 notches', '2T')
const char WALZE_3T [27];  //  'wzekq', '5 notches', '3T')
const char WALZE_4T [27];  //  'wzflr', '5 notches', '4T')
const char WALZE_5T [27];  //  'ycfkr', '5 notches', '5T')
const char WALZE_6T [27];  //  'xeimq', '5 notches', '6T')
const char WALZE_7T [27];  //  'ycfkr', '5 notches', '7T')
const char WALZE_8T [27];  //  'xeimq', '5 notches', '8T')

const char UKW_T [27];

void apply_settings_tirpitz(void);

// I-III (A) [A-865]
// A-865 "Zählwerk" (1928)

const char WALZE_1A8 [27];  //  'suvwzabcefgiklopq', '17 notches (A-865)', '1A8')
const char WALZE_2A8 [27];  //  'stvyzacdfghkmnq', '15 notches (A-865)', '2A8')
const char WALZE_3A8 [27];  //  'uwxaefhkmnr', '11 notches (A-865)', '3A8')

// (G)

const char UKW_G [27];

void apply_settings_zaehlwerk(void);

// I-III (G1) [G-111]
// G-111 (Hungary / Munich)

const char WALZE_1G1 [27];  //  'suvwzabcefgiklopq', '17 notches (G-111)', '1G1')
const char WALZE_2G1 [27];  //  'stvyzacdfghkmnq', '15 notches (G-111)', '2G1')
const char WALZE_5G1 [27];  //  'swzfhmq', '7 notches (G-111)', '5G1')

void apply_settings_hungary(void);

// I-III (G2) [G-260]
// G-260 (Abwehr in Argentina)

const char WALZE_1G2 [27];  //  'suvwzabcefgiklopq', '17 notches (G-260)', '1G2')
const char WALZE_2G2 [27];  //  'stvyzacdfghkmnq', '15 notches (G-260)', '2G2')
const char WALZE_3G2 [27];  //  'uwxaefhkmnr', '11 notches (G-260)', '3G2')

void apply_settings_argentina(void);

// I-III (G3) [G-312]
// G-312 (Abwehr / Bletchley Park)

const char WALZE_1G3 [27];  //  'suvwzabcefgiklopq', '17 notches (G-312)', '1G3')
const char WALZE_2G3 [27];  //  'stvyzacdfghkmnq', '15 notches (G-312)', '2G3')
const char WALZE_3G3 [27];  //  'uwxaefhkmnr', '11 notches (G-312)', '3G3')

void apply_settings_bletchley(void);

void apply_settings_default(void);

// PROGRAM VARIABLES ///////////////////////////////////////////////////////////

#define  MAX_WHEEL_COUNT  10
#define  UKW_INDEX  0

unsigned short used_wheel_count;
unsigned short wheel_offsets[11];
signed short wheel_wiring_rules_front[11][26];
signed short wheel_wiring_rules_reverse[11][26];

// OTHER FUNCTIONS /////////////////////////////////////////////////////////////

unsigned short get_wheel_offset(unsigned short wheelNumber);
void set_wheel_offset(unsigned short wheelNumber, unsigned short new_offset);
void reset_wheel_offsets(void);

signed short *get_wheel_wiring_rules_front(unsigned short wheel_number);
signed short *get_wheel_wiring_rules_reverse(unsigned short wheel_number);

void set_wheel_wiring_rules(unsigned short wheel_number, const char *const wiring_alphabet);

unsigned short get_used_wheel_count(void);
void set_used_wheel_count(unsigned short count);

#endif
