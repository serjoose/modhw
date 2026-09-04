#ifndef MODHW_DRIVERS_H
#define MODHW_DRIVERS_H

void modhw_uart_register(void);
void modhw_spi_register(void);
void modhw_i2c_register(void);
void modhw_jtag_register(void);
void modhw_pin_scan_register(void);
void modhw_subghz_register(void);
void modhw_nfc_register(void);

#endif
