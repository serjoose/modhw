#ifndef MODHW_CAPE_H
#define MODHW_CAPE_H

#include "modhw/protocol.h"

typedef enum {
    MODHW_CAPE_NONE = 0,
    MODHW_CAPE_A_DIGITAL = 1,
    MODHW_CAPE_B_RF = 2,
    MODHW_CAPE_C_SDR = 3
} modhw_cape_id_t;

modhw_cape_id_t modhw_cape_detect(void);

#endif
