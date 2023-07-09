/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef ENIGMATIC_WHEELS_SETTINGS_H
#define ENIGMATIC_WHEELS_SETTINGS_H


// CONSTANTS ///////////////////////////////////////////////////////////////////

#define  SETTINGS_NAME_MAX_LENGTH      10
#define  SETTINGS_NAME_MAX_LENGTH_STR  11

// GETTERS /////////////////////////////////////////////////////////////////////

extern unsigned short settings_get_used_wheel_count(void);

extern signed short settings_get_wheel_wiring_rule(unsigned short mode,
                                                   unsigned short wheel_number,
                                                   unsigned short position);

// VALIDATORS //////////////////////////////////////////////////////////////////

extern void settings_validate_wheel_number(unsigned short wheel_number);

// SETTERS /////////////////////////////////////////////////////////////////////

extern const char SETTINGS_DEFAULT [SETTINGS_NAME_MAX_LENGTH_STR];
extern void settings_default_comment(void);
extern void settings_default_apply(void);

extern const char SETTINGS_ARGENTINA [SETTINGS_NAME_MAX_LENGTH_STR];
extern void settings_argentina_comment(void);
extern void settings_argentina_apply(void);

extern const char SETTINGS_ARMY [SETTINGS_NAME_MAX_LENGTH_STR];
extern void settings_army_comment(void);
extern void settings_army_apply(void);

extern const char SETTINGS_BLETCHLEY [SETTINGS_NAME_MAX_LENGTH_STR];
extern void settings_bletchley_comment(void);
extern void settings_bletchley_apply(void);

extern const char SETTINGS_COMMERCIAL [SETTINGS_NAME_MAX_LENGTH_STR];
extern void settings_commercial_comment(void);
extern void settings_commercial_apply(void);

extern const char SETTINGS_HUNGARY [SETTINGS_NAME_MAX_LENGTH_STR];
extern void settings_hungary_comment(void);
extern void settings_hungary_apply(void);

extern const char SETTINGS_NAVY [SETTINGS_NAME_MAX_LENGTH_STR];
extern void settings_navy_comment(void);
extern void settings_navy_apply(void);

extern const char SETTINGS_NORWAY [SETTINGS_NAME_MAX_LENGTH_STR];
extern void settings_norway_comment(void);
extern void settings_norway_apply(void);

extern const char SETTINGS_RAILWAY [SETTINGS_NAME_MAX_LENGTH_STR];
extern void settings_railway_comment(void);
extern void settings_railway_apply(void);

extern const char SETTINGS_SERVICES [SETTINGS_NAME_MAX_LENGTH_STR];
extern void settings_services_comment(void);
extern void settings_services_apply(void);

extern const char SETTINGS_SWISS [SETTINGS_NAME_MAX_LENGTH_STR];
extern void settings_swiss_comment(void);
extern void settings_swiss_apply(void);

extern const char SETTINGS_TIRPITZ [SETTINGS_NAME_MAX_LENGTH_STR];
extern void settings_tirpitz_comment(void);
extern void settings_tirpitz_apply(void);

extern const char SETTINGS_ZAEHLWERK [SETTINGS_NAME_MAX_LENGTH_STR];
extern void settings_zaehlwerk_comment(void);
extern void settings_zaehlwerk_apply(void);

#endif // ENIGMATIC_WHEELS_SETTINGS_H
