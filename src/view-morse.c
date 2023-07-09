/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdio.h>

#include "util-text.h"
#include "view-morse.h"
#include "view-pager.h"


// MACROS //////////////////////////////////////////////////////////////////////

#define  MORSE_CODE_MAX_LENGTH       6
#define  MORSE_CODE_MAX_LENGTH_STR   7
#define  PART_MAX_LENGTH            14

// CONSTANTS ///////////////////////////////////////////////////////////////////

static const char A_MORSE [MORSE_CODE_MAX_LENGTH] = ".-";
static const char B_MORSE [MORSE_CODE_MAX_LENGTH] = "-...";
static const char C_MORSE [MORSE_CODE_MAX_LENGTH] = "-.-.";
static const char D_MORSE [MORSE_CODE_MAX_LENGTH] = "-..";
static const char E_MORSE [MORSE_CODE_MAX_LENGTH] = ".";
static const char F_MORSE [MORSE_CODE_MAX_LENGTH] = "..-.";
static const char G_MORSE [MORSE_CODE_MAX_LENGTH] = "--.";
static const char H_MORSE [MORSE_CODE_MAX_LENGTH] = "....";
static const char I_MORSE [MORSE_CODE_MAX_LENGTH] = "..";
static const char J_MORSE [MORSE_CODE_MAX_LENGTH] = ".---";
static const char K_MORSE [MORSE_CODE_MAX_LENGTH] = "-.-";
static const char L_MORSE [MORSE_CODE_MAX_LENGTH] = ".-..";
static const char M_MORSE [MORSE_CODE_MAX_LENGTH] = "--";
static const char N_MORSE [MORSE_CODE_MAX_LENGTH] = "-.";
static const char O_MORSE [MORSE_CODE_MAX_LENGTH] = "---";
static const char P_MORSE [MORSE_CODE_MAX_LENGTH] = ".--.";
static const char Q_MORSE [MORSE_CODE_MAX_LENGTH] = "--.-";
static const char R_MORSE [MORSE_CODE_MAX_LENGTH] = ".-.";
static const char S_MORSE [MORSE_CODE_MAX_LENGTH] = "...";
static const char T_MORSE [MORSE_CODE_MAX_LENGTH] = "-";
static const char U_MORSE [MORSE_CODE_MAX_LENGTH] = "..-";
static const char V_MORSE [MORSE_CODE_MAX_LENGTH] = "...-";
static const char W_MORSE [MORSE_CODE_MAX_LENGTH] = ".--";
static const char X_MORSE [MORSE_CODE_MAX_LENGTH] = "-..-";
static const char Y_MORSE [MORSE_CODE_MAX_LENGTH] = "-.--";
static const char Z_MORSE [MORSE_CODE_MAX_LENGTH] = "--..";

// non-letters

static const char DOT_MORSE [MORSE_CODE_MAX_LENGTH] = ".-.-.-";


// PRIVATE /////////////////////////////////////////////////////////////////////

static void morse_print_char_padded(const char *code_text)
{
        printf("%s", code_text);
        text_print_padding(code_text, MORSE_CODE_MAX_LENGTH);
}


static void morse_print_char(char character)
{
        switch (character) {
                case 'a':
                        morse_print_char_padded(A_MORSE);
                        break;
                case 'b':
                        morse_print_char_padded(B_MORSE);
                        break;
                case 'c':
                        morse_print_char_padded(C_MORSE);
                        break;
                case 'd':
                        morse_print_char_padded(D_MORSE);
                        break;
                case 'e':
                        morse_print_char_padded(E_MORSE);
                        break;
                case 'f':
                        morse_print_char_padded(F_MORSE);
                        break;
                case 'g':
                        morse_print_char_padded(G_MORSE);
                        break;
                case 'h':
                        morse_print_char_padded(H_MORSE);
                        break;
                case 'i':
                        morse_print_char_padded(I_MORSE);
                        break;
                case 'j':
                        morse_print_char_padded(J_MORSE);
                        break;
                case 'k':
                        morse_print_char_padded(K_MORSE);
                        break;
                case 'l':
                        morse_print_char_padded(L_MORSE);
                        break;
                case 'm':
                        morse_print_char_padded(M_MORSE);
                        break;
                case 'n':
                        morse_print_char_padded(N_MORSE);
                        break;
                case 'o':
                        morse_print_char_padded(O_MORSE);
                        break;
                case 'p':
                        morse_print_char_padded(P_MORSE);
                        break;
                case 'q':
                        morse_print_char_padded(Q_MORSE);
                        break;
                case 'r':
                        morse_print_char_padded(R_MORSE);
                        break;
                case 's':
                        morse_print_char_padded(S_MORSE);
                        break;
                case 't':
                        morse_print_char_padded(T_MORSE);
                        break;
                case 'u':
                        morse_print_char_padded(U_MORSE);
                        break;
                case 'v':
                        morse_print_char_padded(V_MORSE);
                        break;
                case 'w':
                        morse_print_char_padded(W_MORSE);
                        break;
                case 'x':
                        morse_print_char_padded(X_MORSE);
                        break;
                case 'y':
                        morse_print_char_padded(Y_MORSE);
                        break;
                case 'z':
                        morse_print_char_padded(Z_MORSE);
                        break;
                case '.':
                        morse_print_char_padded(DOT_MORSE);
                        break;
                default:
                        morse_print_char_padded("");
                        break;
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
