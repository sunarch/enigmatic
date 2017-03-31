
#include <stdio.h>
#include <stdlib.h>

#include "util_validate.h"

void validate_wheel_number_any(unsigned short wheel_number, unsigned short wheel_count) {
    // wheel_number: 0: UKW_INDEX, 1-10: wheels
    if (wheel_number > wheel_count) {
        printf("Failed check with (wheel_number > wheel_count): (%u > %u)\n", wheel_number, wheel_count);
        printf("Exiting...\n");
        exit(1);
    }
}

void validate_wheel_number_ukw(unsigned short wheel_number) {
    // wheel_number: 0: UKW_INDEX, 1-10: wheels
    if (wheel_number != UKW_INDEX) {
        printf("Failed check with (wheel_number != UKW_INDEX): (%u != %u)\n", wheel_number, UKW_INDEX);
        printf("Exiting...\n");
        exit(1);
    }
}

void validate_wheel_number_not_ukw(unsigned short wheel_number, unsigned short wheel_count) {
    // wheel_number: 0: UKW_INDEX, 1-10: wheels
    if (wheel_number == UKW_INDEX || wheel_number > wheel_count) {
        printf("Failed check with (wheel_number == UKW_INDEX): (%u == %u)\n", wheel_number, UKW_INDEX);
        printf("Exiting...\n");
        exit(1);
    }
}
