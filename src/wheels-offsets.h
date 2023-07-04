/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef ENIGMATIC_WHEELS_OFFSETS_H
#define ENIGMATIC_WHEELS_OFFSETS_H

extern unsigned short offsets_get(unsigned short wheel_number);

extern void offsets_set(unsigned short wheel_number,
                        unsigned short new_offset);

extern void offsets_reset(void);

#endif // ndef ENIGMATIC_WHEELS_OFFSETS_H
