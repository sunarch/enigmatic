/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "util-abc.h"
#include "util-abc-common.h"
#include "util-text.h"
#include "wheels.h"
#include "wheels-common.h"
#include "wheels-offsets.h"
#include "wheels-settings.h"


#ifdef DEBUG
#include "util-debug.h"
#include "wheels-common.h"
#endif


// MACRO VALUES ////////////////////////////////////////////////////////////////

#define  BUFFER_LENGTH_APPLY_OPTION  16


// CALCULATORS /////////////////////////////////////////////////////////////////

static unsigned short wheels_calculate_index_after_offset(unsigned short index_before,
                                                          unsigned short offset)
{
        return (unsigned short) ((index_before + offset) % ABC_LENGTH);
}


unsigned short wheels_calculate_index_after_wiring_rule(unsigned short index_before,
                                                        signed short wiring_rule)
{
        signed short index_plus_rule = ((signed short) index_before) + wiring_rule;

        unsigned short index_abc_offset = abs(index_plus_rule) % ABC_LENGTH;

        if (index_plus_rule < 0) {
                return ABC_LENGTH - index_abc_offset;
        }
        else {
                return index_abc_offset;
        }
}


// GETTERS /////////////////////////////////////////////////////////////////////

char wheels_get_output_single(unsigned short wheel_number,
                              unsigned short mode,
                              char input_char)
{
#ifdef DEBUG
        debug_print_prefix();
        debug_indent_increment();
        debug_indent_print();
        printf("(wheel ");
        debug_print_number_unsigned_limited(wheel_number, WHEELS_COUNT_MAX_TOTAL);
        printf(") (mode '%u')", mode);
#endif

        settings_validate_wheel_number(wheel_number);

        short index_found = abc_index_from_char_lower(input_char);
        if (index_found < 0) {
                printf("Char '%c' not found in alphabet\n", input_char);
                printf("Exiting...\n");
                exit(RETURN_CODE_ERROR);
        }
        unsigned short input_index = (unsigned short) index_found;

        unsigned short wheel_offset = offsets_get(wheel_number);

#ifdef DEBUG
        printf(" (offset ");
        debug_print_number_unsigned_limited(wheel_offset, WHEELS_COUNT_MAX_TOTAL);
        printf(")");
#endif

#ifdef DEBUG
        printf(" (in '%c'_", input_char);
        debug_print_number_unsigned_limited(input_index, ABC_LENGTH);
        printf(")");
#endif

        unsigned short offset_index = wheels_calculate_index_after_offset(input_index, wheel_offset);
        signed short wiring_rule = settings_get_wheel_wiring_rule(mode, wheel_number, offset_index);

#ifdef DEBUG
        printf(" (rule ");
        debug_print_number_signed_tens(wiring_rule);
        printf(")");
#endif

        unsigned short output_index = wheels_calculate_index_after_wiring_rule(input_index, wiring_rule);
        char output_char = abc_char_lower_from_index(output_index);

#ifdef DEBUG
        printf(" (out ");
        debug_print_number_unsigned_limited(output_index, ABC_LENGTH);
        printf("_'%c')\n", output_char);
        debug_indent_decrement();
#endif

        return output_char;
}


static char wheels_get_output_pass_front(char character, unsigned short wheel_count)
{
#ifdef DEBUG
        debug_print_prefix();
        debug_indent_print();
        printf("first-to-last pass / front pass\n");
#endif

        for (unsigned short i = 1; i <= wheel_count; ++i) {
                character = wheels_get_output_single(i, WHEEL_MODE_FRONT, character);
        }

        return character;
}


static char wheels_get_output_pass_ukw(char character)
{
#ifdef DEBUG
        debug_print_prefix();
        debug_indent_print();
        printf("UKW pass (same front and reverse)\n");
#endif

        character = wheels_get_output_single(UKW_INDEX, WHEEL_MODE_UKW, character);

        return character;
}


static char wheels_get_output_pass_reverse(char character, unsigned short wheel_count)
{
#ifdef DEBUG
        debug_print_prefix();
        debug_indent_print();
        printf("last-to-first pass / reverse pass\n");
#endif

        for (unsigned short i = wheel_count; i >= 1; --i) {
                character = wheels_get_output_single(i, WHEEL_MODE_REVERSE, character);
        }

        return character;
}


char wheels_get_output(char character)
{
        unsigned short wheel_count = settings_get_used_wheel_count();

        character = wheels_get_output_pass_front(character, wheel_count);
        character = wheels_get_output_pass_ukw(character);
        character = wheels_get_output_pass_reverse(character, wheel_count);

        offsets_advance();

        return character;
}


// SETTERS - PRIVATE HELPER ////////////////////////////////////////////////////

static void wheels_print_prompt_option(const char *settings_name, void (*pf_print_settings_comment)(void))
{
        printf("|-> '%s'", settings_name);
        text_print_padding(settings_name, SETTINGS_NAME_MAX_LENGTH);
        printf(" - ");
        pf_print_settings_comment();
        printf("\n");
}


// SETTERS - PUBLIC ////////////////////////////////////////////////////////////

void wheels_apply_default(void)
{
        settings_default_apply();
}


void wheels_apply_prompt(void)
{
        offsets_reset();

        printf("Select option to apply:\n");
        wheels_print_prompt_option(SETTINGS_ARGENTINA, &settings_argentina_comment);
        wheels_print_prompt_option(SETTINGS_ARMY, &settings_army_comment);
        wheels_print_prompt_option(SETTINGS_BLETCHLEY, &settings_bletchley_comment);
        wheels_print_prompt_option(SETTINGS_COMMERCIAL, &settings_commercial_comment);
        wheels_print_prompt_option(SETTINGS_HUNGARY, &settings_hungary_comment);
        wheels_print_prompt_option(SETTINGS_NAVY, &settings_navy_comment);
        wheels_print_prompt_option(SETTINGS_NORWAY, &settings_norway_comment);
        wheels_print_prompt_option(SETTINGS_RAILWAY, &settings_railway_comment);
        wheels_print_prompt_option(SETTINGS_SERVICES, &settings_services_comment);
        wheels_print_prompt_option(SETTINGS_SWISS, &settings_swiss_comment);
        wheels_print_prompt_option(SETTINGS_TIRPITZ, &settings_tirpitz_comment);
        wheels_print_prompt_option(SETTINGS_ZAEHLWERK, &settings_zaehlwerk_comment);

        printf("Default: ");
        settings_default_comment();
        printf("\n");


        static char apply_option[BUFFER_LENGTH_APPLY_OPTION] = "-";

        // get input
        printf("Apply option: ");
        if (fgets(apply_option, BUFFER_LENGTH_APPLY_OPTION, stdin) == NULL) {
                printf("Failed to get apply option\n");
                printf("Exiting...\n");
                exit(RETURN_CODE_ERROR);
        }

        /* Remove trailing newline, if there. */
        unsigned short apply_option_length = (unsigned short) strlen(apply_option);
        if ((apply_option_length > 0) && (apply_option[apply_option_length - 1] == '\n')) {
                apply_option[apply_option_length - 1] = '\0';
        }

             if (strcmp(apply_option, SETTINGS_DEFAULT)    == STRCMP_EQUAL) { settings_default_apply();    }
        else if (strcmp(apply_option, SETTINGS_ARGENTINA)  == STRCMP_EQUAL) { settings_argentina_apply();  }
        else if (strcmp(apply_option, SETTINGS_ARMY)       == STRCMP_EQUAL) { settings_army_apply();       }
        else if (strcmp(apply_option, SETTINGS_BLETCHLEY)  == STRCMP_EQUAL) { settings_bletchley_apply();  }
        else if (strcmp(apply_option, SETTINGS_COMMERCIAL) == STRCMP_EQUAL) { settings_commercial_apply(); }
        else if (strcmp(apply_option, SETTINGS_HUNGARY)    == STRCMP_EQUAL) { settings_hungary_apply();    }
        else if (strcmp(apply_option, SETTINGS_NAVY)       == STRCMP_EQUAL) { settings_navy_apply();       }
        else if (strcmp(apply_option, SETTINGS_NORWAY)     == STRCMP_EQUAL) { settings_norway_apply();     }
        else if (strcmp(apply_option, SETTINGS_RAILWAY)    == STRCMP_EQUAL) { settings_railway_apply();    }
        else if (strcmp(apply_option, SETTINGS_SERVICES)   == STRCMP_EQUAL) { settings_services_apply();   }
        else if (strcmp(apply_option, SETTINGS_SWISS)      == STRCMP_EQUAL) { settings_swiss_apply();      }
        else if (strcmp(apply_option, SETTINGS_TIRPITZ)    == STRCMP_EQUAL) { settings_tirpitz_apply();    }
        else if (strcmp(apply_option, SETTINGS_ZAEHLWERK)  == STRCMP_EQUAL) { settings_zaehlwerk_apply();  }
        else {
                printf("Setting option not recognized: '%s'\n", apply_option);
                settings_default_apply();
        }
}
