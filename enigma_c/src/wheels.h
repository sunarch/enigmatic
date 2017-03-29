
#ifndef _WHEELS_H_
#define _WHEELS_H_

unsigned short wheel_offsets[10];
unsigned short wheel_count;
char wheel_wirings[10][27];
char wheel_wiring_ukw[27];
#define  UKW_INDEX  0

char get_wheel_output(unsigned short wheel_number, char input_char);
void turn_wheel(unsigned short wheelNumber);
unsigned short get_wheel_offset(unsigned short wheelNumber);
void set_wheel_offset(unsigned short wheelNumber, unsigned short new_offset);
void advance_wheels(void);
void reset_wheel_offsets(void);
void set_used_wheel_count(unsigned short count);
char process_char(char input_char);

#define  ABC_UPP  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"  // ordered Alphabet
#define  ABC_LOW  "abcdefghijklmnopqrstuvwxyz"  // ordered Alphabet

// Rotor wheels (wiring, turnover points, c-o info, name)
// Reflectors (UKW)

// W. I-VIII (I,M3,M4)
// I "Services" (Army, GAF)
// M3 (Army, Navy)
// M4 "Shark" (U-Boats)

void apply_settings_services(void);
void apply_settings_army(void);
void apply_settings_navy(void);

#define  WALZE_I     "ekmflgdqvzntowyhxuspaibrcj"  //  'q', 'Q|R', 'I')
#define  WALZE_II    "ajdksiruxblhwtmcqgznpyfvoe"  //  'e', 'E|F', 'II')
#define  WALZE_III   "bdfhjlcprtxvznyeiwgakmusqo"  //  'v', 'V|W', 'III')
#define  WALZE_IV    "esovpzjayquirhxlnftgkdcmwb"  //  'j', 'J|K', 'IV')
#define  WALZE_V     "vzbrgityupsdnhlxawmjqofeck"  //  'z', 'Z|A', 'V')
#define  WALZE_VI    "jpgvoumfyqbenhzrdkasxlictw"  //  'zm', 'Z|A, M|N', 'VI')
#define  WALZE_VII   "nzjhgrcxmyswboufaivlpekqdt"  //  'zm', 'Z|A, M|N', 'VII')
#define  WALZE_VIII  "fkqhtlxocbjspdzramewniuygv"  //  'zm', 'Z|A, M|N', 'VIII')

#define  UKW_A  "ejmzalyxvbwfcrquontspikhgd"
#define  UKW_B  "yruhqsldpxngokmiebfzcwvjat"
#define  UKW_C  "fvpjiaoyedrzxwgctkuqsbnmhl"

    // (M4):

#define  UKW_B_DUENN  "enkqauywjicopblmdxzvfthrgs"  // UKW B "thin"
#define  UKW_C_DUENN  "rdobjntkvehmlfcwzaxgyipsuq"  // UKW C "thin"
#define  WALZE_BETA   "leyjvcnixwpbqmdrtakzgfuhos"
#define  WALZE_GAMMA  "fsokanuerhmbtiycwlqpzxvgjd"

// I-III (D)
// D (commercial)

void apply_settings_commercial(void);

#define  WALZE_1D  "lpgszmhaeoqkvxrfybutnicjdw"  //  'y', 'Y|Z', '1D')
#define  WALZE_2D  "slvgbtfxjqohewirzyamkpcndu"  //  'e', 'E|F', '2D')
#define  WALZE_3D  "cjgdpshkturawzxfmynqobvlie"  //  'n', 'N|O', '3D')

#define  UKW_D  "imetcgfraysqbzxwlhkdvupojn"

// I-III (K)
// K "Swiss K" (Swiss)

void apply_settings_swiss(void);

#define  WALZE_1K  "pezuohxscvfmtbglrinqjwaydk"  //  'y', 'Y|Z', '1K')
#define  WALZE_2K  "zouesydkfwpciqxhmvblgnjrat"  //  'e', 'E|F', '2K')
#define  WALZE_3K  "ehrvxgaobqusimzflynwktpdjc"  //  'n', 'N|O', '3K')

// I-V (N)
// N "Norenigma" (Norway)

void apply_settings_norway(void);

#define  WALZE_1N  "wtokasuyvrbxjhqcpzefmdinlg"  //  'q', 'Q|R', '1N')
#define  WALZE_2N  "gjlpubswemctqvhxaofzdrkyni"  //  'e', 'E|F', '2N')
#define  WALZE_3N  "jwfmhnbpusdytixvzgrqlaoekc"  //  'v', 'V|W', '3N')
#define  WALZE_4N  "esovpzjayquirhxlnftgkdcmwb"  //  'j', 'J|K', '4N')
#define  WALZE_5N  "hejxqotzbvfdascilwpgynmurk"  //  'z', 'Z|A', '5N')

#define  UKW_N  "mowjypuxndsraibfvlkzgqchet"

// I-III (R)
// R "Rocket" (Railway)

void apply_settings_railway(void);

#define  WALZE_1R  "jgdqoxuscamifrvtpnewkblzyh"  //  'n', 'N|O', '1R')
#define  WALZE_2R  "ntzpsfbokmwrcjdivlaeyuxhgq"  //  'e', 'E|F', '2R')
#define  WALZE_3R  "jviubhtcdyakeqzposgxnrmwfl"  //  'y', 'Y|Z', '3R')

#define  UKW_R  "qyhognecvpuztfdjaxwmkisrbl"

// I-VIII (T)
// T "Tirpitz" (Japan)

void apply_settings_tirpitz(void);

#define  WALZE_1T  "kptyuelocvgrfqdanjmbswhzxi"  //  'wzekq', '5 notches', '1T')
#define  WALZE_2T  "uphzlweqmtdjxcaksoigvbyfnr"  //  'wzflr', '5 notches', '2T')
#define  WALZE_3T  "qudlyrfekonvzaxwhmgpjbsict"  //  'wzekq', '5 notches', '3T')
#define  WALZE_4T  "ciwtbkxnrespflydagvhquojzm"  //  'wzflr', '5 notches', '4T')
#define  WALZE_5T  "uaxgisnjbverdylfzwtpckohmq"  //  'ycfkr', '5 notches', '5T')
#define  WALZE_6T  "xfuzgalvhcnysewqtdmrbkpioj"  //  'xeimq', '5 notches', '6T')
#define  WALZE_7T  "bjvftxplnayozikwgdqeruchsm"  //  'ycfkr', '5 notches', '7T')
#define  WALZE_8T  "ymtpnzhwkodajxeluqvgcbisfr"  //  'xeimq', '5 notches', '8T')

#define  UKW_T  "gekpbtaumocniljdxzyfhwvqsr"

// I-III (A) [A-865]
// A-865 "Zählwerk" (1928)

void apply_settings_zaehlwerk(void);

#define  WALZE_1A8  "lpgszmhaeoqkvxrfybutnicjdw"  //  'suvwzabcefgiklopq', '17 notches (A-865)', '1A8')
#define  WALZE_2A8  "slvgbtfxjqohewirzyamkpcndu"  //  'stvyzacdfghkmnq', '15 notches (A-865)', '2A8')
#define  WALZE_3A8  "cjgdpshkturawzxfmynqobvlie"  //  'uwxaefhkmnr', '11 notches (A-865)', '3A8')

// (G)

#define  UKW_G  "rulqmzjsygocetkwdahnbxpvif"

// I-III (G1) [G-111]
// G-111 (Hungary / Munich)

void apply_settings_hungary(void);

#define  WALZE_1G1  "wlrhbqundkjczsexotmagyfpvi"  //  'suvwzabcefgiklopq', '17 notches (G-111)', '1G1')
#define  WALZE_2G1  "tfjqazwmhlcuixrdygoevbnskp"  //  'stvyzacdfghkmnq', '15 notches (G-111)', '2G1')
#define  WALZE_5G1  "qtpixwvdfrmusljohcanezkybg"  //  'swzfhmq', '7 notches (G-111)', '5G1')

// I-III (G2) [G-260]
// G-260 (Abwehr in Argentina)

void apply_settings_argentina(void);

#define  WALZE_1G2  "rcspblkqaumhwytifzvgojnexd"  //  'suvwzabcefgiklopq', '17 notches (G-260)', '1G2')
#define  WALZE_2G2  "wcmibvpjxarosgndlzkeyhufqt"  //  'stvyzacdfghkmnq', '15 notches (G-260)', '2G2')
#define  WALZE_3G2  "fvdhzelsqmaxokyiwpgcbujtnr"  //  'uwxaefhkmnr', '11 notches (G-260)', '3G2')

// I-III (G3) [G-312]
// G-312 (Abwehr / Bletchley Park)

void apply_settings_bletchley(void);

#define  WALZE_1G3 "dmtwsilruyqnkfejcazbpgxohv"  //  'suvwzabcefgiklopq', '17 notches (G-312)', '1G3')
#define  WALZE_2G3 "hqzgpjtmoblncifdyawveusrkx"  //  'stvyzacdfghkmnq', '15 notches (G-312)', '2G3')
#define  WALZE_3G3 "uqntlszfmrehdpxkibvygjcwoa"  //  'uwxaefhkmnr', '11 notches (G-312)', '3G3')


#endif
