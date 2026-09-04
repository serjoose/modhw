#include "modhw/protocol.h"

static modhw_status_t stub_init(void)
{
    return MODHW_ERR_NOT_IMPLEMENTED;
}

static const modhw_driver_t driver = {
    .name = "nfc",
    .cape = "B",
    .init = stub_init,
    .probe = stub_init,
};

void modhw_nfc_register(void)
{
    modhw_register_driver(&driver);
}
