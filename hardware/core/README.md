# Core board

**In:** MCU/SoC, USB, display + input, microSD, 18650 charge/boost, cape connector, status LEDs.

**Out:** Field-facing JTAG/SPI at 5 V, RF matching networks, FPGA (those belong on capes unless you later fold FPGA onto core).

## Open items

- MCU: STM32H7 vs ESP32-S3 ([docs/02-hardware-selection.md](../../docs/02-hardware-selection.md))
- USB-C vs Micro-B
- LCD + rotary encoder vs capacitive touch
- Cape: stacking headers vs board-to-board; pin count TBD

## KiCad

Place `modhw-core.kicad_pro` here after Phase 1 lock.
