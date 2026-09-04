#include "modhw/protocol.h"

static modhw_status_t stub_init(void)
{
    return MODHW_ERR_NOT_IMPLEMENTED;
}

static const modhw_driver_t driver = {
    .name = "uart",
    .cape = "A",
    .init = stub_init,
    .probe = stub_init,
};

void modhw_uart_register(void)
{
    modhw_register_driver(&driver);
}
