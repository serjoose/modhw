#include "modhw/protocol.h"

modhw_status_t modhw_script_eval(const char *source)
{
    (void)source;
    /* Lua or MicroPython — pick one in Phase 2. */
    return MODHW_ERR_NOT_IMPLEMENTED;
}
