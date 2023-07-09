/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdio.h>

#include "util-abc.h"
#include "util-abc-common.h"
#include "util-text.h"
#include "view-morse.h"
#include "view-pager.h"


// MACROS //////////////////////////////////////////////////////////////////////

#define  MORSE_CODE_MAX_LENGTH          6
#define  MORSE_CODE_MAX_LENGTH_STRING   7
#define  PART_MAX_LENGTH               14

// CONSTANTS ///////////////////////////////////////////////////////////////////

static const char A_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = ".-";
static const char B_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = "-...";
static const char C_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = "-.-.";
static const char D_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = "-..";
static const char E_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = ".";
static const char F_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = "..-.";
static const char G_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = "--.";
static const char H_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = "....";
static const char I_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = "..";
static const char J_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = ".---";
static const char K_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = "-.-";
static const char L_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = ".-..";
static const char M_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = "--";
static const char N_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = "-.";
static const char O_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = "---";
static const char P_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = ".--.";
static const char Q_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = "--.-";
static const char R_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = ".-.";
static const char S_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = "...";
static const char T_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = "-";
static const char U_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = "..-";
static const char V_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = "...-";
static const char W_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = ".--";
static const char X_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = "-..-";
static const char Y_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = "-.--";
static const char Z_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = "--..";

// non-letters

static const char DOT_MORSE [MORSE_CODE_MAX_LENGTH_STRING] = ".-.-.-";

// reference list

static const char *MORSE_LETTERS [ABC_LENGTH_STRING] = {
        A_MORSE, B_MORSE, C_MORSE, D_MORSE, E_MORSE,
        F_MORSE, G_MORSE, H_MORSE, I_MORSE, J_MORSE,
        K_MORSE, L_MORSE, M_MORSE, N_MORSE, O_MORSE,
        P_MORSE, Q_MORSE, R_MORSE, S_MORSE, T_MORSE,
        U_MORSE, V_MORSE, W_MORSE, X_MORSE, Y_MORSE,
        Z_MORSE
};


// PRIVATE /////////////////////////////////////////////////////////////////////

static void morse_print_char_padded(const char *code_text)
{
        printf("%s", code_text);
        text_print_padding(code_text, MORSE_CODE_MAX_LENGTH);
}


static void morse_print_char(char character)
{
        signed short letter_index = abc_index_from_char_lower(character);
        if (letter_index < 0) {
                if (character == '.') {
                        morse_print_char_padded(DOT_MORSE);
                }
                else {
                        morse_print_char_padded("");
                }
        }
        else {
                morse_print_char_padded(MORSE_LETTERS[letter_index]);
        }
        printf(" ");
}


static void morse_print_char_label(void)
{
        printf("        ");
}


static void morse_print_char_formatted(char character)
{
        printf("'%c'    ", character);
}


static void morse_print_code_label(void)
{
        printf("MORSE:  ");
}


static void morse_print_code_formatted(char character)
{
        morse_print_char(character);
}


// GENERAL /////////////////////////////////////////////////////////////////////

void morse_print(char *p_text, unsigned short indent_length)
{
        pager_print(p_text,
                    indent_length,
                    PART_MAX_LENGTH,
                    &morse_print_char_label,
                    &morse_print_char_formatted,
                    &morse_print_code_label,
                    &morse_print_code_formatted);
}
