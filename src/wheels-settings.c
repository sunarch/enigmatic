/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <stdio.h>
#include <stdlib.h>

#include "alphabet.h"
#include "wheels-settings.h"

#ifdef DEBUG
    #include "debug.h"
#endif

// GENERAL VARIABLES ///////////////////////////////////////////////////////////

signed short wheel_wiring_rules_front[11][26];
signed short wheel_wiring_rules_reverse[11][26];

// INTERNAL VARIABLES //////////////////////////////////////////////////////////

static unsigned short used_wheel_count;

// INTERNAL VARIABLES - ACCESSORS //////////////////////////////////////////////

unsigned short get_used_wheel_count(void)
{
    // no debug messages in getter functions, include them as checks in calls

    return used_wheel_count;
}

// INTERNAL FUNCTIONS //////////////////////////////////////////////////////////

static void set_used_wheel_count(unsigned short new_wheel_count)
{
#ifdef DEBUG
    debug_indent_increment();  // to function call level
        debug_indent_print();
        printf("FUNC: void set_used_wheel_count(...) // unsigned short new_wheel_count = %u\n", new_wheel_count);
#endif

    if (new_wheel_count > MAX_WHEEL_COUNT) {
        printf("Failed check with (new_wheel_count > %i): (%u > %i)\n", MAX_WHEEL_COUNT, new_wheel_count, MAX_WHEEL_COUNT);
        printf("Exiting...");
        exit(1);
    }

    used_wheel_count = new_wheel_count;

#ifdef DEBUG
    debug_indent_increment();  // to function result level
        debug_indent_print();
        printf("CHECK: get_used_wheel_count() returns %u\n", get_used_wheel_count());
        debug_indent_decrement();  // to function call level
        debug_indent_decrement();  // to caller level
#endif
}

static void set_wheel_wiring_rules(unsigned short wheel_number,
                                   const char *const wiring_alphabet)
{

    signed short wiring_rule;

    for (unsigned short n = 0; n < 26; ++n) {
        wiring_rule = (signed short) ((wiring_alphabet[n] - abc_lower(n)) % 26);
        wheel_wiring_rules_front[wheel_number][n] = wiring_rule;
        wheel_wiring_rules_reverse[wheel_number][(n + wiring_rule) % 26] = (-1) * wiring_rule;
    }
}

// Rotor wheels (wiring, turnover points, c-o info, name) //////////////////////
// Reflectors (UKW) ////////////////////////////////////////////////////////////

// =============================================================================

// W. I-VIII (I,M3,M4)
// I "Services" (Army, GAF)
// M3 (Army, Navy)
// M4 "Shark" (U-Boats)

static const char WALZE_I    [27] = "ekmflgdqvzntowyhxuspaibrcj";  //  'q', 'Q|R', 'I')
static const char WALZE_II   [27] = "ajdksiruxblhwtmcqgznpyfvoe";  //  'e', 'E|F', 'II')
static const char WALZE_III  [27] = "bdfhjlcprtxvznyeiwgakmusqo";  //  'v', 'V|W', 'III')
static const char WALZE_IV   [27] = "esovpzjayquirhxlnftgkdcmwb";  //  'j', 'J|K', 'IV')
static const char WALZE_V    [27] = "vzbrgityupsdnhlxawmjqofeck";  //  'z', 'Z|A', 'V')
static const char WALZE_VI   [27] = "jpgvoumfyqbenhzrdkasxlictw";  //  'zm', 'Z|A, M|N', 'VI')
static const char WALZE_VII  [27] = "nzjhgrcxmyswboufaivlpekqdt";  //  'zm', 'Z|A, M|N', 'VII')
static const char WALZE_VIII [27] = "fkqhtlxocbjspdzramewniuygv";  //  'zm', 'Z|A, M|N', 'VIII')

static const char UKW_A [27] = "ejmzalyxvbwfcrquontspikhgd";
static const char UKW_B [27] = "yruhqsldpxngokmiebfzcwvjat";
static const char UKW_C [27] = "fvpjiaoyedrzxwgctkuqsbnmhl";

// (M4):
/* UKW B and C "thin" are not currently used in any configuration
static const char UKW_B_DUENN [27] = "enkqauywjicopblmdxzvfthrgs";  // UKW B "thin"
static const char UKW_C_DUENN [27] = "rdobjntkvehmlfcwzaxgyipsuq";  // UKW C "thin"
*/
static const char WALZE_BETA  [27] = "leyjvcnixwpbqmdrtakzgfuhos";
static const char WALZE_GAMMA [27] = "fsokanuerhmbtiycwlqpzxvgjd";

// -----------------------------------------------------------------------------

void settings_services_comment(void) {
    printf("I \"Services\" (Army, GAF)");
}

void settings_services_apply(void)
{
#ifdef DEBUG
    debug_indent_increment(); // to function outer level
        debug_indent_print();
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
    // set_wheel_wiring_rules(9, ABC_LOWER);
    // set_wheel_wiring_rules(10, ABC_LOWER);

    set_wheel_wiring_rules(UKW_INDEX, UKW_A);

#ifdef DEBUG
    debug_indent_decrement(); // to caller level
#endif
}

// -----------------------------------------------------------------------------

extern void settings_army_comment(void) {
    printf("M3 (Army, Navy)");
}

void settings_army_apply(void)
{
#ifdef DEBUG
    debug_indent_increment(); // to function outer level
        debug_indent_print();
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
    // set_wheel_wiring_rules(9, ABC_LOWER);
    // set_wheel_wiring_rules(10, ABC_LOWER);

    set_wheel_wiring_rules(UKW_INDEX, UKW_B);

#ifdef DEBUG
    debug_indent_decrement(); // to caller level
#endif
}

// -----------------------------------------------------------------------------

void settings_navy_comment(void) {
    printf("M3 (Army, Navy)");
}

void settings_navy_apply(void)
{
#ifdef DEBUG
    debug_indent_increment(); // to function outer level
        debug_indent_print();
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
    debug_indent_decrement(); // to caller level
#endif
}

// =============================================================================

// I-III (D)
// D (commercial)

static const char WALZE_1D [27] = "lpgszmhaeoqkvxrfybutnicjdw";  //  'y', 'Y|Z', '1D')
static const char WALZE_2D [27] = "slvgbtfxjqohewirzyamkpcndu";  //  'e', 'E|F', '2D')
static const char WALZE_3D [27] = "cjgdpshkturawzxfmynqobvlie";  //  'n', 'N|O', '3D')

static const char UKW_D [27] = "imetcgfraysqbzxwlhkdvupojn";

// -----------------------------------------------------------------------------

void settings_commercial_comment(void) {
    printf("D (commercial)");
}

void settings_commercial_apply(void)
{
#ifdef DEBUG
    debug_indent_increment(); // to function outer level
        debug_indent_print();
        printf("Applying settings: commercial\n");
#endif

    set_used_wheel_count(3);

    set_wheel_wiring_rules(1, WALZE_1D);
    set_wheel_wiring_rules(2, WALZE_2D);
    set_wheel_wiring_rules(3, WALZE_3D);
    // set_wheel_wiring_rules(4, ABC_LOWER);
    // set_wheel_wiring_rules(5, ABC_LOWER);
    // set_wheel_wiring_rules(6, ABC_LOWER);
    // set_wheel_wiring_rules(7, ABC_LOWER);
    // set_wheel_wiring_rules(8, ABC_LOWER);
    // set_wheel_wiring_rules(9, ABC_LOWER);
    // set_wheel_wiring_rules(10, ABC_LOWER);

    set_wheel_wiring_rules(UKW_INDEX, UKW_D);

#ifdef DEBUG
    debug_indent_decrement(); // to caller level
#endif
}

// =============================================================================

// I-III (K)
// K "Swiss K" (Swiss)

static const char WALZE_1K [27] = "pezuohxscvfmtbglrinqjwaydk";  //  'y', 'Y|Z', '1K')
static const char WALZE_2K [27] = "zouesydkfwpciqxhmvblgnjrat";  //  'e', 'E|F', '2K')
static const char WALZE_3K [27] = "ehrvxgaobqusimzflynwktpdjc";  //  'n', 'N|O', '3K')

// -----------------------------------------------------------------------------

void settings_swiss_comment(void) {
    printf("K \"Swiss K\" (Swiss)");
}

void settings_swiss_apply(void)
{
#ifdef DEBUG
    debug_indent_increment(); // to function outer level
        debug_indent_print();
        printf("Applying settings: \"Swiss K\" (Swiss)\n");
#endif

    set_used_wheel_count(3);

    set_wheel_wiring_rules(1, WALZE_1K);
    set_wheel_wiring_rules(2, WALZE_2K);
    set_wheel_wiring_rules(3, WALZE_3K);
    // set_wheel_wiring_rules(4, ABC_LOWER);
    // set_wheel_wiring_rules(5, ABC_LOWER);
    // set_wheel_wiring_rules(6, ABC_LOWER);
    // set_wheel_wiring_rules(7, ABC_LOWER);
    // set_wheel_wiring_rules(8, ABC_LOWER);
    // set_wheel_wiring_rules(9, ABC_LOWER);
    // set_wheel_wiring_rules(10, ABC_LOWER);

    set_wheel_wiring_rules(UKW_INDEX, ABC_LOWER);

#ifdef DEBUG
    debug_indent_decrement(); // to caller level
#endif
}

// =============================================================================

// I-V (N)
// N "Norenigma" (Norway)

static const char WALZE_1N [27] = "wtokasuyvrbxjhqcpzefmdinlg";  //  'q', 'Q|R', '1N')
static const char WALZE_2N [27] = "gjlpubswemctqvhxaofzdrkyni";  //  'e', 'E|F', '2N')
static const char WALZE_3N [27] = "jwfmhnbpusdytixvzgrqlaoekc";  //  'v', 'V|W', '3N')
static const char WALZE_4N [27] = "esovpzjayquirhxlnftgkdcmwb";  //  'j', 'J|K', '4N')
static const char WALZE_5N [27] = "hejxqotzbvfdascilwpgynmurk";  //  'z', 'Z|A', '5N')

static const char UKW_N [27] = "mowjypuxndsraibfvlkzgqchet";

// -----------------------------------------------------------------------------

void settings_norway_comment(void) {
    printf("N \"Norenigma\" (Norway)");
}

void settings_norway_apply(void)
{
#ifdef DEBUG
    debug_indent_increment(); // to function outer level
        debug_indent_print();
        printf("Applying settings: \"Norenigma\" (Norway)\n");
#endif

    set_used_wheel_count(5);

    set_wheel_wiring_rules(1, WALZE_1N);
    set_wheel_wiring_rules(2, WALZE_2N);
    set_wheel_wiring_rules(3, WALZE_3N);
    set_wheel_wiring_rules(4, WALZE_4N);
    set_wheel_wiring_rules(5, WALZE_5N);
    // set_wheel_wiring_rules(6, ABC_LOWER);
    // set_wheel_wiring_rules(7, ABC_LOWER);
    // set_wheel_wiring_rules(8, ABC_LOWER);
    // set_wheel_wiring_rules(9, ABC_LOWER);
    // set_wheel_wiring_rules(10, ABC_LOWER);

    set_wheel_wiring_rules(UKW_INDEX, UKW_N);

#ifdef DEBUG
    debug_indent_decrement(); // to caller level
#endif
}

// =============================================================================

// I-III (R)
// R "Rocket" (Railway)

static const char WALZE_1R [27] = "jgdqoxuscamifrvtpnewkblzyh";  //  'n', 'N|O', '1R')
static const char WALZE_2R [27] = "ntzpsfbokmwrcjdivlaeyuxhgq";  //  'e', 'E|F', '2R')
static const char WALZE_3R [27] = "jviubhtcdyakeqzposgxnrmwfl";  //  'y', 'Y|Z', '3R')

static const char UKW_R [27] = "qyhognecvpuztfdjaxwmkisrbl";

// -----------------------------------------------------------------------------

void settings_railway_comment(void) {
    printf("R \"Rocket\" (Railway)");
}

void settings_railway_apply(void)
{
#ifdef DEBUG
    debug_indent_increment(); // to function outer level
        debug_indent_print();
        printf("Applying settings: \"Rocket\" (Railway)\n");
#endif

    set_used_wheel_count(3);

    set_wheel_wiring_rules(1, WALZE_1R);
    set_wheel_wiring_rules(2, WALZE_2R);
    set_wheel_wiring_rules(3, WALZE_3R);
    // set_wheel_wiring_rules(4, ABC_LOWER);
    // set_wheel_wiring_rules(5, ABC_LOWER);
    // set_wheel_wiring_rules(6, ABC_LOWER);
    // set_wheel_wiring_rules(7, ABC_LOWER);
    // set_wheel_wiring_rules(8, ABC_LOWER);
    // set_wheel_wiring_rules(9, ABC_LOWER);
    // set_wheel_wiring_rules(10, ABC_LOWER);

    set_wheel_wiring_rules(UKW_INDEX, UKW_R);

#ifdef DEBUG
    debug_indent_decrement(); // to caller level
#endif
}

// =============================================================================

// I-VIII (T)
// T "Tirpitz" (Japan)

static const char WALZE_1T [27] = "kptyuelocvgrfqdanjmbswhzxi";  //  'wzekq', '5 notches', '1T')
static const char WALZE_2T [27] = "uphzlweqmtdjxcaksoigvbyfnr";  //  'wzflr', '5 notches', '2T')
static const char WALZE_3T [27] = "qudlyrfekonvzaxwhmgpjbsict";  //  'wzekq', '5 notches', '3T')
static const char WALZE_4T [27] = "ciwtbkxnrespflydagvhquojzm";  //  'wzflr', '5 notches', '4T')
static const char WALZE_5T [27] = "uaxgisnjbverdylfzwtpckohmq";  //  'ycfkr', '5 notches', '5T')
static const char WALZE_6T [27] = "xfuzgalvhcnysewqtdmrbkpioj";  //  'xeimq', '5 notches', '6T')
static const char WALZE_7T [27] = "bjvftxplnayozikwgdqeruchsm";  //  'ycfkr', '5 notches', '7T')
static const char WALZE_8T [27] = "ymtpnzhwkodajxeluqvgcbisfr";  //  'xeimq', '5 notches', '8T')

static const char UKW_T [27] = "gekpbtaumocniljdxzyfhwvqsr";

// -----------------------------------------------------------------------------

void settings_tirpitz_comment(void) {
    printf("T \"Tirpitz\" (Japan)");
}

void settings_tirpitz_apply(void)
{
#ifdef DEBUG
    debug_indent_increment(); // to function outer level
        debug_indent_print();
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
    // set_wheel_wiring_rules(9, ABC_LOWER);
    // set_wheel_wiring_rules(10, ABC_LOWER);

    set_wheel_wiring_rules(UKW_INDEX, UKW_T);

#ifdef DEBUG
    debug_indent_decrement(); // to caller level
#endif
}

// =============================================================================

// I-III (A) [A-865]
// A-865 "Zählwerk" (1928)

static const char WALZE_1A8 [27] = "lpgszmhaeoqkvxrfybutnicjdw";  //  'suvwzabcefgiklopq', '17 notches (A-865)', '1A8')
static const char WALZE_2A8 [27] = "slvgbtfxjqohewirzyamkpcndu";  //  'stvyzacdfghkmnq', '15 notches (A-865)', '2A8')
static const char WALZE_3A8 [27] = "cjgdpshkturawzxfmynqobvlie";  //  'uwxaefhkmnr', '11 notches (A-865)', '3A8')

// (G)

static const char UKW_G [27] = "rulqmzjsygocetkwdahnbxpvif";

// -----------------------------------------------------------------------------

void settings_zaehlwerk_comment(void) {
    printf("A-865 \"Zählwerk\" (1928)");
}

void settings_zaehlwerk_apply(void)
{
#ifdef DEBUG
    debug_indent_increment(); // to function outer level
        debug_indent_print();
        printf("Applying settings: \"Zählwerk\" (1928)\n");
#endif

    set_used_wheel_count(3);

    set_wheel_wiring_rules(1, WALZE_1A8);
    set_wheel_wiring_rules(2, WALZE_2A8);
    set_wheel_wiring_rules(3, WALZE_3A8);
    // set_wheel_wiring_rules(4, ABC_LOWER);
    // set_wheel_wiring_rules(5, ABC_LOWER);
    // set_wheel_wiring_rules(6, ABC_LOWER);
    // set_wheel_wiring_rules(7, ABC_LOWER);
    // set_wheel_wiring_rules(8, ABC_LOWER);
    // set_wheel_wiring_rules(9, ABC_LOWER);
    // set_wheel_wiring_rules(10, ABC_LOWER);

    set_wheel_wiring_rules(UKW_INDEX, ABC_LOWER);

#ifdef DEBUG
    debug_indent_decrement(); // to caller level
#endif
}

// =============================================================================

// I-III (G1) [G-111]
// G-111 (Hungary / Munich)

static const char WALZE_1G1 [27] = "wlrhbqundkjczsexotmagyfpvi";  //  'suvwzabcefgiklopq', '17 notches (G-111)', '1G1')
static const char WALZE_2G1 [27] = "tfjqazwmhlcuixrdygoevbnskp";  //  'stvyzacdfghkmnq', '15 notches (G-111)', '2G1')
static const char WALZE_5G1 [27] = "qtpixwvdfrmusljohcanezkybg";  //  'swzfhmq', '7 notches (G-111)', '5G1')

// -----------------------------------------------------------------------------

void settings_hungary_comment(void) {
    printf("G-111 (Hungary / Munich)");
}

void settings_hungary_apply(void)
{
#ifdef DEBUG
    debug_indent_increment(); // to function outer level
        debug_indent_print();
        printf("Applying settings: Hungary / Munich\n");
#endif

    set_used_wheel_count(3);

    set_wheel_wiring_rules(1, WALZE_1G1);
    set_wheel_wiring_rules(2, WALZE_2G1);
    set_wheel_wiring_rules(3, WALZE_5G1);
    // set_wheel_wiring_rules(4, ABC_LOWER);
    // set_wheel_wiring_rules(5, ABC_LOWER);
    // set_wheel_wiring_rules(6, ABC_LOWER);
    // set_wheel_wiring_rules(7, ABC_LOWER);
    // set_wheel_wiring_rules(8, ABC_LOWER);
    // set_wheel_wiring_rules(9, ABC_LOWER);
    // set_wheel_wiring_rules(10, ABC_LOWER);

    set_wheel_wiring_rules(UKW_INDEX, UKW_G);

#ifdef DEBUG
    debug_indent_decrement(); // to caller level
#endif
}

// =============================================================================

// I-III (G2) [G-260]
// G-260 (Abwehr in Argentina)

static const char WALZE_1G2 [27] = "rcspblkqaumhwytifzvgojnexd";  //  'suvwzabcefgiklopq', '17 notches (G-260)', '1G2')
static const char WALZE_2G2 [27] = "wcmibvpjxarosgndlzkeyhufqt";  //  'stvyzacdfghkmnq', '15 notches (G-260)', '2G2')
static const char WALZE_3G2 [27] = "fvdhzelsqmaxokyiwpgcbujtnr";  //  'uwxaefhkmnr', '11 notches (G-260)', '3G2')

// -----------------------------------------------------------------------------

void settings_argentina_comment(void) {
    printf("G-260 (Abwehr in Argentina)");
}

void settings_argentina_apply(void)
{
#ifdef DEBUG
    debug_indent_increment(); // to function outer level
        debug_indent_print();
        printf("Applying settings: Abwehr in Argentina\n");
#endif

    set_used_wheel_count(3);

    set_wheel_wiring_rules(1, WALZE_1G2);
    set_wheel_wiring_rules(2, WALZE_2G2);
    set_wheel_wiring_rules(3, WALZE_3G2);
    // set_wheel_wiring_rules(4, ABC_LOWER);
    // set_wheel_wiring_rules(5, ABC_LOWER);
    // set_wheel_wiring_rules(6, ABC_LOWER);
    // set_wheel_wiring_rules(7, ABC_LOWER);
    // set_wheel_wiring_rules(8, ABC_LOWER);
    // set_wheel_wiring_rules(9, ABC_LOWER);
    // set_wheel_wiring_rules(10, ABC_LOWER);

    set_wheel_wiring_rules(UKW_INDEX, UKW_G);

#ifdef DEBUG
    debug_indent_decrement(); // to caller level
#endif
}

// =============================================================================

// I-III (G3) [G-312]
// G-312 (Abwehr / Bletchley Park)

static const char WALZE_1G3 [27] = "dmtwsilruyqnkfejcazbpgxohv";  //  'suvwzabcefgiklopq', '17 notches (G-312)', '1G3')
static const char WALZE_2G3 [27] = "hqzgpjtmoblncifdyawveusrkx";  //  'stvyzacdfghkmnq', '15 notches (G-312)', '2G3')
static const char WALZE_3G3 [27] = "uqntlszfmrehdpxkibvygjcwoa";  //  'uwxaefhkmnr', '11 notches (G-312)', '3G3')

// -----------------------------------------------------------------------------

void settings_bletchley_comment(void) {
    printf("G-312 (Abwehr / Bletchley Park)");
}

void settings_bletchley_apply(void)
{
#ifdef DEBUG
    debug_indent_increment(); // to function outer level
        debug_indent_print();
        printf("Applying settings: Abwehr / Bletchley Park\n");
#endif

    set_used_wheel_count(3);

    set_wheel_wiring_rules(1, WALZE_1G3);
    set_wheel_wiring_rules(2, WALZE_2G3);
    set_wheel_wiring_rules(3, WALZE_3G3);
    // set_wheel_wiring_rules(4, ABC_LOWER);
    // set_wheel_wiring_rules(5, ABC_LOWER);
    // set_wheel_wiring_rules(6, ABC_LOWER);
    // set_wheel_wiring_rules(7, ABC_LOWER);
    // set_wheel_wiring_rules(8, ABC_LOWER);
    // set_wheel_wiring_rules(9, ABC_LOWER);
    // set_wheel_wiring_rules(10, ABC_LOWER);

    set_wheel_wiring_rules(UKW_INDEX, UKW_G);

#ifdef DEBUG
    debug_indent_decrement(); // to caller level
#endif
}

// =============================================================================

void settings_default_comment(void) {
    printf("'%s'", BLETCHLEY);
}

void settings_default_apply(void)
{
#ifdef DEBUG
    debug_indent_increment(); // to function outer level
        debug_indent_print();
        printf("Applying settings: (default)\n");
#endif

    settings_bletchley_apply();

#ifdef DEBUG
    debug_indent_decrement(); // to caller level
#endif
}
