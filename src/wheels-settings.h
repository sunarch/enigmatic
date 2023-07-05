/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef ENIGMATIC_WHEELS_SETTINGS_H
#define ENIGMATIC_WHEELS_SETTINGS_H

#include "alphabet-common.h"
#include "wheels-common.h"

// PUBLIC VARIABLES ////////////////////////////////////////////////////////////

extern signed short wheel_wiring_rules_front   [WHEELS_COUNT_MAX_TOTAL][ABC_LENGTH];
extern signed short wheel_wiring_rules_reverse [WHEELS_COUNT_MAX_TOTAL][ABC_LENGTH];

// GETTERS /////////////////////////////////////////////////////////////////////

extern unsigned short get_used_wheel_count(void);

// VALIDATORS //////////////////////////////////////////////////////////////////

extern void validate_wheel_number(unsigned short wheel_number);

// SETTERS /////////////////////////////////////////////////////////////////////

#define  DEFAULT  "default"

extern void settings_default_comment(void);
extern void settings_default_apply(void);

#define  ARGENTINA           "argentina"
#define  PADDING_ARGENTINA            "  "
#define  ARMY                "army"
#define  PADDING_ARMY            "       "
#define  BLETCHLEY           "bletchley"
#define  PADDING_BLETCHLEY            "  "
#define  COMMERCIAL          "commercial"
#define  PADDING_COMMERCIAL            " "
#define  HUNGARY             "hungary"
#define  PADDING_HUNGARY            "    "
#define  NAVY                "navy"
#define  PADDING_NAVY            "       "
#define  NORWAY              "norway"
#define  PADDING_NORWAY            "     "
#define  RAILWAY             "railway"
#define  PADDING_RAILWAY            "    "
#define  SERVICES            "services"
#define  PADDING_SERVICES            "   "
#define  SWISS               "swiss"
#define  PADDING_SWISS            "      "
#define  TIRPITZ             "tirpitz"
#define  PADDING_TIRPITZ            "    "
#define  ZAEHLWERK           "zaehlwerk"
#define  PADDING_ZAEHLWERK            "  "

extern void settings_argentina_comment(void);
extern void settings_argentina_apply(void);

extern void settings_army_comment(void);
extern void settings_army_apply(void);

extern void settings_bletchley_comment(void);
extern void settings_bletchley_apply(void);

extern void settings_commercial_comment(void);
extern void settings_commercial_apply(void);

extern void settings_hungary_comment(void);
extern void settings_hungary_apply(void);

extern void settings_navy_comment(void);
extern void settings_navy_apply(void);

extern void settings_norway_comment(void);
extern void settings_norway_apply(void);

extern void settings_railway_comment(void);
extern void settings_railway_apply(void);

extern void settings_services_comment(void);
extern void settings_services_apply(void);

extern void settings_swiss_comment(void);
extern void settings_swiss_apply(void);

extern void settings_tirpitz_comment(void);
extern void settings_tirpitz_apply(void);

extern void settings_zaehlwerk_comment(void);
extern void settings_zaehlwerk_apply(void);

#endif // ENIGMATIC_WHEELS_SETTINGS_H
