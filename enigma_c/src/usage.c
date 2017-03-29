
#include <stdlib.h>
#include <string.h>

#include "usage.h"

char get_wheel_output(unsigned short wheel_number, char input_char) {

    // 0: UKW_INDEX, 1-8: wheels
    if (wheel_number > 8) { exit(1); }

    unsigned short wheel_offset = 0;
    if (wheel_number != UKW_INDEX) {
        wheel_offset = get_wheel_offset(wheel_number);
    }

    char output;

    unsigned short index = 23;
    char *p_occurence;

    p_occurence = strchr(ABC_UPP, input_char);
    if(p_occurence) { index = p_occurence - ABC_UPP; }
    else {
        p_occurence = strchr(ABC_LOW, input_char);
        if(p_occurence) { index = p_occurence - ABC_LOW; }
    }

    if (wheel_number == UKW_INDEX) {
        output = wheel_wiring_ukw[(index + wheel_offset) % 26];
    }
    else {
        output = wheel_wirings[wheel_number][(index + wheel_offset) % 26];
    }

    return output;
}

void turn_wheel(unsigned short wheelNumber) {

    if (wheelNumber < 1 || wheelNumber > wheel_count) { return; }
    wheel_offsets[wheelNumber-1] = (wheel_offsets[wheelNumber-1] + 1) % 26;
}

unsigned short get_wheel_offset(unsigned short wheelNumber) {

    if (wheelNumber < 1 || wheelNumber > wheel_count) { return 0; }
    return wheel_offsets[wheelNumber-1];
}

void set_wheel_offset(unsigned short wheelNumber, unsigned short new_offset) {

    if (wheelNumber < 1 || wheelNumber > wheel_count) { return; }
    wheel_offsets[wheelNumber-1] = new_offset % 26;
}

void advance_wheels(void) {

    for (unsigned short n = wheel_count; n >= 1; --n) {
        if (n == wheel_count) {
            turn_wheel(n);
        }
        else if (get_wheel_offset(n+1) == 0) {
            turn_wheel(n);
        }
        else {
            break;
        }
    }
}

void reset_wheel_offsets(void) {

    for (unsigned short n = 1; n <= 10; ++n) {
        wheel_offsets[n-1] = 0;
    }
}

void reset_wheel_wirings(void) {

    for (unsigned short n = 1; n <= 10; ++n) {
        wheel_wirings[n-1] = ABC_LOW;
    }
}

void set_used_wheel_count(unsigned short count) {

    if (count < 1 || count > 10) { return; }
    wheel_count = count;
    reset_wheel_offsets();
}

char process_char(char input_char) {

    char current_char = input_char;
    for (unsigned short n = 1; n <= wheel_count; ++n) {
        current_char = get_wheel_output(n, current_char);
    }

    current_char = get_wheel_output(0, current_char);

    for (unsigned short n = wheel_count; n <= 1; --n) {
        current_char = get_wheel_output(n, current_char);
    }

    advance_wheels();

    return current_char;
}

