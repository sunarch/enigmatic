
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "usage.h"
#include "wheels.h"
#include "util_debug.h"
#include "util_validate.h"


char get_wheel_output(unsigned short wheel_number, unsigned short mode, char input_char) {
    if(DEBUG) {
        inc_debug_indent();  // to function call level
        print_debug_indent();
        printf("FUNC: char get_wheel_output(...) // unsigned short wheel_number = %u // unsigned short mode = %u // char input_char = %c\n", wheel_number, mode, input_char);
        inc_debug_indent();  // to function result level
    }

    // validate wheel_number
    validate_wheel_number_any(wheel_number, get_used_wheel_count());

    char output_char = '?';
    char *p_occurence;
    unsigned short index = 0;
    unsigned short wheel_offset = 0;
    signed short wiring_rule = 0;

    // index from input (input char location in wiring alphabet)
    p_occurence = strchr(ABC_LOW, input_char);
    if(p_occurence == NULL) {
        printf("Failed check with (p_occurence == NULL): (%p == NULL)\n", p_occurence);
        printf("Exiting...\n");
        exit(1);
    }
    index = p_occurence - ABC_LOW;
    if (index >= 26) {
        printf("Failed check with (index >= 26): (%u >= 26)\n", index);
        printf("Exiting...\n");
        exit(1);
    }
    if(DEBUG) {
        print_debug_indent();
        printf("input wiring alphabet: \"ABC_LOW\")\n");
        print_debug_indent();
        printf("index from input (input char location in wiring alphabet) // %u\n", index);
    }

    // index with offset (index of letter with the wiring rule to be used)
    wheel_offset = get_wheel_offset(wheel_number);
    index = (index + wheel_offset) % 26;
    if(DEBUG) {
        print_debug_indent();
        printf("index with offset (index of letter with the wiring rule to be used) // %u\n", index);
    }

    // wiring rule
    switch(mode) {
        case WHEEL_MODE_UKW:
        case WHEEL_MODE_FRONT:
            wiring_rule = get_wheel_wiring_rules_front(wheel_number)[index];
            break;
        case WHEEL_MODE_REVERSE:
            wiring_rule = get_wheel_wiring_rules_reverse(wheel_number)[index];
            break;
        default:
            exit(1);
    }
    if(DEBUG) {
        print_debug_indent();
        printf("wiring rule // %d\n", wiring_rule);
    }

    // index after wiring rule applied
    index = (index + wiring_rule) % 26;
    if(DEBUG) {
        print_debug_indent();
        printf("index after wiring rule applied // %u\n", index);
    }

    // output char
    output_char = ABC_LOW[index];

    if(DEBUG) {
        print_debug_indent();
        printf("return output_char; // %c\n", output_char);
        dec_debug_indent();  // to function call level
        dec_debug_indent();  // to caller level
    }

    return output_char;
}

void turn_wheel(unsigned short wheel_number) {
    // validate wheel_number
    validate_wheel_number_any(wheel_number, get_used_wheel_count());

    // move wheel offset by 1
    set_wheel_offset(wheel_number, ((get_wheel_offset(wheel_number) + 1) % 26));

    if(DEBUG) {
        inc_debug_indent();  // to function call level
        print_debug_indent();
        printf("FUNC: void turn_wheel(...) // unsigned short wheel_number = %u\n", wheel_number);
        inc_debug_indent();  // to function result level
        unsigned short check_value_wheel_offset = get_wheel_offset(wheel_number);
        print_debug_indent();
        printf("CHECK: get_wheel_offset(%u) returns %u\n", wheel_number, check_value_wheel_offset);
        dec_debug_indent();  // to function call level
        dec_debug_indent();  // to caller level
    }
}


void advance_wheels(void) {

    unsigned short wheel_count = get_used_wheel_count();

    for (unsigned short n = 1; n <= wheel_count; ++n) {
        if (get_wheel_offset(n) < 25) {
            turn_wheel(n);
            break;
        }
        else if (get_wheel_offset(n) == 25) {
            turn_wheel(n);
            continue;
        }
        else {
            exit(1);
        }
    }

    if(DEBUG) {
        inc_debug_indent();  // to function call level
        print_debug_indent();
        printf("FUNC: void advance_wheels(void)\n");
        inc_debug_indent();  // to function result level
        unsigned short check_value_wheel_offset = get_wheel_offset(0);
        print_debug_indent();
        printf("CHECK: get_wheel_offset(wheel_number) // UKW (0): %u\n", check_value_wheel_offset);
        for (unsigned short n = 1; n <= wheel_count; ++n) {
            check_value_wheel_offset =  get_wheel_offset(n);
            print_debug_indent();
            printf("CHECK: get_wheel_offset(wheel_number) // w%u: %u\n", n, check_value_wheel_offset);
        }
        dec_debug_indent();  // to function call level
        dec_debug_indent();  // to caller level
    }
}

void print_config(void) {
    if(DEBUG) {
        inc_debug_indent(); // to function outer level
        print_debug_indent();
        printf("START of configuration\n");
        inc_debug_indent(); // to function inner level
    }

    printf("Wheel count: %u\n", get_used_wheel_count());
    //printf("Wheel 1 wiring: %s\n", wheel_wirings[1-1]);
    //printf("Wheel 2 wiring: %s\n", wheel_wirings[2-1]);
    //printf("Wheel 3 wiring: %s\n", wheel_wirings[3-1]);
    //printf("Wheel 4 wiring: %s\n", wheel_wirings[4-1]);
    //printf("Wheel 5 wiring: %s\n", wheel_wirings[5-1]);
    //printf("Wheel 6 wiring: %s\n", wheel_wirings[6-1]);
    //printf("Wheel 7 wiring: %s\n", wheel_wirings[7-1]);
    //printf("Wheel 8 wiring: %s\n", wheel_wirings[8-1]);
    //printf("Wheel 9 wiring: %s\n", wheel_wirings[9-1]);
    //printf("Wheel 10 wiring: %s\n", wheel_wirings[10-1]);
    //printf("UKW wiring: %s\n", wheel_wiring_ukw);

    if(DEBUG) {
        dec_debug_indent(); // to function outer level
        print_debug_indent();
        printf("END of configuration\n");
        dec_debug_indent(); // to caller level
    }
}

char *process_message(char *p_input_string) {
    if(DEBUG) {
        inc_debug_indent(); // to function outer level
        print_debug_indent();
        printf("Entered function: process_message\n");
        inc_debug_indent(); // to function inner level

        print_debug_indent();
        printf("Parameter (char *) \"p_input_string\": %s\n", p_input_string);
    }

    unsigned short wheel_count = get_used_wheel_count();

    unsigned long msg_len = strlen(p_input_string);

    char output_string[msg_len];
    char *p_output_string = output_string;

    char current_char;

    for (unsigned short n = 0; n < msg_len; ++n) {
        if(DEBUG) {
            inc_debug_indent(); // to for inner level
        }

        current_char = p_input_string[n];

        // start of character processing
        if(DEBUG) {
            print_debug_indent();
            printf("Processing next character: %c\n", current_char);
            inc_debug_indent(); // to character processing inner level
        }

        // preprocess character: uppercase to lowercase, skip special
        unsigned short index;
        char *p_occurence;
        p_occurence = strchr(ABC_LOW, current_char);
        if(p_occurence == NULL) {
            p_occurence = strchr(ABC_UPP, current_char);
            if(p_occurence != NULL) {
                index = p_occurence - ABC_UPP;
                current_char = ABC_LOW[index];
            }
            else {
                continue;
            }
        }

        // first-to-last pass / front pass
        if(DEBUG) {
            print_debug_indent();
            printf("first-to-last pass / front pass\n");
        }
        for (unsigned short n = 1; n <= wheel_count; ++n) {
            current_char = get_wheel_output(n, WHEEL_MODE_FRONT, current_char);
        }

        // UKW pass (same front and reverse)
        if(DEBUG) {
            print_debug_indent();
            printf("UKW pass (same front and reverse)\n");
        }
        current_char = get_wheel_output(UKW_INDEX, WHEEL_MODE_UKW, current_char);

        // last-to-first pass / reverse pass
        if(DEBUG) {
            print_debug_indent();
            printf("last-to-first pass / reverse pass\n");
        }
        for (unsigned short n = wheel_count; n >= 1; --n) {
            current_char = get_wheel_output(n, WHEEL_MODE_REVERSE, current_char);
        }

        // end of character processing
        if(DEBUG) {
            print_debug_indent();
            printf("Processed character: %c\n", current_char);
            dec_debug_indent(); // to for inner level
        }

        p_output_string[n] = current_char;

        advance_wheels();

        if(DEBUG) {
            dec_debug_indent(); // to function inner level
        }
    }

    if(DEBUG) {
        print_debug_indent();
        printf("Return value(char *) \"p_output_string\": %s\n", p_output_string);

        dec_debug_indent(); // to function outer level
        print_debug_indent();
        printf("Leaving function: process_message\n");
        dec_debug_indent(); // to caller level
    }

    return p_output_string;
}
