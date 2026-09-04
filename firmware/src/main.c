#include "modhw/protocol.h"
#include "modhw/version.h"
#include "modhw/cape.h"

#include <stdio.h>

int main(void)
{
    printf("modhw firmware sim %s\n", MODHW_VERSION_STRING);
    modhw_register_all_builtin();

    printf("cape detect: %d (sim: none)\n", (int)modhw_cape_detect());
    printf("drivers:\n");
    for (size_t i = 0; i < modhw_driver_count(); i++) {
        const modhw_driver_t *d = modhw_driver_at(i);
        printf("  - %s [%s]\n", d->name, d->cape);
    }
    return 0;
}
