
#include <string.h>

#include "wheels.h"

int wheel_offsets[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int wheel_count = 3 ; // default: Bletchley
char wheel_wirings[10][27] = { WALZE_1G3, WALZE_2G3, WALZE_3G3, ABC_LOW, ABC_LOW, ABC_LOW, ABC_LOW, ABC_LOW, ABC_LOW, ABC_LOW } ; // default: Bletchley
char wheel_wiring_ukw[27] = UKW_G ; // default: Bletchley

void apply_settings_services(void) {
    extern int wheel_count;
    extern char wheel_wirings[][27];
    extern char wheel_wiring_ukw[];
    
    wheel_count  =  5 ;

    strcpy(wheel_wirings[0], WALZE_I);
    strcpy(wheel_wirings[1], WALZE_II);
    strcpy(wheel_wirings[2], WALZE_III);
    strcpy(wheel_wirings[3], WALZE_IV);
    strcpy(wheel_wirings[4], WALZE_V);
    strcpy(wheel_wirings[5], WALZE_VI);
    strcpy(wheel_wirings[6], WALZE_VII);
    strcpy(wheel_wirings[7], WALZE_VIII);
    strcpy(wheel_wirings[8], ABC_LOW);
    strcpy(wheel_wirings[9], ABC_LOW);

    strcpy(wheel_wiring_ukw, UKW_A);
}

void apply_settings_army(void) {
    extern int wheel_count;
    extern char wheel_wirings[][27];
    extern char wheel_wiring_ukw[];
    
    wheel_count  =  8 ;

    strcpy(wheel_wirings[0], WALZE_I);
    strcpy(wheel_wirings[1], WALZE_II);
    strcpy(wheel_wirings[2], WALZE_III);
    strcpy(wheel_wirings[3], WALZE_IV);
    strcpy(wheel_wirings[4], WALZE_V);
    strcpy(wheel_wirings[5], WALZE_VI);
    strcpy(wheel_wirings[6], WALZE_VII);
    strcpy(wheel_wirings[7], WALZE_VIII);
    strcpy(wheel_wirings[8], ABC_LOW);
    strcpy(wheel_wirings[9], ABC_LOW);

    strcpy(wheel_wiring_ukw, UKW_B);
}

void apply_settings_navy(void) {
    extern int wheel_count;
    extern char wheel_wirings[][27];
    extern char wheel_wiring_ukw[];
    
    wheel_count  =  10 ;

    strcpy(wheel_wirings[0], WALZE_BETA);
    strcpy(wheel_wirings[1], WALZE_GAMMA);
    strcpy(wheel_wirings[2], WALZE_I);
    strcpy(wheel_wirings[3], WALZE_II);
    strcpy(wheel_wirings[4], WALZE_III);
    strcpy(wheel_wirings[5], WALZE_IV);
    strcpy(wheel_wirings[6], WALZE_V);
    strcpy(wheel_wirings[7], WALZE_VI);
    strcpy(wheel_wirings[8], WALZE_VII);
    strcpy(wheel_wirings[9], WALZE_VIII);

    strcpy(wheel_wiring_ukw, UKW_C);
}

void apply_settings_commercial(void) {
    extern int wheel_count;
    extern char wheel_wirings[][27];
    extern char wheel_wiring_ukw[];
    
    wheel_count  =  3 ;

    strcpy(wheel_wirings[0], WALZE_1D);
    strcpy(wheel_wirings[1], WALZE_2D);
    strcpy(wheel_wirings[2], WALZE_3D);
    strcpy(wheel_wirings[3], ABC_LOW);
    strcpy(wheel_wirings[4], ABC_LOW);
    strcpy(wheel_wirings[5], ABC_LOW);
    strcpy(wheel_wirings[6], ABC_LOW);
    strcpy(wheel_wirings[7], ABC_LOW);
    strcpy(wheel_wirings[8], ABC_LOW);
    strcpy(wheel_wirings[9], ABC_LOW);

    strcpy(wheel_wiring_ukw, UKW_D);
}

void apply_settings_swiss(void) {
    extern int wheel_count;
    extern char wheel_wirings[][27];
    extern char wheel_wiring_ukw[];
    
    wheel_count  =  3 ;

    strcpy(wheel_wirings[0], WALZE_1K);
    strcpy(wheel_wirings[1], WALZE_2K);
    strcpy(wheel_wirings[2], WALZE_3K);
    strcpy(wheel_wirings[3], ABC_LOW);
    strcpy(wheel_wirings[4], ABC_LOW);
    strcpy(wheel_wirings[5], ABC_LOW);
    strcpy(wheel_wirings[6], ABC_LOW);
    strcpy(wheel_wirings[7], ABC_LOW);
    strcpy(wheel_wirings[8], ABC_LOW);
    strcpy(wheel_wirings[9], ABC_LOW);

    strcpy(wheel_wiring_ukw, ABC_UPP);
}

void apply_settings_norway(void) {
    extern int wheel_count;
    extern char wheel_wirings[][27];
    extern char wheel_wiring_ukw[];
    
    wheel_count  =  5 ;

    strcpy(wheel_wirings[0], WALZE_1N);
    strcpy(wheel_wirings[1], WALZE_2N);
    strcpy(wheel_wirings[2], WALZE_3N);
    strcpy(wheel_wirings[3], WALZE_4N);
    strcpy(wheel_wirings[4], WALZE_5N);
    strcpy(wheel_wirings[5], ABC_LOW);
    strcpy(wheel_wirings[6], ABC_LOW);
    strcpy(wheel_wirings[7], ABC_LOW);
    strcpy(wheel_wirings[8], ABC_LOW);
    strcpy(wheel_wirings[9], ABC_LOW);

    strcpy(wheel_wiring_ukw, UKW_N);
}

void apply_settings_railway(void) {
    extern int wheel_count;
    extern char wheel_wirings[][27];
    extern char wheel_wiring_ukw[];
    
    wheel_count  =  3 ;

    strcpy(wheel_wirings[0], WALZE_1R);
    strcpy(wheel_wirings[1], WALZE_2R);
    strcpy(wheel_wirings[2], WALZE_3R);
    strcpy(wheel_wirings[3], ABC_LOW);
    strcpy(wheel_wirings[4], ABC_LOW);
    strcpy(wheel_wirings[5], ABC_LOW);
    strcpy(wheel_wirings[6], ABC_LOW);
    strcpy(wheel_wirings[7], ABC_LOW);
    strcpy(wheel_wirings[8], ABC_LOW);
    strcpy(wheel_wirings[9], ABC_LOW);

    strcpy(wheel_wiring_ukw, UKW_R);
}

void apply_settings_tirpitz(void) {
    extern int wheel_count;
    extern char wheel_wirings[][27];
    extern char wheel_wiring_ukw[];
    
    wheel_count  =  8 ;

    strcpy(wheel_wirings[0], WALZE_1T);
    strcpy(wheel_wirings[1], WALZE_2T);
    strcpy(wheel_wirings[2], WALZE_3T);
    strcpy(wheel_wirings[3], WALZE_4T);
    strcpy(wheel_wirings[4], WALZE_5T);
    strcpy(wheel_wirings[5], WALZE_6T);
    strcpy(wheel_wirings[6], WALZE_7T);
    strcpy(wheel_wirings[7], WALZE_8T);
    strcpy(wheel_wirings[8], ABC_LOW);
    strcpy(wheel_wirings[9], ABC_LOW);

    strcpy(wheel_wiring_ukw, UKW_T);
}

void apply_settings_zaehlwerk(void) {
    extern int wheel_count;
    extern char wheel_wirings[][27];
    extern char wheel_wiring_ukw[];
    
    wheel_count  =  3 ;

    strcpy(wheel_wirings[0], WALZE_1A8);
    strcpy(wheel_wirings[1], WALZE_2A8);
    strcpy(wheel_wirings[2], WALZE_3A8);
    strcpy(wheel_wirings[3], ABC_LOW);
    strcpy(wheel_wirings[4], ABC_LOW);
    strcpy(wheel_wirings[5], ABC_LOW);
    strcpy(wheel_wirings[6], ABC_LOW);
    strcpy(wheel_wirings[7], ABC_LOW);
    strcpy(wheel_wirings[8], ABC_LOW);
    strcpy(wheel_wirings[9], ABC_LOW);

    strcpy(wheel_wiring_ukw, ABC_UPP);
}

void apply_settings_hungary(void) {
    extern int wheel_count;
    extern char wheel_wirings[][27];
    extern char wheel_wiring_ukw[];
    
    wheel_count  =  3 ;

    strcpy(wheel_wirings[0], WALZE_1G1);
    strcpy(wheel_wirings[1], WALZE_2G1);
    strcpy(wheel_wirings[2], WALZE_5G1);
    strcpy(wheel_wirings[3], ABC_LOW);
    strcpy(wheel_wirings[4], ABC_LOW);
    strcpy(wheel_wirings[5], ABC_LOW);
    strcpy(wheel_wirings[6], ABC_LOW);
    strcpy(wheel_wirings[7], ABC_LOW);
    strcpy(wheel_wirings[8], ABC_LOW);
    strcpy(wheel_wirings[9], ABC_LOW);

    strcpy(wheel_wiring_ukw, UKW_G);
}

void apply_settings_argentina(void) {
    extern int wheel_count;
    extern char wheel_wirings[][27];
    extern char wheel_wiring_ukw[];
    
    wheel_count  =  3 ;

    strcpy(wheel_wirings[0], WALZE_1G2);
    strcpy(wheel_wirings[1], WALZE_2G2);
    strcpy(wheel_wirings[2], WALZE_3G2);
    strcpy(wheel_wirings[3], ABC_LOW);
    strcpy(wheel_wirings[4], ABC_LOW);
    strcpy(wheel_wirings[5], ABC_LOW);
    strcpy(wheel_wirings[6], ABC_LOW);
    strcpy(wheel_wirings[7], ABC_LOW);
    strcpy(wheel_wirings[8], ABC_LOW);
    strcpy(wheel_wirings[9], ABC_LOW);

    strcpy(wheel_wiring_ukw, UKW_G);
}

void apply_settings_bletchley(void) {
    extern int wheel_count;
    extern char wheel_wirings[][27];
    extern char wheel_wiring_ukw[];
    
    wheel_count  =  3 ;

    strcpy(wheel_wirings[0], WALZE_1G3);
    strcpy(wheel_wirings[1], WALZE_2G3);
    strcpy(wheel_wirings[2], WALZE_3G3);
    strcpy(wheel_wirings[3], ABC_LOW);
    strcpy(wheel_wirings[4], ABC_LOW);
    strcpy(wheel_wirings[5], ABC_LOW);
    strcpy(wheel_wirings[6], ABC_LOW);
    strcpy(wheel_wirings[7], ABC_LOW);
    strcpy(wheel_wirings[8], ABC_LOW);
    strcpy(wheel_wirings[9], ABC_LOW);

    strcpy(wheel_wiring_ukw, UKW_G);
}

char get_wheel_output(int wheel_number, char input_char) {
    extern char wheel_wirings[][27];
    extern char wheel_wiring_ukw[];
    
    // 0: UKW_INDEX, 1-8: wheels
    if (wheel_number < 0 || wheel_number > 8) { wheel_number = 1; }

    int wheel_offset = 0;
    if (wheel_number != UKW_INDEX) {
        wheel_offset = get_wheel_offset(wheel_number);
    }

    char output;

    int index = 23;
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

void turn_wheel(int wheelNumber) {
    extern int wheel_offsets[];
    extern int wheel_count;
    
    if (wheelNumber < 1 || wheelNumber > wheel_count) { return; }
    wheel_offsets[wheelNumber-1] = (wheel_offsets[wheelNumber-1] + 1) % 26;
}

int get_wheel_offset(int wheelNumber) {
    extern int wheel_offsets[];
    extern int wheel_count;
    
    if (wheelNumber < 1 || wheelNumber > wheel_count) { return 0; }
    return wheel_offsets[wheelNumber-1];
}

void set_wheel_offset(int wheelNumber, int new_offset) {
    extern int wheel_offsets[];
    extern int wheel_count;
    
    if (wheelNumber < 1 || wheelNumber > wheel_count) { return; }
    wheel_offsets[wheelNumber-1] = new_offset % 26;
}

void advance_wheels(void) {
    extern int wheel_count;
    
    for (int n = wheel_count; n >= 1; --n) {
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
    extern int wheel_offsets[];
    
    for (int n = 1; n <= 10; ++n) {
        wheel_offsets[n-1] = 0;
    }
}

void reset_wheel_wirings(void) {
    extern char wheel_wirings[][27];
    
    for (int n = 1; n <= 10; ++n) {
        strcpy(wheel_wirings[n-1], ABC_LOW);
    }
}

void set_used_wheel_count(int count) {
    extern int wheel_offsets[];
    extern int wheel_count;
    
    if (count < 1 || count > 10) { return; }
    wheel_count = count;
    reset_wheel_offsets();
}

char process_char(char input_char) {
    extern int wheel_count;
    
    char current_char = input_char;
    for (int n = 1; n <= wheel_count; ++n) {
        current_char = get_wheel_output(n, current_char);
    }

    current_char = get_wheel_output(0, current_char);

    for (int n = wheel_count; n <= 1; --n) {
        current_char = get_wheel_output(n, current_char);
    }

    advance_wheels();

    return current_char;
}

