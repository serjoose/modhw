#include "modhw/protocol.h"

static modhw_status_t stub_init(void)
{
    return MODHW_ERR_NOT_IMPLEMENTED;
}

static const modhw_driver_t driver = {
    .name = "spi",
    .cape = "A",
    .init = stub_init,
    .probe = stub_init,
};

void modhw_spi_register(void)
{
    modhw_register_driver(&driver);
}
