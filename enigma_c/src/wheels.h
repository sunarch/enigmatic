
#ifndef _WHEELS_H_
#define _WHEELS_H_

char ABC_UPP [27];  // ordered Alphabet
char ABC_LOW [27];  // ordered Alphabet

// Rotor wheels (wiring, turnover points, c-o info, name)
// Reflectors (UKW)

// W. I-VIII (I,M3,M4)
// I "Services" (Army, GAF)
// M3 (Army, Navy)
// M4 "Shark" (U-Boats)

char WALZE_I    [27];  //  'q', 'Q|R', 'I')
char WALZE_II   [27];  //  'e', 'E|F', 'II')
char WALZE_III  [27];  //  'v', 'V|W', 'III')
char WALZE_IV   [27];  //  'j', 'J|K', 'IV')
char WALZE_V    [27];  //  'z', 'Z|A', 'V')
char WALZE_VI   [27];  //  'zm', 'Z|A, M|N', 'VI')
char WALZE_VII  [27];  //  'zm', 'Z|A, M|N', 'VII')
char WALZE_VIII [27];  //  'zm', 'Z|A, M|N', 'VIII')

char UKW_A [27];
char UKW_B [27];
char UKW_C [27];

    // (M4):

char UKW_B_DUENN [27];  // UKW B "thin"
char UKW_C_DUENN [27];  // UKW C "thin"
char WALZE_BETA  [27];
char WALZE_GAMMA [27];

void apply_settings_services(void);
void apply_settings_army(void);
void apply_settings_navy(void);

// I-III (D)
// D (commercial)

char WALZE_1D [27];  //  'y', 'Y|Z', '1D')
char WALZE_2D [27];  //  'e', 'E|F', '2D')
char WALZE_3D [27];  //  'n', 'N|O', '3D')

char UKW_D [27];

void apply_settings_commercial(void);

// I-III (K)
// K "Swiss K" (Swiss)

char WALZE_1K [27];  //  'y', 'Y|Z', '1K')
char WALZE_2K [27];  //  'e', 'E|F', '2K')
char WALZE_3K [27];  //  'n', 'N|O', '3K')

void apply_settings_swiss(void);

// I-V (N)
// N "Norenigma" (Norway)

char WALZE_1N [27];  //  'q', 'Q|R', '1N')
char WALZE_2N [27];  //  'e', 'E|F', '2N')
char WALZE_3N [27];  //  'v', 'V|W', '3N')
char WALZE_4N [27];  //  'j', 'J|K', '4N')
char WALZE_5N [27];  //  'z', 'Z|A', '5N')

char UKW_N [27];

void apply_settings_norway(void);

// I-III (R)
// R "Rocket" (Railway)

char WALZE_1R [27];  //  'n', 'N|O', '1R')
char WALZE_2R [27];  //  'e', 'E|F', '2R')
char WALZE_3R [27];  //  'y', 'Y|Z', '3R')

char UKW_R [27];

void apply_settings_railway(void);

// I-VIII (T)
// T "Tirpitz" (Japan)

char WALZE_1T [27];  //  'wzekq', '5 notches', '1T')
char WALZE_2T [27];  //  'wzflr', '5 notches', '2T')
char WALZE_3T [27];  //  'wzekq', '5 notches', '3T')
char WALZE_4T [27];  //  'wzflr', '5 notches', '4T')
char WALZE_5T [27];  //  'ycfkr', '5 notches', '5T')
char WALZE_6T [27];  //  'xeimq', '5 notches', '6T')
char WALZE_7T [27];  //  'ycfkr', '5 notches', '7T')
char WALZE_8T [27];  //  'xeimq', '5 notches', '8T')

char UKW_T [27];

void apply_settings_tirpitz(void);

// I-III (A) [A-865]
// A-865 "Zählwerk" (1928)

char WALZE_1A8 [27];  //  'suvwzabcefgiklopq', '17 notches (A-865)', '1A8')
char WALZE_2A8 [27];  //  'stvyzacdfghkmnq', '15 notches (A-865)', '2A8')
char WALZE_3A8 [27];  //  'uwxaefhkmnr', '11 notches (A-865)', '3A8')

// (G)

char UKW_G [27];

void apply_settings_zaehlwerk(void);

// I-III (G1) [G-111]
// G-111 (Hungary / Munich)

char WALZE_1G1 [27];  //  'suvwzabcefgiklopq', '17 notches (G-111)', '1G1')
char WALZE_2G1 [27];  //  'stvyzacdfghkmnq', '15 notches (G-111)', '2G1')
char WALZE_5G1 [27];  //  'swzfhmq', '7 notches (G-111)', '5G1')

void apply_settings_hungary(void);

// I-III (G2) [G-260]
// G-260 (Abwehr in Argentina)

char WALZE_1G2 [27];  //  'suvwzabcefgiklopq', '17 notches (G-260)', '1G2')
char WALZE_2G2 [27];  //  'stvyzacdfghkmnq', '15 notches (G-260)', '2G2')
char WALZE_3G2 [27];  //  'uwxaefhkmnr', '11 notches (G-260)', '3G2')

void apply_settings_argentina(void);

// I-III (G3) [G-312]
// G-312 (Abwehr / Bletchley Park)

char WALZE_1G3 [27];  //  'suvwzabcefgiklopq', '17 notches (G-312)', '1G3')
char WALZE_2G3 [27];  //  'stvyzacdfghkmnq', '15 notches (G-312)', '2G3')
char WALZE_3G3 [27];  //  'uwxaefhkmnr', '11 notches (G-312)', '3G3')

void apply_settings_bletchley(void);

// PROGRAM VARIABLES

unsigned short wheel_offsets[10];
unsigned short wheel_count;
char *wheel_wirings[10];
char *wheel_wiring_ukw;

#endif
