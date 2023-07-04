/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wheels.h"
#include "wheels-offsets.h"
#include "wheels-settings.h"

#ifdef DEBUG
    #include "debug.h"
#endif

// INTERNAL CONSTANTS //////////////////////////////////////////////////////////

#define  BUFFER_LENGTH_APPLY_OPTION  16

// settings ////////////////////////////////////////////////////////////////////

void wheels_apply_default(void)
{
    settings_default_apply();
}

void wheels_apply_prompt(void)
{
    offsets_reset();

    printf("Select option to apply:\n");
    printf("|-> '%s'%s- ", ARGENTINA,  PADDING_ARGENTINA);  settings_argentina_comment();  printf("\n");
    printf("|-> '%s'%s- ", ARMY,       PADDING_ARMY);       settings_army_comment();       printf("\n");
    printf("|-> '%s'%s- ", BLETCHLEY,  PADDING_BLETCHLEY);  settings_bletchley_comment();  printf("\n");
    printf("|-> '%s'%s- ", COMMERCIAL, PADDING_COMMERCIAL); settings_commercial_comment(); printf("\n");
    printf("|-> '%s'%s- ", HUNGARY,    PADDING_HUNGARY);    settings_hungary_comment();    printf("\n");
    printf("|-> '%s'%s- ", NAVY,       PADDING_NAVY);       settings_navy_comment();       printf("\n");
    printf("|-> '%s'%s- ", NORWAY,     PADDING_NORWAY);     settings_norway_comment();     printf("\n");
    printf("|-> '%s'%s- ", RAILWAY,    PADDING_RAILWAY);    settings_railway_comment();    printf("\n");
    printf("|-> '%s'%s- ", SERVICES,   PADDING_SERVICES);   settings_services_comment();   printf("\n");
    printf("|-> '%s'%s- ", SWISS,      PADDING_SWISS);      settings_swiss_comment();      printf("\n");
    printf("|-> '%s'%s- ", TIRPITZ,    PADDING_TIRPITZ);    settings_tirpitz_comment();    printf("\n");
    printf("|-> '%s'%s- ", ZAEHLWERK,  PADDING_ZAEHLWERK);  settings_zaehlwerk_comment();  printf("\n");
    printf("Default: ");                                    settings_default_comment();    printf("\n");
    printf("Apply option: ");

    static char apply_option[BUFFER_LENGTH_APPLY_OPTION]  = "-";

    // get input
    if (fgets(apply_option, BUFFER_LENGTH_APPLY_OPTION, stdin) == NULL) {
        printf("Failed to get apply option\n");
        printf("Exiting...\n");
        exit(1);
    };

    /* Remove trailing newline, if there. */
    unsigned short apply_option_length = strlen(apply_option);
    if ((apply_option_length > 0) && (apply_option[apply_option_length - 1] == '\n')) {
        apply_option[apply_option_length - 1] = '\0';
    }

    if (strcmp(apply_option, DEFAULT) == STRCMP_EQUAL) {
        settings_default_apply();
    }
    else if (strcmp(apply_option, ARGENTINA) == STRCMP_EQUAL) {
        settings_argentina_apply();
    }
    else if (strcmp(apply_option, ARMY) == STRCMP_EQUAL) {
        settings_army_apply();
    }
    else if (strcmp(apply_option, BLETCHLEY) == STRCMP_EQUAL) {
        settings_bletchley_apply();
    }
    else if (strcmp(apply_option, COMMERCIAL) == STRCMP_EQUAL) {
        settings_commercial_apply();
    }
    else if (strcmp(apply_option, HUNGARY) == STRCMP_EQUAL) {
        settings_hungary_apply();
    }
    else if (strcmp(apply_option, NAVY) == STRCMP_EQUAL) {
        settings_navy_apply();
    }
    else if (strcmp(apply_option, NORWAY) == STRCMP_EQUAL) {
        settings_norway_apply();
    }
    else if (strcmp(apply_option, RAILWAY) == STRCMP_EQUAL) {
        settings_railway_apply();
    }
    else if (strcmp(apply_option, SERVICES) == STRCMP_EQUAL) {
        settings_services_apply();
    }
    else if (strcmp(apply_option, SWISS) == STRCMP_EQUAL) {
        settings_swiss_apply();
    }
    else if (strcmp(apply_option, TIRPITZ) == STRCMP_EQUAL) {
        settings_tirpitz_apply();
    }
    else if (strcmp(apply_option, ZAEHLWERK) == STRCMP_EQUAL) {
        settings_zaehlwerk_apply();
    }
    else {
        printf("Setting option not recognized: '%s'\n", apply_option);
        settings_default_apply();
    }
}

// OTHER FUNCTIONS /////////////////////////////////////////////////////////////

signed short *get_wheel_wiring_rules_front(unsigned short wheel_number)
{
    // no debug messages in getter functions, include them as checks in calls

    // validate wheel number
    validate_wheel_number(wheel_number);

    return wheel_wiring_rules_front[wheel_number];
}

signed short *get_wheel_wiring_rules_reverse(unsigned short wheel_number)
{
    // no debug messages in getter functions, include them as checks in calls

    // validate wheel number
    validate_wheel_number(wheel_number);

    return wheel_wiring_rules_reverse[wheel_number];
}

unsigned short wheels_get_count(void)
{
    return get_used_wheel_count();
}

void collect_wheel_wiring_rules_front_for_position(unsigned short position, signed short *rules)
{
    if (position > 25) { return; }

    for (unsigned short i = 0; i < 11; ++i) {
        rules[i] = wheel_wiring_rules_front[i][position];
    }

}

void collect_wheel_wiring_rules_reverse_for_position(unsigned short position, signed short *rules)
{
    if (position > 25) { return; }

    for (unsigned short i = 0; i < 11; ++i) {
        rules[i] = wheel_wiring_rules_reverse[i][position];
    }
}
