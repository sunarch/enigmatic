/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include <stdio.h>
#include <stdlib.h>

#include "wheels.h"
#include "util-debug.h"
#include "util-validate.h"

const char ABC_UPP [27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  // ordered Alphabet
const char ABC_LOW [27] = "abcdefghijklmnopqrstuvwxyz";  // ordered Alphabet

// Rotor wheels (wiring, turnover points, c-o info, name) //////////////////////
// Reflectors (UKW) ////////////////////////////////////////////////////////////

// W. I-VIII (I,M3,M4)
// I "Services" (Army, GAF)
// M3 (Army, Navy)
// M4 "Shark" (U-Boats)

const char WALZE_I    [27] = "ekmflgdqvzntowyhxuspaibrcj";  //  'q', 'Q|R', 'I')
const char WALZE_II   [27] = "ajdksiruxblhwtmcqgznpyfvoe";  //  'e', 'E|F', 'II')
const char WALZE_III  [27] = "bdfhjlcprtxvznyeiwgakmusqo";  //  'v', 'V|W', 'III')
const char WALZE_IV   [27] = "esovpzjayquirhxlnftgkdcmwb";  //  'j', 'J|K', 'IV')
const char WALZE_V    [27] = "vzbrgityupsdnhlxawmjqofeck";  //  'z', 'Z|A', 'V')
const char WALZE_VI   [27] = "jpgvoumfyqbenhzrdkasxlictw";  //  'zm', 'Z|A, M|N', 'VI')
const char WALZE_VII  [27] = "nzjhgrcxmyswboufaivlpekqdt";  //  'zm', 'Z|A, M|N', 'VII')
const char WALZE_VIII [27] = "fkqhtlxocbjspdzramewniuygv";  //  'zm', 'Z|A, M|N', 'VIII')

const char UKW_A [27] = "ejmzalyxvbwfcrquontspikhgd";
const char UKW_B [27] = "yruhqsldpxngokmiebfzcwvjat";
const char UKW_C [27] = "fvpjiaoyedrzxwgctkuqsbnmhl";

    // (M4):

const char UKW_B_DUENN [27] = "enkqauywjicopblmdxzvfthrgs";  // UKW B "thin"
const char UKW_C_DUENN [27] = "rdobjntkvehmlfcwzaxgyipsuq";  // UKW C "thin"
const char WALZE_BETA  [27] = "leyjvcnixwpbqmdrtakzgfuhos";
const char WALZE_GAMMA [27] = "fsokanuerhmbtiycwlqpzxvgjd";

void apply_settings_services(void) {
    #ifdef DEBUG
        inc_debug_indent(); // to function outer level
        print_debug_indent();
        printf("Applying settings: services\n");
    #endif

    set_used_wheel_count(5);

    set_wheel_wiring_rules(1, WALZE_I);
    set_wheel_wiring_rules(2, WALZE_II);
    set_wheel_wiring_rules(3, WALZE_III);
    set_wheel_wiring_rules(4, WALZE_IV);
    set_wheel_wiring_rules(5, WALZE_V);
    // set_wheel_wiring_rules(6, WALZE_VI);
    // set_wheel_wiring_rules(7, WALZE_VII);
    // set_wheel_wiring_rules(8, WALZE_VIII);
    // set_wheel_wiring_rules(9, ABC_LOW);
    // set_wheel_wiring_rules(10, ABC_LOW);

    set_wheel_wiring_rules(UKW_INDEX, UKW_A);

    #ifdef DEBUG
        dec_debug_indent(); // to caller level
    #endif
}

void apply_settings_army(void) {
    #ifdef DEBUG
        inc_debug_indent(); // to function outer level
        print_debug_indent();
        printf("Applying settings: army\n");
    #endif

    set_used_wheel_count(8);

    set_wheel_wiring_rules(1, WALZE_I);
    set_wheel_wiring_rules(2, WALZE_II);
    set_wheel_wiring_rules(3, WALZE_III);
    set_wheel_wiring_rules(4, WALZE_IV);
    set_wheel_wiring_rules(5, WALZE_V);
    set_wheel_wiring_rules(6, WALZE_VI);
    set_wheel_wiring_rules(7, WALZE_VII);
    set_wheel_wiring_rules(8, WALZE_VIII);
    // set_wheel_wiring_rules(9, ABC_LOW);
    // set_wheel_wiring_rules(10, ABC_LOW);

    set_wheel_wiring_rules(UKW_INDEX, UKW_B);

    #ifdef DEBUG
        dec_debug_indent(); // to caller level
    #endif
}

void apply_settings_navy(void) {
    #ifdef DEBUG
        inc_debug_indent(); // to function outer level
        print_debug_indent();
        printf("Applying settings: navy\n");
    #endif

    set_used_wheel_count(10);

    set_wheel_wiring_rules(1, WALZE_BETA);
    set_wheel_wiring_rules(2, WALZE_GAMMA);
    set_wheel_wiring_rules(3, WALZE_I);
    set_wheel_wiring_rules(4, WALZE_II);
    set_wheel_wiring_rules(5, WALZE_III);
    set_wheel_wiring_rules(6, WALZE_IV);
    set_wheel_wiring_rules(7, WALZE_V);
    set_wheel_wiring_rules(8, WALZE_VI);
    set_wheel_wiring_rules(9, WALZE_VII);
    set_wheel_wiring_rules(10, WALZE_VIII);

    set_wheel_wiring_rules(UKW_INDEX, UKW_C);

    #ifdef DEBUG
        dec_debug_indent(); // to caller level
    #endif
}

// I-III (D)
// D (commercial)

const char WALZE_1D [27] = "lpgszmhaeoqkvxrfybutnicjdw";  //  'y', 'Y|Z', '1D')
const char WALZE_2D [27] = "slvgbtfxjqohewirzyamkpcndu";  //  'e', 'E|F', '2D')
const char WALZE_3D [27] = "cjgdpshkturawzxfmynqobvlie";  //  'n', 'N|O', '3D')

const char UKW_D [27] = "imetcgfraysqbzxwlhkdvupojn";

void apply_settings_commercial(void) {
    #ifdef DEBUG
        inc_debug_indent(); // to function outer level
        print_debug_indent();
        printf("Applying settings: commercial\n");
    #endif

    set_used_wheel_count(3);

    set_wheel_wiring_rules(1, WALZE_1D);
    set_wheel_wiring_rules(2, WALZE_2D);
    set_wheel_wiring_rules(3, WALZE_3D);
    // set_wheel_wiring_rules(4, ABC_LOW);
    // set_wheel_wiring_rules(5, ABC_LOW);
    // set_wheel_wiring_rules(6, ABC_LOW);
    // set_wheel_wiring_rules(7, ABC_LOW);
    // set_wheel_wiring_rules(8, ABC_LOW);
    // set_wheel_wiring_rules(9, ABC_LOW);
    // set_wheel_wiring_rules(10, ABC_LOW);

    set_wheel_wiring_rules(UKW_INDEX, UKW_D);

    #ifdef DEBUG
        dec_debug_indent(); // to caller level
    #endif
}

// I-III (K)
// K "Swiss K" (Swiss)

const char WALZE_1K [27] = "pezuohxscvfmtbglrinqjwaydk";  //  'y', 'Y|Z', '1K')
const char WALZE_2K [27] = "zouesydkfwpciqxhmvblgnjrat";  //  'e', 'E|F', '2K')
const char WALZE_3K [27] = "ehrvxgaobqusimzflynwktpdjc";  //  'n', 'N|O', '3K')

void apply_settings_swiss(void) {
    #ifdef DEBUG
        inc_debug_indent(); // to function outer level
        print_debug_indent();
        printf("Applying settings: \"Swiss K\" (Swiss)\n");
    #endif

    set_used_wheel_count(3);

    set_wheel_wiring_rules(1, WALZE_1K);
    set_wheel_wiring_rules(2, WALZE_2K);
    set_wheel_wiring_rules(3, WALZE_3K);
    // set_wheel_wiring_rules(4, ABC_LOW);
    // set_wheel_wiring_rules(5, ABC_LOW);
    // set_wheel_wiring_rules(6, ABC_LOW);
    // set_wheel_wiring_rules(7, ABC_LOW);
    // set_wheel_wiring_rules(8, ABC_LOW);
    // set_wheel_wiring_rules(9, ABC_LOW);
    // set_wheel_wiring_rules(10, ABC_LOW);

    set_wheel_wiring_rules(UKW_INDEX, ABC_LOW);

    #ifdef DEBUG
        dec_debug_indent(); // to caller level
    #endif
}

// I-V (N)
// N "Norenigma" (Norway)

const char WALZE_1N [27] = "wtokasuyvrbxjhqcpzefmdinlg";  //  'q', 'Q|R', '1N')
const char WALZE_2N [27] = "gjlpubswemctqvhxaofzdrkyni";  //  'e', 'E|F', '2N')
const char WALZE_3N [27] = "jwfmhnbpusdytixvzgrqlaoekc";  //  'v', 'V|W', '3N')
const char WALZE_4N [27] = "esovpzjayquirhxlnftgkdcmwb";  //  'j', 'J|K', '4N')
const char WALZE_5N [27] = "hejxqotzbvfdascilwpgynmurk";  //  'z', 'Z|A', '5N')

const char UKW_N [27] = "mowjypuxndsraibfvlkzgqchet";

void apply_settings_norway(void) {
    #ifdef DEBUG
        inc_debug_indent(); // to function outer level
        print_debug_indent();
        printf("Applying settings: \"Norenigma\" (Norway)\n");
    #endif

    set_used_wheel_count(5);

    set_wheel_wiring_rules(1, WALZE_1N);
    set_wheel_wiring_rules(2, WALZE_2N);
    set_wheel_wiring_rules(3, WALZE_3N);
    set_wheel_wiring_rules(4, WALZE_4N);
    set_wheel_wiring_rules(5, WALZE_5N);
    // set_wheel_wiring_rules(6, ABC_LOW);
    // set_wheel_wiring_rules(7, ABC_LOW);
    // set_wheel_wiring_rules(8, ABC_LOW);
    // set_wheel_wiring_rules(9, ABC_LOW);
    // set_wheel_wiring_rules(10, ABC_LOW);

    set_wheel_wiring_rules(UKW_INDEX, UKW_N);

    #ifdef DEBUG
        dec_debug_indent(); // to caller level
    #endif
}

// I-III (R)
// R "Rocket" (Railway)

const char WALZE_1R [27] = "jgdqoxuscamifrvtpnewkblzyh";  //  'n', 'N|O', '1R')
const char WALZE_2R [27] = "ntzpsfbokmwrcjdivlaeyuxhgq";  //  'e', 'E|F', '2R')
const char WALZE_3R [27] = "jviubhtcdyakeqzposgxnrmwfl";  //  'y', 'Y|Z', '3R')

const char UKW_R [27] = "qyhognecvpuztfdjaxwmkisrbl";

void apply_settings_railway(void) {
    #ifdef DEBUG
        inc_debug_indent(); // to function outer level
        print_debug_indent();
        printf("Applying settings: \"Rocket\" (Railway)\n");
    #endif

    set_used_wheel_count(3);

    set_wheel_wiring_rules(1, WALZE_1R);
    set_wheel_wiring_rules(2, WALZE_2R);
    set_wheel_wiring_rules(3, WALZE_3R);
    // set_wheel_wiring_rules(4, ABC_LOW);
    // set_wheel_wiring_rules(5, ABC_LOW);
    // set_wheel_wiring_rules(6, ABC_LOW);
    // set_wheel_wiring_rules(7, ABC_LOW);
    // set_wheel_wiring_rules(8, ABC_LOW);
    // set_wheel_wiring_rules(9, ABC_LOW);
    // set_wheel_wiring_rules(10, ABC_LOW);

    set_wheel_wiring_rules(UKW_INDEX, UKW_R);

    #ifdef DEBUG
        dec_debug_indent(); // to caller level
    #endif
}

// I-VIII (T)
// T "Tirpitz" (Japan)

const char WALZE_1T [27] = "kptyuelocvgrfqdanjmbswhzxi";  //  'wzekq', '5 notches', '1T')
const char WALZE_2T [27] = "uphzlweqmtdjxcaksoigvbyfnr";  //  'wzflr', '5 notches', '2T')
const char WALZE_3T [27] = "qudlyrfekonvzaxwhmgpjbsict";  //  'wzekq', '5 notches', '3T')
const char WALZE_4T [27] = "ciwtbkxnrespflydagvhquojzm";  //  'wzflr', '5 notches', '4T')
const char WALZE_5T [27] = "uaxgisnjbverdylfzwtpckohmq";  //  'ycfkr', '5 notches', '5T')
const char WALZE_6T [27] = "xfuzgalvhcnysewqtdmrbkpioj";  //  'xeimq', '5 notches', '6T')
const char WALZE_7T [27] = "bjvftxplnayozikwgdqeruchsm";  //  'ycfkr', '5 notches', '7T')
const char WALZE_8T [27] = "ymtpnzhwkodajxeluqvgcbisfr";  //  'xeimq', '5 notches', '8T')

const char UKW_T [27] = "gekpbtaumocniljdxzyfhwvqsr";

void apply_settings_tirpitz(void) {
    #ifdef DEBUG
        inc_debug_indent(); // to function outer level
        print_debug_indent();
        printf("Applying settings: \"Tirpitz\" (Japan)\n");
    #endif

    set_used_wheel_count(8);

    set_wheel_wiring_rules(1, WALZE_1T);
    set_wheel_wiring_rules(2, WALZE_2T);
    set_wheel_wiring_rules(3, WALZE_3T);
    set_wheel_wiring_rules(4, WALZE_4T);
    set_wheel_wiring_rules(5, WALZE_5T);
    set_wheel_wiring_rules(6, WALZE_6T);
    set_wheel_wiring_rules(7, WALZE_7T);
    set_wheel_wiring_rules(8, WALZE_8T);
    // set_wheel_wiring_rules(9, ABC_LOW);
    // set_wheel_wiring_rules(10, ABC_LOW);

    set_wheel_wiring_rules(UKW_INDEX, UKW_T);

    #ifdef DEBUG
        dec_debug_indent(); // to caller level
    #endif
}

// I-III (A) [A-865]
// A-865 "Zählwerk" (1928)

const char WALZE_1A8 [27] = "lpgszmhaeoqkvxrfybutnicjdw";  //  'suvwzabcefgiklopq', '17 notches (A-865)', '1A8')
const char WALZE_2A8 [27] = "slvgbtfxjqohewirzyamkpcndu";  //  'stvyzacdfghkmnq', '15 notches (A-865)', '2A8')
const char WALZE_3A8 [27] = "cjgdpshkturawzxfmynqobvlie";  //  'uwxaefhkmnr', '11 notches (A-865)', '3A8')

// (G)

const char UKW_G [27] = "rulqmzjsygocetkwdahnbxpvif";

void apply_settings_zaehlwerk(void) {
    #ifdef DEBUG
        inc_debug_indent(); // to function outer level
        print_debug_indent();
        printf("Applying settings: \"Zählwerk\" (1928)\n");
    #endif

    set_used_wheel_count(3);

    set_wheel_wiring_rules(1, WALZE_1A8);
    set_wheel_wiring_rules(2, WALZE_2A8);
    set_wheel_wiring_rules(3, WALZE_3A8);
    // set_wheel_wiring_rules(4, ABC_LOW);
    // set_wheel_wiring_rules(5, ABC_LOW);
    // set_wheel_wiring_rules(6, ABC_LOW);
    // set_wheel_wiring_rules(7, ABC_LOW);
    // set_wheel_wiring_rules(8, ABC_LOW);
    // set_wheel_wiring_rules(9, ABC_LOW);
    // set_wheel_wiring_rules(10, ABC_LOW);

    set_wheel_wiring_rules(UKW_INDEX, ABC_LOW);

    #ifdef DEBUG
        dec_debug_indent(); // to caller level
    #endif
}

// I-III (G1) [G-111]
// G-111 (Hungary / Munich)

const char WALZE_1G1 [27] = "wlrhbqundkjczsexotmagyfpvi";  //  'suvwzabcefgiklopq', '17 notches (G-111)', '1G1')
const char WALZE_2G1 [27] = "tfjqazwmhlcuixrdygoevbnskp";  //  'stvyzacdfghkmnq', '15 notches (G-111)', '2G1')
const char WALZE_5G1 [27] = "qtpixwvdfrmusljohcanezkybg";  //  'swzfhmq', '7 notches (G-111)', '5G1')

void apply_settings_hungary(void) {
    #ifdef DEBUG
        inc_debug_indent(); // to function outer level
        print_debug_indent();
        printf("Applying settings: Hungary / Munich\n");
    #endif

    set_used_wheel_count(3);

    set_wheel_wiring_rules(1, WALZE_1G1);
    set_wheel_wiring_rules(2, WALZE_2G1);
    set_wheel_wiring_rules(3, WALZE_5G1);
    // set_wheel_wiring_rules(4, ABC_LOW);
    // set_wheel_wiring_rules(5, ABC_LOW);
    // set_wheel_wiring_rules(6, ABC_LOW);
    // set_wheel_wiring_rules(7, ABC_LOW);
    // set_wheel_wiring_rules(8, ABC_LOW);
    // set_wheel_wiring_rules(9, ABC_LOW);
    // set_wheel_wiring_rules(10, ABC_LOW);

    set_wheel_wiring_rules(UKW_INDEX, UKW_G);

    #ifdef DEBUG
        dec_debug_indent(); // to caller level
    #endif
}

// I-III (G2) [G-260]
// G-260 (Abwehr in Argentina)

const char WALZE_1G2 [27] = "rcspblkqaumhwytifzvgojnexd";  //  'suvwzabcefgiklopq', '17 notches (G-260)', '1G2')
const char WALZE_2G2 [27] = "wcmibvpjxarosgndlzkeyhufqt";  //  'stvyzacdfghkmnq', '15 notches (G-260)', '2G2')
const char WALZE_3G2 [27] = "fvdhzelsqmaxokyiwpgcbujtnr";  //  'uwxaefhkmnr', '11 notches (G-260)', '3G2')

void apply_settings_argentina(void) {
    #ifdef DEBUG
        inc_debug_indent(); // to function outer level
        print_debug_indent();
        printf("Applying settings: Abwehr in Argentina\n");
    #endif

    set_used_wheel_count(3);

    set_wheel_wiring_rules(1, WALZE_1G2);
    set_wheel_wiring_rules(2, WALZE_2G2);
    set_wheel_wiring_rules(3, WALZE_3G2);
    // set_wheel_wiring_rules(4, ABC_LOW);
    // set_wheel_wiring_rules(5, ABC_LOW);
    // set_wheel_wiring_rules(6, ABC_LOW);
    // set_wheel_wiring_rules(7, ABC_LOW);
    // set_wheel_wiring_rules(8, ABC_LOW);
    // set_wheel_wiring_rules(9, ABC_LOW);
    // set_wheel_wiring_rules(10, ABC_LOW);

    set_wheel_wiring_rules(UKW_INDEX, UKW_G);

    #ifdef DEBUG
        dec_debug_indent(); // to caller level
    #endif
}

// I-III (G3) [G-312]
// G-312 (Abwehr / Bletchley Park)

const char WALZE_1G3 [27] = "dmtwsilruyqnkfejcazbpgxohv";  //  'suvwzabcefgiklopq', '17 notches (G-312)', '1G3')
const char WALZE_2G3 [27] = "hqzgpjtmoblncifdyawveusrkx";  //  'stvyzacdfghkmnq', '15 notches (G-312)', '2G3')
const char WALZE_3G3 [27] = "uqntlszfmrehdpxkibvygjcwoa";  //  'uwxaefhkmnr', '11 notches (G-312)', '3G3')

void apply_settings_bletchley(void) {
    #ifdef DEBUG
        inc_debug_indent(); // to function outer level
        print_debug_indent();
        printf("Applying settings: Abwehr / Bletchley Park\n");
    #endif

    set_used_wheel_count(3);

    set_wheel_wiring_rules(1, WALZE_1G3);
    set_wheel_wiring_rules(2, WALZE_2G3);
    set_wheel_wiring_rules(3, WALZE_3G3);
    // set_wheel_wiring_rules(4, ABC_LOW);
    // set_wheel_wiring_rules(5, ABC_LOW);
    // set_wheel_wiring_rules(6, ABC_LOW);
    // set_wheel_wiring_rules(7, ABC_LOW);
    // set_wheel_wiring_rules(8, ABC_LOW);
    // set_wheel_wiring_rules(9, ABC_LOW);
    // set_wheel_wiring_rules(10, ABC_LOW);

    set_wheel_wiring_rules(UKW_INDEX, UKW_G);

    #ifdef DEBUG
        dec_debug_indent(); // to caller level
    #endif
}

void apply_settings_default(void) {
    #ifdef DEBUG
        inc_debug_indent(); // to function outer level
        print_debug_indent();
        printf("Applying settings: (default)\n");
    #endif

    apply_settings_bletchley();

    #ifdef DEBUG
        dec_debug_indent(); // to caller level
    #endif
}

// PROGRAM VARIABLES ///////////////////////////////////////////////////////////

// unsigned short used_wheel_count;
unsigned short wheel_offsets[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
// signed short wheel_wiring_rules_front[11][26];
// signed short wheel_wiring_rules_reverse[11][26];

// OTHER FUNCTIONS /////////////////////////////////////////////////////////////

unsigned short get_wheel_offset(unsigned short wheel_number) {
    // no debug messages in getter functions, include them as checks in calls

    // validate wheel_number
    validate_wheel_number_any(wheel_number, get_used_wheel_count());

    return wheel_offsets[wheel_number];
}

void set_wheel_offset(unsigned short wheel_number, unsigned short new_offset) {
    #ifdef DEBUG
        inc_debug_indent();  // to function call level
        print_debug_indent();
        printf("FUNC: void set_wheel_offset(...) // unsigned short wheel_number = %u // unsigned short new_offset = %u\n", wheel_number, new_offset);
    #endif

    // validate wheel_number
    validate_wheel_number_any(wheel_number, get_used_wheel_count());

    // change wheel offset
    wheel_offsets[wheel_number] = new_offset % 26;

    #ifdef DEBUG
        inc_debug_indent();  // to function result level
        print_debug_indent();
        printf("CHECK: get_wheel_offset(%u) returns %u\n", wheel_number, get_wheel_offset(wheel_number));
        dec_debug_indent();  // to function call level
        dec_debug_indent();  // to caller level
    #endif
}

void reset_wheel_offsets(void) {
    #ifdef DEBUG
        inc_debug_indent();  // to function call level
        print_debug_indent();
        printf("FUNC: void reset_wheel_offsets(void)\n");
    #endif

    for (unsigned short n = 0; n < 11; ++n) {
        wheel_offsets[n] = 0;
    }

    #ifdef DEBUG
        inc_debug_indent();  // to function result level
        unsigned short check_value_wheel_offset = get_wheel_offset(0);
        print_debug_indent();
        printf("CHECK: get_wheel_offset(...) // wheel_number = 0 // %u // should always be 0 (UKW)\n", check_value_wheel_offset);
        for (unsigned short n = 1; n <= get_used_wheel_count(); ++n) {
            check_value_wheel_offset =  get_wheel_offset(n);
            print_debug_indent();
            printf("CHECK: get_wheel_offset(...) // wheel_number = %u // %u\n", n, check_value_wheel_offset);
        }
        dec_debug_indent();  // to function call level
        dec_debug_indent();  // to caller level
    #endif
}

signed short *get_wheel_wiring_rules_front(unsigned short wheel_number) {
    // no debug messages in getter functions, include them as checks in calls

    // validate wheel number
    validate_wheel_number_any(wheel_number, get_used_wheel_count());

    return wheel_wiring_rules_front[wheel_number];
}

signed short *get_wheel_wiring_rules_reverse(unsigned short wheel_number) {
    // no debug messages in getter functions, include them as checks in calls

    // validate wheel number
    validate_wheel_number_any(wheel_number, get_used_wheel_count());

    return wheel_wiring_rules_reverse[wheel_number];
}

void set_wheel_wiring_rules(unsigned short wheel_number, const char *const wiring_alphabet) {
    // validate wheel number
    validate_wheel_number_any(wheel_number, get_used_wheel_count());

    signed short wiring_rule;

    for (unsigned short n = 0; n < 26; ++n) {
        wiring_rule = (signed short) ((wiring_alphabet[n] - ABC_LOW[n]) % 26);
        wheel_wiring_rules_front[wheel_number][n] = wiring_rule;
        wheel_wiring_rules_reverse[wheel_number][(n + wiring_rule) % 26] = (-1) * wiring_rule;
    }
}

unsigned short get_used_wheel_count(void) {
    // no debug messages in getter functions, include them as checks in calls

    return used_wheel_count;
}

void set_used_wheel_count(unsigned short new_wheel_count) {
    #ifdef DEBUG
        inc_debug_indent();  // to function call level
        print_debug_indent();
        printf("FUNC: void set_used_wheel_count(...) // unsigned short new_wheel_count = %u\n", new_wheel_count);
    #endif

    if (new_wheel_count > MAX_WHEEL_COUNT) {
        printf("Failed check with (new_wheel_count > %i): (%u > %i)\n", MAX_WHEEL_COUNT, new_wheel_count, MAX_WHEEL_COUNT);
        printf("Exiting...");
        exit(1);
    }

    used_wheel_count = new_wheel_count;

    // reset wheel offsets
    reset_wheel_offsets();

    #ifdef DEBUG
        inc_debug_indent();  // to function result level
        print_debug_indent();
        printf("CHECK: get_used_wheel_count() returns %u\n", get_used_wheel_count());
        dec_debug_indent();  // to function call level
        dec_debug_indent();  // to caller level
    #endif
}
