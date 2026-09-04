#ifndef MODHW_PROTOCOL_H
#define MODHW_PROTOCOL_H

#include <stddef.h>
#include <stdint.h>

typedef enum {
    MODHW_OK = 0,
    MODHW_ERR_NOT_IMPLEMENTED = 1,
    MODHW_ERR_NO_CAPE = 2,
    MODHW_ERR_BAD_ARG = 3
} modhw_status_t;

typedef struct {
    const char *name;
    const char *cape; /* "core", "A", "B", "C" */
    modhw_status_t (*init)(void);
    modhw_status_t (*probe)(void);
} modhw_driver_t;

void modhw_register_driver(const modhw_driver_t *drv);
size_t modhw_driver_count(void);
const modhw_driver_t *modhw_driver_at(size_t index);
void modhw_register_all_builtin(void);

#endif
