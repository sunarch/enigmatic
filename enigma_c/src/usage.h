
#ifndef _USAGE_H_
#define _USAGE_H_

#define  WHEEL_MODE_UKW      0
#define  WHEEL_MODE_FRONT    1
#define  WHEEL_MODE_REVERSE  2

char get_wheel_output(unsigned short wheel_number, unsigned short mode, char input_char);

void turn_wheel(unsigned short wheelNumber);
void advance_wheels(void);

void print_config(void);

char *process_message(char *pInputString);


#endif
