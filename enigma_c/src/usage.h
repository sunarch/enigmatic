
#ifndef _USAGE_H_
#define _USAGE_H_

#define  WHEEL_MODE_UKW      0
#define  WHEEL_MODE_FRONT    1
#define  WHEEL_MODE_REVERSE  2

unsigned short calculate_index_after_wiring_rule(unsigned short index_before, signed short wiring_rule);
char get_wheel_output(unsigned short wheel_number, unsigned short mode, char input_char);

void turn_wheel(unsigned short wheelNumber);
void advance_wheels(void);

void print_config_section(signed short *wheel_wiring_rules);
void print_config(void);

char *process_message(char *pInputString);


#endif
