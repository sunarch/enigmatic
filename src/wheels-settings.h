/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef ENIGMATIC_WHEELS_SETTINGS_H
#define ENIGMATIC_WHEELS_SETTINGS_H

// GETTERS /////////////////////////////////////////////////////////////////////

extern unsigned short get_used_wheel_count(void);

extern signed short get_wheel_wiring_rule(unsigned short mode,
                                          unsigned short wheel_number,
                                          unsigned short position);

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
