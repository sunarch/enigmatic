/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "util-abc.h"
#include "util-abc-common.h"
#include "wheels-common.h"
#include "wheels-settings.h"


#ifdef DEBUG
#include "util-debug.h"
#endif


// PRIVATE VARIABLES ///////////////////////////////////////////////////////////

static unsigned short used_wheel_count;

static signed short wheel_wiring_rules_front   [WHEELS_COUNT_MAX_TOTAL][ABC_LENGTH];
static signed short wheel_wiring_rules_reverse [WHEELS_COUNT_MAX_TOTAL][ABC_LENGTH];


// GETTERS /////////////////////////////////////////////////////////////////////

unsigned short settings_get_used_wheel_count(void)
{
        return used_wheel_count;
}


signed short settings_get_wheel_wiring_rule(unsigned short mode,
                                            unsigned short wheel_number,
                                            unsigned short position)
{
        settings_validate_wheel_number(wheel_number);

        switch (mode) {
                case WHEEL_MODE_UKW:
                        // use the WHEEL_MODE_FRONT method for WHEEL_MODE_UKW
                        // front and reverse should be same for UKW
                        // no break.
                case WHEEL_MODE_FRONT:
                        return wheel_wiring_rules_front[wheel_number][position];
                case WHEEL_MODE_REVERSE:
                        return wheel_wiring_rules_reverse[wheel_number][position];
                default:
                        exit(RETURN_CODE_ERROR);
        }
}


// VALIDATORS //////////////////////////////////////////////////////////////////

void settings_validate_wheel_number(unsigned short wheel_number)
{
        unsigned short wheel_count = settings_get_used_wheel_count();

        if (wheel_number > wheel_count) {
                printf("Failed check with (wheel_number > wheel_count): (%u > %u)\n", wheel_number, wheel_count);
                printf("Exiting...\n");
                exit(RETURN_CODE_ERROR);
        }
}


// DEBUG /////////////////////////////////////////////////////////////////////

#ifdef DEBUG
static void settings_print_prefix_apply(void)
{
    printf("Applying settings: ");
}
#endif


// SETTERS - INTERNAL //////////////////////////////////////////////////////////

static void settings_set_used_wheel_count(unsigned short new_wheel_count)
{
#ifdef DEBUG
        debug_print_prefix();
        printf("set_used_wheel_count '%u' -> '%u'", settings_get_used_wheel_count(), new_wheel_count);
#endif

        if (new_wheel_count > WHEELS_COUNT_MAX_REGULAR) {
                printf("Failed check with (new_wheel_count (%u) > %u)", new_wheel_count, WHEELS_COUNT_MAX_REGULAR);
                printf("Exiting...");
                exit(RETURN_CODE_ERROR);
        }

        used_wheel_count = new_wheel_count;

#ifdef DEBUG
        printf(" | check: '%u'\n", settings_get_used_wheel_count());
#endif
}


static void settings_set_wheel_by_alphabet(unsigned short wheel_number,
                                           const char *wiring_alphabet)
{
        signed short wiring_rule;

        for (unsigned short n = 0; n < ABC_LENGTH; ++n) {
                wiring_rule = (signed short) ((wiring_alphabet[n] - abc_char_lower_from_index(n)) % ABC_LENGTH);
                wheel_wiring_rules_front[wheel_number][n] = wiring_rule;
                wheel_wiring_rules_reverse[wheel_number][(n + wiring_rule) % ABC_LENGTH] = (-1) * wiring_rule;
        }
}


static void settings_set_wheel_blank(unsigned short wheel_number)
{
        for (signed short n = 0; n < ABC_LENGTH; ++n) {
                wheel_wiring_rules_front[wheel_number][n] = n;
                wheel_wiring_rules_reverse[wheel_number][n] = n;
        }
}


// SETTERS /////////////////////////////////////////////////////////////////////

// Rotor wheels (wiring, turnover points, c-o info, name)
// Reflectors (UKW)

// =============================================================================

// W. I-VIII (I,M3,M4)
// I "Services" (Army, GAF)
// M3 (Army, Navy)
// M4 "Shark" (U-Boats)

static const char WALZE_I    [ABC_LENGTH_STRING] = "ekmflgdqvzntowyhxuspaibrcj";  //  'q', 'Q|R', 'I')
static const char WALZE_II   [ABC_LENGTH_STRING] = "ajdksiruxblhwtmcqgznpyfvoe";  //  'e', 'E|F', 'II')
static const char WALZE_III  [ABC_LENGTH_STRING] = "bdfhjlcprtxvznyeiwgakmusqo";  //  'v', 'V|W', 'III')
static const char WALZE_IV   [ABC_LENGTH_STRING] = "esovpzjayquirhxlnftgkdcmwb";  //  'j', 'J|K', 'IV')
static const char WALZE_V    [ABC_LENGTH_STRING] = "vzbrgityupsdnhlxawmjqofeck";  //  'z', 'Z|A', 'V')
static const char WALZE_VI   [ABC_LENGTH_STRING] = "jpgvoumfyqbenhzrdkasxlictw";  //  'zm', 'Z|A, M|N', 'VI')
static const char WALZE_VII  [ABC_LENGTH_STRING] = "nzjhgrcxmyswboufaivlpekqdt";  //  'zm', 'Z|A, M|N', 'VII')
static const char WALZE_VIII [ABC_LENGTH_STRING] = "fkqhtlxocbjspdzramewniuygv";  //  'zm', 'Z|A, M|N', 'VIII')

static const char UKW_A [ABC_LENGTH_STRING] = "ejmzalyxvbwfcrquontspikhgd";
static const char UKW_B [ABC_LENGTH_STRING] = "yruhqsldpxngokmiebfzcwvjat";
static const char UKW_C [ABC_LENGTH_STRING] = "fvpjiaoyedrzxwgctkuqsbnmhl";

// (M4):
/* UKW B and C "thin" are not currently used in any configuration
static const char UKW_B_DUENN [ABC_LENGTH_STRING] = "enkqauywjicopblmdxzvfthrgs";  // UKW B "thin"
static const char UKW_C_DUENN [ABC_LENGTH_STRING] = "rdobjntkvehmlfcwzaxgyipsuq";  // UKW C "thin"
*/
static const char WALZE_BETA  [ABC_LENGTH_STRING] = "leyjvcnixwpbqmdrtakzgfuhos";
static const char WALZE_GAMMA [ABC_LENGTH_STRING] = "fsokanuerhmbtiycwlqpzxvgjd";

// -----------------------------------------------------------------------------

const char SETTINGS_SERVICES [SETTINGS_NAME_MAX_LENGTH_STR] = "services";


void settings_services_comment(void)
{
        printf("I \"Services\" (Army, GAF)");
}


void settings_services_apply(void)
{
#ifdef DEBUG
        debug_print_prefix();
        settings_print_prefix_apply();
        settings_services_comment();
        printf("\n");
#endif

        settings_set_used_wheel_count(5);

        settings_set_wheel_by_alphabet(1, WALZE_I);
        settings_set_wheel_by_alphabet(2, WALZE_II);
        settings_set_wheel_by_alphabet(3, WALZE_III);
        settings_set_wheel_by_alphabet(4, WALZE_IV);
        settings_set_wheel_by_alphabet(5, WALZE_V);
        settings_set_wheel_by_alphabet(6, WALZE_VI); // above 5 unused
        settings_set_wheel_by_alphabet(7, WALZE_VII); // above 5 unused
        settings_set_wheel_by_alphabet(8, WALZE_VIII); // above 5 unused
        settings_set_wheel_blank(9); // unused
        settings_set_wheel_blank(10); // unused

        settings_set_wheel_by_alphabet(UKW_INDEX, UKW_A);
}

// -----------------------------------------------------------------------------

const char SETTINGS_ARMY [SETTINGS_NAME_MAX_LENGTH_STR] = "army";


extern void settings_army_comment(void)
{
        printf("M3 (Army, Navy) -> Army");
}


void settings_army_apply(void)
{
#ifdef DEBUG
        debug_print_prefix();
        settings_print_prefix_apply();
        settings_army_comment();
        printf("\n");
#endif

        settings_set_used_wheel_count(8);

        settings_set_wheel_by_alphabet(1, WALZE_I);
        settings_set_wheel_by_alphabet(2, WALZE_II);
        settings_set_wheel_by_alphabet(3, WALZE_III);
        settings_set_wheel_by_alphabet(4, WALZE_IV);
        settings_set_wheel_by_alphabet(5, WALZE_V);
        settings_set_wheel_by_alphabet(6, WALZE_VI);
        settings_set_wheel_by_alphabet(7, WALZE_VII);
        settings_set_wheel_by_alphabet(8, WALZE_VIII);
        settings_set_wheel_blank(9); // unused
        settings_set_wheel_blank(10); // unused

        settings_set_wheel_by_alphabet(UKW_INDEX, UKW_B);
}

// -----------------------------------------------------------------------------

const char SETTINGS_NAVY [SETTINGS_NAME_MAX_LENGTH_STR] = "navy";


void settings_navy_comment(void)
{
        printf("M3 (Army, Navy) -> Navy");
}


void settings_navy_apply(void)
{
#ifdef DEBUG
        debug_print_prefix();
        settings_print_prefix_apply();
        settings_navy_comment();
        printf("\n");
#endif

        settings_set_used_wheel_count(10);

        settings_set_wheel_by_alphabet(1, WALZE_BETA);
        settings_set_wheel_by_alphabet(2, WALZE_GAMMA);
        settings_set_wheel_by_alphabet(3, WALZE_I);
        settings_set_wheel_by_alphabet(4, WALZE_II);
        settings_set_wheel_by_alphabet(5, WALZE_III);
        settings_set_wheel_by_alphabet(6, WALZE_IV);
        settings_set_wheel_by_alphabet(7, WALZE_V);
        settings_set_wheel_by_alphabet(8, WALZE_VI);
        settings_set_wheel_by_alphabet(9, WALZE_VII);
        settings_set_wheel_by_alphabet(10, WALZE_VIII);

        settings_set_wheel_by_alphabet(UKW_INDEX, UKW_C);
}

// =============================================================================

// I-III (D)
// D (commercial)

static const char WALZE_1D [ABC_LENGTH_STRING] = "lpgszmhaeoqkvxrfybutnicjdw";  //  'y', 'Y|Z', '1D')
static const char WALZE_2D [ABC_LENGTH_STRING] = "slvgbtfxjqohewirzyamkpcndu";  //  'e', 'E|F', '2D')
static const char WALZE_3D [ABC_LENGTH_STRING] = "cjgdpshkturawzxfmynqobvlie";  //  'n', 'N|O', '3D')

static const char UKW_D [ABC_LENGTH_STRING] = "imetcgfraysqbzxwlhkdvupojn";

// -----------------------------------------------------------------------------

const char SETTINGS_COMMERCIAL [SETTINGS_NAME_MAX_LENGTH_STR] = "commercial";


void settings_commercial_comment(void)
{
        printf("D (commercial)");
}


void settings_commercial_apply(void)
{
#ifdef DEBUG
        debug_print_prefix();
        settings_print_prefix_apply();
        settings_commercial_comment();
        printf("\n");
#endif

        settings_set_used_wheel_count(3);

        settings_set_wheel_by_alphabet(1, WALZE_1D);
        settings_set_wheel_by_alphabet(2, WALZE_2D);
        settings_set_wheel_by_alphabet(3, WALZE_3D);
        settings_set_wheel_blank(4); // unused
        settings_set_wheel_blank(5); // unused
        settings_set_wheel_blank(6); // unused
        settings_set_wheel_blank(7); // unused
        settings_set_wheel_blank(8); // unused
        settings_set_wheel_blank(9); // unused
        settings_set_wheel_blank(10); // unused

        settings_set_wheel_by_alphabet(UKW_INDEX, UKW_D);
}

// =============================================================================

// I-III (K)
// K "Swiss K" (Swiss)

static const char WALZE_1K [ABC_LENGTH_STRING] = "pezuohxscvfmtbglrinqjwaydk";  //  'y', 'Y|Z', '1K')
static const char WALZE_2K [ABC_LENGTH_STRING] = "zouesydkfwpciqxhmvblgnjrat";  //  'e', 'E|F', '2K')
static const char WALZE_3K [ABC_LENGTH_STRING] = "ehrvxgaobqusimzflynwktpdjc";  //  'n', 'N|O', '3K')

// -----------------------------------------------------------------------------

const char SETTINGS_SWISS [SETTINGS_NAME_MAX_LENGTH_STR] = "swiss";


void settings_swiss_comment(void)
{
        printf("K \"Swiss K\" (Swiss)");
}


void settings_swiss_apply(void)
{
#ifdef DEBUG
        debug_print_prefix();
        settings_print_prefix_apply();
        settings_swiss_comment();
        printf("\n");
#endif

        settings_set_used_wheel_count(3);

        settings_set_wheel_by_alphabet(1, WALZE_1K);
        settings_set_wheel_by_alphabet(2, WALZE_2K);
        settings_set_wheel_by_alphabet(3, WALZE_3K);
        settings_set_wheel_blank(4); // unused
        settings_set_wheel_blank(5); // unused
        settings_set_wheel_blank(6); // unused
        settings_set_wheel_blank(7); // unused
        settings_set_wheel_blank(8); // unused
        settings_set_wheel_blank(9); // unused
        settings_set_wheel_blank(10); // unused

        settings_set_wheel_blank(UKW_INDEX);
}

// =============================================================================

// I-V (N)
// N "Norenigma" (Norway)

static const char WALZE_1N [ABC_LENGTH_STRING] = "wtokasuyvrbxjhqcpzefmdinlg";  //  'q', 'Q|R', '1N')
static const char WALZE_2N [ABC_LENGTH_STRING] = "gjlpubswemctqvhxaofzdrkyni";  //  'e', 'E|F', '2N')
static const char WALZE_3N [ABC_LENGTH_STRING] = "jwfmhnbpusdytixvzgrqlaoekc";  //  'v', 'V|W', '3N')
static const char WALZE_4N [ABC_LENGTH_STRING] = "esovpzjayquirhxlnftgkdcmwb";  //  'j', 'J|K', '4N')
static const char WALZE_5N [ABC_LENGTH_STRING] = "hejxqotzbvfdascilwpgynmurk";  //  'z', 'Z|A', '5N')

static const char UKW_N [ABC_LENGTH_STRING] = "mowjypuxndsraibfvlkzgqchet";

// -----------------------------------------------------------------------------

const char SETTINGS_NORWAY [SETTINGS_NAME_MAX_LENGTH_STR] = "norway";


void settings_norway_comment(void)
{
        printf("N \"Norenigma\" (Norway)");
}


void settings_norway_apply(void)
{
#ifdef DEBUG
        debug_print_prefix();
        settings_print_prefix_apply();
        settings_norway_comment();
        printf("\n");
#endif

        settings_set_used_wheel_count(5);

        settings_set_wheel_by_alphabet(1, WALZE_1N);
        settings_set_wheel_by_alphabet(2, WALZE_2N);
        settings_set_wheel_by_alphabet(3, WALZE_3N);
        settings_set_wheel_by_alphabet(4, WALZE_4N);
        settings_set_wheel_by_alphabet(5, WALZE_5N);
        settings_set_wheel_blank(6); // unused
        settings_set_wheel_blank(7); // unused
        settings_set_wheel_blank(8); // unused
        settings_set_wheel_blank(9); // unused
        settings_set_wheel_blank(10); // unused

        settings_set_wheel_by_alphabet(UKW_INDEX, UKW_N);
}

// =============================================================================

// I-III (R)
// R "Rocket" (Railway)

static const char WALZE_1R [ABC_LENGTH_STRING] = "jgdqoxuscamifrvtpnewkblzyh";  //  'n', 'N|O', '1R')
static const char WALZE_2R [ABC_LENGTH_STRING] = "ntzpsfbokmwrcjdivlaeyuxhgq";  //  'e', 'E|F', '2R')
static const char WALZE_3R [ABC_LENGTH_STRING] = "jviubhtcdyakeqzposgxnrmwfl";  //  'y', 'Y|Z', '3R')

static const char UKW_R [ABC_LENGTH_STRING] = "qyhognecvpuztfdjaxwmkisrbl";

// -----------------------------------------------------------------------------

const char SETTINGS_RAILWAY [SETTINGS_NAME_MAX_LENGTH_STR] = "railway";


void settings_railway_comment(void)
{
        printf("R \"Rocket\" (Railway)");
}


void settings_railway_apply(void)
{
#ifdef DEBUG
        debug_print_prefix();
        settings_print_prefix_apply();
        settings_railway_comment();
        printf("\n");
#endif

        settings_set_used_wheel_count(3);

        settings_set_wheel_by_alphabet(1, WALZE_1R);
        settings_set_wheel_by_alphabet(2, WALZE_2R);
        settings_set_wheel_by_alphabet(3, WALZE_3R);
        settings_set_wheel_blank(4); // unused
        settings_set_wheel_blank(5); // unused
        settings_set_wheel_blank(6); // unused
        settings_set_wheel_blank(7); // unused
        settings_set_wheel_blank(8); // unused
        settings_set_wheel_blank(9); // unused
        settings_set_wheel_blank(10); // unused

        settings_set_wheel_by_alphabet(UKW_INDEX, UKW_R);
}

// =============================================================================

// I-VIII (T)
// T "Tirpitz" (Japan)

static const char WALZE_1T [ABC_LENGTH_STRING] = "kptyuelocvgrfqdanjmbswhzxi";  //  'wzekq', '5 notches', '1T')
static const char WALZE_2T [ABC_LENGTH_STRING] = "uphzlweqmtdjxcaksoigvbyfnr";  //  'wzflr', '5 notches', '2T')
static const char WALZE_3T [ABC_LENGTH_STRING] = "qudlyrfekonvzaxwhmgpjbsict";  //  'wzekq', '5 notches', '3T')
static const char WALZE_4T [ABC_LENGTH_STRING] = "ciwtbkxnrespflydagvhquojzm";  //  'wzflr', '5 notches', '4T')
static const char WALZE_5T [ABC_LENGTH_STRING] = "uaxgisnjbverdylfzwtpckohmq";  //  'ycfkr', '5 notches', '5T')
static const char WALZE_6T [ABC_LENGTH_STRING] = "xfuzgalvhcnysewqtdmrbkpioj";  //  'xeimq', '5 notches', '6T')
static const char WALZE_7T [ABC_LENGTH_STRING] = "bjvftxplnayozikwgdqeruchsm";  //  'ycfkr', '5 notches', '7T')
static const char WALZE_8T [ABC_LENGTH_STRING] = "ymtpnzhwkodajxeluqvgcbisfr";  //  'xeimq', '5 notches', '8T')

static const char UKW_T [ABC_LENGTH_STRING] = "gekpbtaumocniljdxzyfhwvqsr";

// -----------------------------------------------------------------------------

const char SETTINGS_TIRPITZ [SETTINGS_NAME_MAX_LENGTH_STR] = "tirpitz";


void settings_tirpitz_comment(void)
{
        printf("T \"Tirpitz\" (Japan)");
}


void settings_tirpitz_apply(void)
{
#ifdef DEBUG
        debug_print_prefix();
        settings_print_prefix_apply();
        settings_tirpitz_comment();
        printf("\n");
#endif

        settings_set_used_wheel_count(8);

        settings_set_wheel_by_alphabet(1, WALZE_1T);
        settings_set_wheel_by_alphabet(2, WALZE_2T);
        settings_set_wheel_by_alphabet(3, WALZE_3T);
        settings_set_wheel_by_alphabet(4, WALZE_4T);
        settings_set_wheel_by_alphabet(5, WALZE_5T);
        settings_set_wheel_by_alphabet(6, WALZE_6T);
        settings_set_wheel_by_alphabet(7, WALZE_7T);
        settings_set_wheel_by_alphabet(8, WALZE_8T);
        settings_set_wheel_blank(9); // unused
        settings_set_wheel_blank(10); // unused

        settings_set_wheel_by_alphabet(UKW_INDEX, UKW_T);
}

// =============================================================================

// I-III (A) [A-865]
// A-865 "Zählwerk" (1928)

static const char WALZE_1A8 [ABC_LENGTH_STRING] = "lpgszmhaeoqkvxrfybutnicjdw";  //  'suvwzabcefgiklopq', '17 notches (A-865)', '1A8')
static const char WALZE_2A8 [ABC_LENGTH_STRING] = "slvgbtfxjqohewirzyamkpcndu";  //  'stvyzacdfghkmnq', '15 notches (A-865)', '2A8')
static const char WALZE_3A8 [ABC_LENGTH_STRING] = "cjgdpshkturawzxfmynqobvlie";  //  'uwxaefhkmnr', '11 notches (A-865)', '3A8')

// (G)

static const char UKW_G [ABC_LENGTH_STRING] = "rulqmzjsygocetkwdahnbxpvif";

// -----------------------------------------------------------------------------

const char SETTINGS_ZAEHLWERK [SETTINGS_NAME_MAX_LENGTH_STR] = "zaehlwerk";


void settings_zaehlwerk_comment(void)
{
        printf("A-865 \"Zählwerk\" (1928)");
}


void settings_zaehlwerk_apply(void)
{
#ifdef DEBUG
        debug_print_prefix();
        settings_print_prefix_apply();
        settings_zaehlwerk_comment();
        printf("\n");
#endif

        settings_set_used_wheel_count(3);

        settings_set_wheel_by_alphabet(1, WALZE_1A8);
        settings_set_wheel_by_alphabet(2, WALZE_2A8);
        settings_set_wheel_by_alphabet(3, WALZE_3A8);
        settings_set_wheel_blank(4); // unused
        settings_set_wheel_blank(5); // unused
        settings_set_wheel_blank(6); // unused
        settings_set_wheel_blank(7); // unused
        settings_set_wheel_blank(8); // unused
        settings_set_wheel_blank(9); // unused
        settings_set_wheel_blank(10); // unused

        settings_set_wheel_blank(UKW_INDEX);
}

// =============================================================================

// I-III (G1) [G-111]
// G-111 (Hungary / Munich)

static const char WALZE_1G1 [ABC_LENGTH_STRING] = "wlrhbqundkjczsexotmagyfpvi";  //  'suvwzabcefgiklopq', '17 notches (G-111)', '1G1')
static const char WALZE_2G1 [ABC_LENGTH_STRING] = "tfjqazwmhlcuixrdygoevbnskp";  //  'stvyzacdfghkmnq', '15 notches (G-111)', '2G1')
static const char WALZE_5G1 [ABC_LENGTH_STRING] = "qtpixwvdfrmusljohcanezkybg";  //  'swzfhmq', '7 notches (G-111)', '5G1')

// -----------------------------------------------------------------------------

const char SETTINGS_HUNGARY [SETTINGS_NAME_MAX_LENGTH_STR] = "hungary";


void settings_hungary_comment(void)
{
        printf("G-111 (Hungary / Munich)");
}


void settings_hungary_apply(void)
{
#ifdef DEBUG
        debug_print_prefix();
        settings_print_prefix_apply();
        settings_hungary_comment();
        printf("\n");
#endif

        settings_set_used_wheel_count(3);

        settings_set_wheel_by_alphabet(1, WALZE_1G1);
        settings_set_wheel_by_alphabet(2, WALZE_2G1);
        settings_set_wheel_by_alphabet(3, WALZE_5G1);
        settings_set_wheel_blank(4); // unused
        settings_set_wheel_blank(5); // unused
        settings_set_wheel_blank(6); // unused
        settings_set_wheel_blank(7); // unused
        settings_set_wheel_blank(8); // unused
        settings_set_wheel_blank(9); // unused
        settings_set_wheel_blank(10); // unused

        settings_set_wheel_by_alphabet(UKW_INDEX, UKW_G);
}

// =============================================================================

// I-III (G2) [G-260]
// G-260 (Abwehr in Argentina)

static const char WALZE_1G2 [ABC_LENGTH_STRING] = "rcspblkqaumhwytifzvgojnexd";  //  'suvwzabcefgiklopq', '17 notches (G-260)', '1G2')
static const char WALZE_2G2 [ABC_LENGTH_STRING] = "wcmibvpjxarosgndlzkeyhufqt";  //  'stvyzacdfghkmnq', '15 notches (G-260)', '2G2')
static const char WALZE_3G2 [ABC_LENGTH_STRING] = "fvdhzelsqmaxokyiwpgcbujtnr";  //  'uwxaefhkmnr', '11 notches (G-260)', '3G2')

// -----------------------------------------------------------------------------

const char SETTINGS_ARGENTINA [SETTINGS_NAME_MAX_LENGTH_STR] = "argentina";


void settings_argentina_comment(void)
{
        printf("G-260 (Abwehr in Argentina)");
}


void settings_argentina_apply(void)
{
#ifdef DEBUG
        debug_print_prefix();
        settings_print_prefix_apply();
        settings_argentina_comment();
        printf("\n");
#endif

        settings_set_used_wheel_count(3);

        settings_set_wheel_by_alphabet(1, WALZE_1G2);
        settings_set_wheel_by_alphabet(2, WALZE_2G2);
        settings_set_wheel_by_alphabet(3, WALZE_3G2);
        settings_set_wheel_blank(4); // unused
        settings_set_wheel_blank(5); // unused
        settings_set_wheel_blank(6); // unused
        settings_set_wheel_blank(7); // unused
        settings_set_wheel_blank(8); // unused
        settings_set_wheel_blank(9); // unused
        settings_set_wheel_blank(10); // unused

        settings_set_wheel_by_alphabet(UKW_INDEX, UKW_G);
}

// =============================================================================

// I-III (G3) [G-312]
// G-312 (Abwehr / Bletchley Park)

static const char WALZE_1G3 [ABC_LENGTH_STRING] = "dmtwsilruyqnkfejcazbpgxohv";  //  'suvwzabcefgiklopq', '17 notches (G-312)', '1G3')
static const char WALZE_2G3 [ABC_LENGTH_STRING] = "hqzgpjtmoblncifdyawveusrkx";  //  'stvyzacdfghkmnq', '15 notches (G-312)', '2G3')
static const char WALZE_3G3 [ABC_LENGTH_STRING] = "uqntlszfmrehdpxkibvygjcwoa";  //  'uwxaefhkmnr', '11 notches (G-312)', '3G3')

// -----------------------------------------------------------------------------

const char SETTINGS_BLETCHLEY [SETTINGS_NAME_MAX_LENGTH_STR] = "bletchley";


void settings_bletchley_comment(void)
{
        printf("G-312 (Abwehr / Bletchley Park)");
}


void settings_bletchley_apply(void)
{
#ifdef DEBUG
        debug_print_prefix();
        settings_print_prefix_apply();
        settings_bletchley_comment();
        printf("\n");
#endif

        settings_set_used_wheel_count(3);

        settings_set_wheel_by_alphabet(1, WALZE_1G3);
        settings_set_wheel_by_alphabet(2, WALZE_2G3);
        settings_set_wheel_by_alphabet(3, WALZE_3G3);
        settings_set_wheel_blank(4); // unused
        settings_set_wheel_blank(5); // unused
        settings_set_wheel_blank(6); // unused
        settings_set_wheel_blank(7); // unused
        settings_set_wheel_blank(8); // unused
        settings_set_wheel_blank(9); // unused
        settings_set_wheel_blank(10); // unused

        settings_set_wheel_by_alphabet(UKW_INDEX, UKW_G);
}

// =============================================================================

const char SETTINGS_DEFAULT [SETTINGS_NAME_MAX_LENGTH_STR] = "default";


void settings_default_comment(void)
{
        printf("'%s'", SETTINGS_BLETCHLEY);
}


void settings_default_apply(void)
{
#ifdef DEBUG
        debug_print_prefix();
        settings_print_prefix_apply();
        printf("(%s) ", SETTINGS_DEFAULT);
        settings_default_comment();
        printf("\n");
#endif

        settings_bletchley_apply();
}
