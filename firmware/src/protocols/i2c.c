#include "modhw/protocol.h"

static modhw_status_t stub_init(void)
{
    return MODHW_ERR_NOT_IMPLEMENTED;
}

static const modhw_driver_t driver = {
    .name = "i2c",
    .cape = "A",
    .init = stub_init,
    .probe = stub_init,
};

void modhw_i2c_register(void)
{
    modhw_register_driver(&driver);
}
