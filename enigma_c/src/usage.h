
#ifndef _USAGE_H_
#define _USAGE_H_

#define  UKW_INDEX  0

extern char ABC_UPP [27];  // ordered Alphabet
extern char ABC_LOW [27];  // ordered Alphabet

extern void apply_settings_services(void);
extern void apply_settings_army(void);
extern void apply_settings_navy(void);
extern void apply_settings_commercial(void);
extern void apply_settings_swiss(void);
extern void apply_settings_norway(void);
extern void apply_settings_railway(void);
extern void apply_settings_tirpitz(void);
extern void apply_settings_zaehlwerk(void);
extern void apply_settings_hungary(void);
extern void apply_settings_argentina(void);
extern void apply_settings_bletchley(void);

extern unsigned short wheel_offsets[10];
extern unsigned short wheel_count;
extern char *wheel_wirings[10];
extern char *wheel_wiring_ukw;

char get_wheel_output(unsigned short wheel_number, char input_char);
void turn_wheel(unsigned short wheelNumber);
unsigned short get_wheel_offset(unsigned short wheelNumber);
void set_wheel_offset(unsigned short wheelNumber, unsigned short new_offset);
void advance_wheels(void);
void reset_wheel_offsets(void);
void set_used_wheel_count(unsigned short count);
char process_char(char input_char);

#endif
