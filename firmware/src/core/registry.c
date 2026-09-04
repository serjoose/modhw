#include "modhw/protocol.h"
#include "modhw/drivers.h"

#define MODHW_MAX_DRIVERS 32

static const modhw_driver_t *g_drivers[MODHW_MAX_DRIVERS];
static size_t g_count;

void modhw_register_driver(const modhw_driver_t *drv)
{
    if (drv == NULL || g_count >= MODHW_MAX_DRIVERS) {
        return;
    }
    g_drivers[g_count++] = drv;
}

size_t modhw_driver_count(void)
{
    return g_count;
}

const modhw_driver_t *modhw_driver_at(size_t index)
{
    if (index >= g_count) {
        return NULL;
    }
    return g_drivers[index];
}

void modhw_register_all_builtin(void)
{
    modhw_uart_register();
    modhw_spi_register();
    modhw_i2c_register();
    modhw_jtag_register();
    modhw_pin_scan_register();
    modhw_subghz_register();
    modhw_nfc_register();
}
