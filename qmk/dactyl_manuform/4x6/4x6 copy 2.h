#pragma once

#include "dactyl_manuform.h"

#define XXX KC_NO

#define LAYOUT( \
    k00, k01, k02, k03, k04, k05,                    k50, k51, k52, k53, k54, k55, \
    k10, k11, k12, k13, k14, k15,                    k60, k61, k62, k63, k64, k65, \
    k20, k21, k22, k23, k24, k25,                    k70, k71, k72, k73, k74, k75, \
              k32, k33,                                        k82, k83, \
                        k34, k35,                    k80, k81, \
                        k44, k45,                    k90, k91, \
              k42, k43,                                        k92, k93 \
) { \
    { k00, k01, k02, k03, k04, k05 }, \
    { k10, k11, k12, k13, k14, k15 }, \
    { k20, k21, k22, k23, k24, k25 }, \
    { XXX, XXX, k32, k33, k34, k35 }, \
    { XXX, XXX, k42, k43, k44, k45 }, \
\
    { k50, k51, k52, k53, k54, k55 }, \
    { k60, k61, k62, k63, k64, k65 }, \
    { k70, k71, k72, k73, k74, k75 }, \
    { k80, k81, k82, k83, XXX, XXX }, \
    { k90, k91, k92, k93, XXX, XXX } \
}
