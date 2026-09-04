#include "modhw/protocol.h"

/* Pin-role scan against an authorized unknown header (JTAGulator-class).
 * Implementation belongs here once Module A IO exists. */

static modhw_status_t stub_init(void)
{
    return MODHW_ERR_NOT_IMPLEMENTED;
}

static const modhw_driver_t driver = {
    .name = "pin_scan",
    .cape = "A",
    .init = stub_init,
    .probe = stub_init,
};

void modhw_pin_scan_register(void)
{
    modhw_register_driver(&driver);
}
