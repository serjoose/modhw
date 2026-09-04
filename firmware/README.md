# Firmware

MCU is **not locked**. This tree is a **host-simulatable skeleton**: protocol drivers register into a table; `main` prints the inventory.

```text
include/modhw/     public headers
src/core/          RTOS / cape / USB (stubs)
src/protocols/     one file per protocol
src/capture/       logic analyzer interface
src/ui/            display
src/scripts/       Lua/MicroPython host (stub)
```

## Host sim (no ARM toolchain)

```bash
cmake -S firmware -B firmware/build -DMODHW_HOST_SIM=ON
cmake --build firmware/build
./firmware/build/modhw_sim   # Windows: firmware\build\Debug\modhw_sim.exe
```

## Later

Point this CMake at an STM32 or ESP-IDF toolchain, or add `platformio.ini`, once Phase 1 picks a chip. FreeRTOS is the intended runtime ([docs/03-firmware.md](../docs/03-firmware.md)).
