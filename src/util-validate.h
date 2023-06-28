/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef _UTIL_VALIDATE_H_
#define _UTIL_VALIDATE_H_

#ifndef  UKW_INDEX
#define  UKW_INDEX  0
#endif

extern void validate_wheel_number_any(unsigned short wheel_number,
                                      unsigned short wheel_count);

extern void validate_wheel_number_ukw(unsigned short wheel_number);

extern void validate_wheel_number_not_ukw(unsigned short wheel_number,
                                          unsigned short wheel_count);

#endif // ndef _UTIL_VALIDATE_H_
