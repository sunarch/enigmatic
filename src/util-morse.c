/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdio.h>

#include "util-morse.h"
#include "util-pager.h"


// CONSTANTS ///////////////////////////////////////////////////////////////////

#define  PART_MAX_LENGTH  20

// Paddings by morse code length ///////////////////////////////////////////////

#define  PADDING_MORSE_0  "       "
#define  PADDING_MORSE_1  "      "
#define  PADDING_MORSE_2  "     "
#define  PADDING_MORSE_3  "    "
#define  PADDING_MORSE_4  "   "
#define  PADDING_MORSE_5  "  "
#define  PADDING_MORSE_6  " "

// Morse codes and paddings for letters ////////////////////////////////////////

#define  A_MORSE    ".-"
#define  A_PADDING  PADDING_MORSE_2
#define  B_MORSE    "-..."
#define  B_PADDING  PADDING_MORSE_4
#define  C_MORSE    "-.-."
#define  C_PADDING  PADDING_MORSE_4
#define  D_MORSE    "-.."
#define  D_PADDING  PADDING_MORSE_3
#define  E_MORSE    "."
#define  E_PADDING  PADDING_MORSE_1
#define  F_MORSE    "..-."
#define  F_PADDING  PADDING_MORSE_4
#define  G_MORSE    "--."
#define  G_PADDING  PADDING_MORSE_3
#define  H_MORSE    "...."
#define  H_PADDING  PADDING_MORSE_4
#define  I_MORSE    ".."
#define  I_PADDING  PADDING_MORSE_2
#define  J_MORSE    ".---"
#define  J_PADDING  PADDING_MORSE_4
#define  K_MORSE    "-.-"
#define  K_PADDING  PADDING_MORSE_3
#define  L_MORSE    ".-.."
#define  L_PADDING  PADDING_MORSE_4
#define  M_MORSE    "--"
#define  M_PADDING  PADDING_MORSE_2
#define  N_MORSE    "-."
#define  N_PADDING  PADDING_MORSE_2
#define  O_MORSE    "---"
#define  O_PADDING  PADDING_MORSE_3
#define  P_MORSE    ".--."
#define  P_PADDING  PADDING_MORSE_4
#define  Q_MORSE    "--.-"
#define  Q_PADDING  PADDING_MORSE_4
#define  R_MORSE    ".-."
#define  R_PADDING  PADDING_MORSE_3
#define  S_MORSE    "..."
#define  S_PADDING  PADDING_MORSE_3
#define  T_MORSE    "-"
#define  T_PADDING  PADDING_MORSE_1
#define  U_MORSE    "..-"
#define  U_PADDING  PADDING_MORSE_3
#define  V_MORSE    "...-"
#define  V_PADDING  PADDING_MORSE_4
#define  W_MORSE    ".--"
#define  W_PADDING  PADDING_MORSE_3
#define  X_MORSE    "-..-"
#define  X_PADDING  PADDING_MORSE_4
#define  Y_MORSE    "-.--"
#define  Y_PADDING  PADDING_MORSE_4
#define  Z_MORSE    "--.."
#define  Z_PADDING  PADDING_MORSE_4

// Morse codes and paddings for non-letters ////////////////////////////////////

#define  DOT_MORSE    ".-.-.-"
#define  DOT_PADDING  PADDING_MORSE_6


// PRIVATE /////////////////////////////////////////////////////////////////////

static void morse_print_char(char character)
{
    switch (character) {
        case 'a':
            printf(A_MORSE);
            printf(A_PADDING);
            break;
        case 'b':
            printf(B_MORSE);
            printf(B_PADDING);
            break;
        case 'c':
            printf(C_MORSE);
            printf(C_PADDING);
            break;
        case 'd':
            printf(D_MORSE);
            printf(D_PADDING);
            break;
        case 'e':
            printf(E_MORSE);
            printf(E_PADDING);
            break;
        case 'f':
            printf(F_MORSE);
            printf(F_PADDING);
            break;
        case 'g':
            printf(G_MORSE);
            printf(G_PADDING);
            break;
        case 'h':
            printf(H_MORSE);
            printf(H_PADDING);
            break;
        case 'i':
            printf(I_MORSE);
            printf(I_PADDING);
            break;
        case 'j':
            printf(J_MORSE);
            printf(J_PADDING);
            break;
        case 'k':
            printf(K_MORSE);
            printf(K_PADDING);
            break;
        case 'l':
            printf(L_MORSE);
            printf(L_PADDING);
            break;
        case 'm':
            printf(M_MORSE);
            printf(M_PADDING);
            break;
        case 'n':
            printf(N_MORSE);
            printf(N_PADDING);
            break;
        case 'o':
            printf(O_MORSE);
            printf(O_PADDING);
            break;
        case 'p':
            printf(P_MORSE);
            printf(P_PADDING);
            break;
        case 'q':
            printf(Q_MORSE);
            printf(Q_PADDING);
            break;
        case 'r':
            printf(R_MORSE);
            printf(R_PADDING);
            break;
        case 's':
            printf(S_MORSE);
            printf(S_PADDING);
            break;
        case 't':
            printf(T_MORSE);
            printf(T_PADDING);
            break;
        case 'u':
            printf(U_MORSE);
            printf(U_PADDING);
            break;
        case 'v':
            printf(V_MORSE);
            printf(V_PADDING);
            break;
        case 'w':
            printf(W_MORSE);
            printf(W_PADDING);
            break;
        case 'x':
            printf(X_MORSE);
            printf(X_PADDING);
            break;
        case 'y':
            printf(Y_MORSE);
            printf(Y_PADDING);
            break;
        case 'z':
            printf(Z_MORSE);
            printf(Z_PADDING);
            break;
        case '.':
            printf(DOT_MORSE);
            printf(DOT_PADDING);
            break;
        default:
            printf(PADDING_MORSE_0);
            break;
    }
}


static void morse_item_char_label(void)
{
    printf("        ");
}


static void morse_item_char_formatted(char character)
{
    printf("'%c'    ", character);
}


static void morse_item_code_label(void)
{
    printf("MORSE:  ");
}


static void morse_item_code_formatted(char character)
{
    morse_print_char(character);
}


// GENERAL /////////////////////////////////////////////////////////////////////

void morse_print(char *p_text, unsigned short indent_length)
{
    pager_print(p_text,
                indent_length,
                PART_MAX_LENGTH,
                &morse_item_char_label,
                &morse_item_char_formatted,
                &morse_item_code_label,
                &morse_item_code_formatted);
}
