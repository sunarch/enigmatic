
#ifndef _UTIL_VALIDATE_H_
#define _UTIL_VALIDATE_H_

#ifndef  UKW_INDEX
#define  UKW_INDEX  0
#endif

void validate_wheel_number_any(unsigned short wheel_number, unsigned short wheel_count);
void validate_wheel_number_ukw(unsigned short wheel_number);
void validate_wheel_number_not_ukw(unsigned short wheel_number, unsigned short wheel_count);

#endif
