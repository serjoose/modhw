#include "modhw/cape.h"

modhw_cape_id_t modhw_cape_detect(void)
{
    /* Real impl: I2C ID EEPROM or resistor strap on the cape connector. */
    return MODHW_CAPE_NONE;
}
