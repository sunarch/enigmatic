
#include "wheels.h"

char ABC_UPP [27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  // ordered Alphabet
char ABC_LOW [27] = "abcdefghijklmnopqrstuvwxyz";  // ordered Alphabet

// Rotor wheels (wiring, turnover points, c-o info, name)
// Reflectors (UKW)

// W. I-VIII (I,M3,M4)
// I "Services" (Army, GAF)
// M3 (Army, Navy)
// M4 "Shark" (U-Boats)

char WALZE_I    [27] = "ekmflgdqvzntowyhxuspaibrcj";  //  'q', 'Q|R', 'I')
char WALZE_II   [27] = "ajdksiruxblhwtmcqgznpyfvoe";  //  'e', 'E|F', 'II')
char WALZE_III  [27] = "bdfhjlcprtxvznyeiwgakmusqo";  //  'v', 'V|W', 'III')
char WALZE_IV   [27] = "esovpzjayquirhxlnftgkdcmwb";  //  'j', 'J|K', 'IV')
char WALZE_V    [27] = "vzbrgityupsdnhlxawmjqofeck";  //  'z', 'Z|A', 'V')
char WALZE_VI   [27] = "jpgvoumfyqbenhzrdkasxlictw";  //  'zm', 'Z|A, M|N', 'VI')
char WALZE_VII  [27] = "nzjhgrcxmyswboufaivlpekqdt";  //  'zm', 'Z|A, M|N', 'VII')
char WALZE_VIII [27] = "fkqhtlxocbjspdzramewniuygv";  //  'zm', 'Z|A, M|N', 'VIII')

char UKW_A [27] = "ejmzalyxvbwfcrquontspikhgd";
char UKW_B [27] = "yruhqsldpxngokmiebfzcwvjat";
char UKW_C [27] = "fvpjiaoyedrzxwgctkuqsbnmhl";

    // (M4):

char UKW_B_DUENN [27] = "enkqauywjicopblmdxzvfthrgs";  // UKW B "thin"
char UKW_C_DUENN [27] = "rdobjntkvehmlfcwzaxgyipsuq";  // UKW C "thin"
char WALZE_BETA  [27] = "leyjvcnixwpbqmdrtakzgfuhos";
char WALZE_GAMMA [27] = "fsokanuerhmbtiycwlqpzxvgjd";

void apply_settings_services(void) {

    wheel_count  =  5 ;

    wheel_wirings[0] = WALZE_I;
    wheel_wirings[1] = WALZE_II;
    wheel_wirings[2] = WALZE_III;
    wheel_wirings[3] = WALZE_IV;
    wheel_wirings[4] = WALZE_V;
    wheel_wirings[5] = WALZE_VI;
    wheel_wirings[6] = WALZE_VII;
    wheel_wirings[7] = WALZE_VIII;
    wheel_wirings[8] = ABC_LOW;
    wheel_wirings[9] = ABC_LOW;

    wheel_wiring_ukw = UKW_A;
}

void apply_settings_army(void) {

    wheel_count  =  8 ;

    wheel_wirings[0] = WALZE_I;
    wheel_wirings[1] = WALZE_II;
    wheel_wirings[2] = WALZE_III;
    wheel_wirings[3] = WALZE_IV;
    wheel_wirings[4] = WALZE_V;
    wheel_wirings[5] = WALZE_VI;
    wheel_wirings[6] = WALZE_VII;
    wheel_wirings[7] = WALZE_VIII;
    wheel_wirings[8] = ABC_LOW;
    wheel_wirings[9] = ABC_LOW;

    wheel_wiring_ukw = UKW_B;
}

void apply_settings_navy(void) {

    wheel_count  =  10 ;

    wheel_wirings[0] = WALZE_BETA;
    wheel_wirings[1] = WALZE_GAMMA;
    wheel_wirings[2] = WALZE_I;
    wheel_wirings[3] = WALZE_II;
    wheel_wirings[4] = WALZE_III;
    wheel_wirings[5] = WALZE_IV;
    wheel_wirings[6] = WALZE_V;
    wheel_wirings[7] = WALZE_VI;
    wheel_wirings[8] = WALZE_VII;
    wheel_wirings[9] = WALZE_VIII;

    wheel_wiring_ukw = UKW_C;
}

// I-III (D)
// D (commercial)

char WALZE_1D [27] = "lpgszmhaeoqkvxrfybutnicjdw";  //  'y', 'Y|Z', '1D')
char WALZE_2D [27] = "slvgbtfxjqohewirzyamkpcndu";  //  'e', 'E|F', '2D')
char WALZE_3D [27] = "cjgdpshkturawzxfmynqobvlie";  //  'n', 'N|O', '3D')

char UKW_D [27] = "imetcgfraysqbzxwlhkdvupojn";

void apply_settings_commercial(void) {

    wheel_count  =  3 ;

    wheel_wirings[0] = WALZE_1D;
    wheel_wirings[1] = WALZE_2D;
    wheel_wirings[2] = WALZE_3D;
    wheel_wirings[3] = ABC_LOW;
    wheel_wirings[4] = ABC_LOW;
    wheel_wirings[5] = ABC_LOW;
    wheel_wirings[6] = ABC_LOW;
    wheel_wirings[7] = ABC_LOW;
    wheel_wirings[8] = ABC_LOW;
    wheel_wirings[9] = ABC_LOW;

    wheel_wiring_ukw = UKW_D;
}

// I-III (K)
// K "Swiss K" (Swiss)

char WALZE_1K [27] = "pezuohxscvfmtbglrinqjwaydk";  //  'y', 'Y|Z', '1K')
char WALZE_2K [27] = "zouesydkfwpciqxhmvblgnjrat";  //  'e', 'E|F', '2K')
char WALZE_3K [27] = "ehrvxgaobqusimzflynwktpdjc";  //  'n', 'N|O', '3K')

void apply_settings_swiss(void) {

    wheel_count  =  3 ;

    wheel_wirings[0] = WALZE_1K;
    wheel_wirings[1] = WALZE_2K;
    wheel_wirings[2] = WALZE_3K;
    wheel_wirings[3] = ABC_LOW;
    wheel_wirings[4] = ABC_LOW;
    wheel_wirings[5] = ABC_LOW;
    wheel_wirings[6] = ABC_LOW;
    wheel_wirings[7] = ABC_LOW;
    wheel_wirings[8] = ABC_LOW;
    wheel_wirings[9] = ABC_LOW;

    wheel_wiring_ukw = ABC_UPP;
}

// I-V (N)
// N "Norenigma" (Norway)

char WALZE_1N [27] = "wtokasuyvrbxjhqcpzefmdinlg";  //  'q', 'Q|R', '1N')
char WALZE_2N [27] = "gjlpubswemctqvhxaofzdrkyni";  //  'e', 'E|F', '2N')
char WALZE_3N [27] = "jwfmhnbpusdytixvzgrqlaoekc";  //  'v', 'V|W', '3N')
char WALZE_4N [27] = "esovpzjayquirhxlnftgkdcmwb";  //  'j', 'J|K', '4N')
char WALZE_5N [27] = "hejxqotzbvfdascilwpgynmurk";  //  'z', 'Z|A', '5N')

char UKW_N [27] = "mowjypuxndsraibfvlkzgqchet";

void apply_settings_norway(void) {

    wheel_count  =  5 ;

    wheel_wirings[0] = WALZE_1N;
    wheel_wirings[1] = WALZE_2N;
    wheel_wirings[2] = WALZE_3N;
    wheel_wirings[3] = WALZE_4N;
    wheel_wirings[4] = WALZE_5N;
    wheel_wirings[5] = ABC_LOW;
    wheel_wirings[6] = ABC_LOW;
    wheel_wirings[7] = ABC_LOW;
    wheel_wirings[8] = ABC_LOW;
    wheel_wirings[9] = ABC_LOW;

    wheel_wiring_ukw = UKW_N;
}

// I-III (R)
// R "Rocket" (Railway)

char WALZE_1R [27] = "jgdqoxuscamifrvtpnewkblzyh";  //  'n', 'N|O', '1R')
char WALZE_2R [27] = "ntzpsfbokmwrcjdivlaeyuxhgq";  //  'e', 'E|F', '2R')
char WALZE_3R [27] = "jviubhtcdyakeqzposgxnrmwfl";  //  'y', 'Y|Z', '3R')

char UKW_R [27] = "qyhognecvpuztfdjaxwmkisrbl";

void apply_settings_railway(void) {

    wheel_count  =  3 ;

    wheel_wirings[0] = WALZE_1R;
    wheel_wirings[1] = WALZE_2R;
    wheel_wirings[2] = WALZE_3R;
    wheel_wirings[3] = ABC_LOW;
    wheel_wirings[4] = ABC_LOW;
    wheel_wirings[5] = ABC_LOW;
    wheel_wirings[6] = ABC_LOW;
    wheel_wirings[7] = ABC_LOW;
    wheel_wirings[8] = ABC_LOW;
    wheel_wirings[9] = ABC_LOW;

    wheel_wiring_ukw = UKW_R;
}

// I-VIII (T)
// T "Tirpitz" (Japan)

char WALZE_1T [27] = "kptyuelocvgrfqdanjmbswhzxi";  //  'wzekq', '5 notches', '1T')
char WALZE_2T [27] = "uphzlweqmtdjxcaksoigvbyfnr";  //  'wzflr', '5 notches', '2T')
char WALZE_3T [27] = "qudlyrfekonvzaxwhmgpjbsict";  //  'wzekq', '5 notches', '3T')
char WALZE_4T [27] = "ciwtbkxnrespflydagvhquojzm";  //  'wzflr', '5 notches', '4T')
char WALZE_5T [27] = "uaxgisnjbverdylfzwtpckohmq";  //  'ycfkr', '5 notches', '5T')
char WALZE_6T [27] = "xfuzgalvhcnysewqtdmrbkpioj";  //  'xeimq', '5 notches', '6T')
char WALZE_7T [27] = "bjvftxplnayozikwgdqeruchsm";  //  'ycfkr', '5 notches', '7T')
char WALZE_8T [27] = "ymtpnzhwkodajxeluqvgcbisfr";  //  'xeimq', '5 notches', '8T')

char UKW_T [27] = "gekpbtaumocniljdxzyfhwvqsr";

void apply_settings_tirpitz(void) {

    wheel_count  =  8 ;

    wheel_wirings[0] = WALZE_1T;
    wheel_wirings[1] = WALZE_2T;
    wheel_wirings[2] = WALZE_3T;
    wheel_wirings[3] = WALZE_4T;
    wheel_wirings[4] = WALZE_5T;
    wheel_wirings[5] = WALZE_6T;
    wheel_wirings[6] = WALZE_7T;
    wheel_wirings[7] = WALZE_8T;
    wheel_wirings[8] = ABC_LOW;
    wheel_wirings[9] = ABC_LOW;

    wheel_wiring_ukw = UKW_T;
}

// I-III (A) [A-865]
// A-865 "Zählwerk" (1928)

char WALZE_1A8 [27] = "lpgszmhaeoqkvxrfybutnicjdw";  //  'suvwzabcefgiklopq', '17 notches (A-865)', '1A8')
char WALZE_2A8 [27] = "slvgbtfxjqohewirzyamkpcndu";  //  'stvyzacdfghkmnq', '15 notches (A-865)', '2A8')
char WALZE_3A8 [27] = "cjgdpshkturawzxfmynqobvlie";  //  'uwxaefhkmnr', '11 notches (A-865)', '3A8')

// (G)

char UKW_G [27] = "rulqmzjsygocetkwdahnbxpvif";

void apply_settings_zaehlwerk(void) {

    wheel_count  =  3 ;

    wheel_wirings[0] = WALZE_1A8;
    wheel_wirings[1] = WALZE_2A8;
    wheel_wirings[2] = WALZE_3A8;
    wheel_wirings[3] = ABC_LOW;
    wheel_wirings[4] = ABC_LOW;
    wheel_wirings[5] = ABC_LOW;
    wheel_wirings[6] = ABC_LOW;
    wheel_wirings[7] = ABC_LOW;
    wheel_wirings[8] = ABC_LOW;
    wheel_wirings[9] = ABC_LOW;

    wheel_wiring_ukw = ABC_LOW;
}

// I-III (G1) [G-111]
// G-111 (Hungary / Munich)

char WALZE_1G1 [27] = "wlrhbqundkjczsexotmagyfpvi";  //  'suvwzabcefgiklopq', '17 notches (G-111)', '1G1')
char WALZE_2G1 [27] = "tfjqazwmhlcuixrdygoevbnskp";  //  'stvyzacdfghkmnq', '15 notches (G-111)', '2G1')
char WALZE_5G1 [27] = "qtpixwvdfrmusljohcanezkybg";  //  'swzfhmq', '7 notches (G-111)', '5G1')

void apply_settings_hungary(void) {

    wheel_count  =  3 ;

    wheel_wirings[0] = WALZE_1G1;
    wheel_wirings[1] = WALZE_2G1;
    wheel_wirings[2] = WALZE_5G1;
    wheel_wirings[3] = ABC_LOW;
    wheel_wirings[4] = ABC_LOW;
    wheel_wirings[5] = ABC_LOW;
    wheel_wirings[6] = ABC_LOW;
    wheel_wirings[7] = ABC_LOW;
    wheel_wirings[8] = ABC_LOW;
    wheel_wirings[9] = ABC_LOW;

    wheel_wiring_ukw, UKW_G;
}

// I-III (G2) [G-260]
// G-260 (Abwehr in Argentina)

char WALZE_1G2 [27] = "rcspblkqaumhwytifzvgojnexd";  //  'suvwzabcefgiklopq', '17 notches (G-260)', '1G2')
char WALZE_2G2 [27] = "wcmibvpjxarosgndlzkeyhufqt";  //  'stvyzacdfghkmnq', '15 notches (G-260)', '2G2')
char WALZE_3G2 [27] = "fvdhzelsqmaxokyiwpgcbujtnr";  //  'uwxaefhkmnr', '11 notches (G-260)', '3G2')

void apply_settings_argentina(void) {

    wheel_count  =  3 ;

    wheel_wirings[0] = WALZE_1G2;
    wheel_wirings[1] = WALZE_2G2;
    wheel_wirings[2] = WALZE_3G2;
    wheel_wirings[3] = ABC_LOW;
    wheel_wirings[4] = ABC_LOW;
    wheel_wirings[5] = ABC_LOW;
    wheel_wirings[6] = ABC_LOW;
    wheel_wirings[7] = ABC_LOW;
    wheel_wirings[8] = ABC_LOW;
    wheel_wirings[9] = ABC_LOW;

    wheel_wiring_ukw = UKW_G;
}

// I-III (G3) [G-312]
// G-312 (Abwehr / Bletchley Park)

char WALZE_1G3 [27] = "dmtwsilruyqnkfejcazbpgxohv";  //  'suvwzabcefgiklopq', '17 notches (G-312)', '1G3')
char WALZE_2G3 [27] = "hqzgpjtmoblncifdyawveusrkx";  //  'stvyzacdfghkmnq', '15 notches (G-312)', '2G3')
char WALZE_3G3 [27] = "uqntlszfmrehdpxkibvygjcwoa";  //  'uwxaefhkmnr', '11 notches (G-312)', '3G3')

void apply_settings_bletchley(void) {

    wheel_count  =  3 ;

    wheel_wirings[0] = WALZE_1G3;
    wheel_wirings[1] = WALZE_2G3;
    wheel_wirings[2] = WALZE_3G3;
    wheel_wirings[3] = ABC_LOW;
    wheel_wirings[4] = ABC_LOW;
    wheel_wirings[5] = ABC_LOW;
    wheel_wirings[6] = ABC_LOW;
    wheel_wirings[7] = ABC_LOW;
    wheel_wirings[8] = ABC_LOW;
    wheel_wirings[9] = ABC_LOW;

    wheel_wiring_ukw = UKW_G;
}

// PROGRAM VARIABLES

unsigned short wheel_offsets[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

unsigned short wheel_count = 3 ; // default: Bletchley

char *wheel_wirings[10] = { WALZE_1G3, WALZE_2G3, WALZE_3G3, ABC_LOW, ABC_LOW, ABC_LOW, ABC_LOW, ABC_LOW, ABC_LOW, ABC_LOW } ; // default: Bletchley

char *wheel_wiring_ukw = UKW_G ; // default: Bletchley
