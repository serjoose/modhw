# Module A — Digital bus interface

Replacement class: Bus Pirate / JTAGulator / Shikra-style **lab** IO.

## Functions

- UART, SPI, I2C, JTAG/SWD
- Pin identity scan on unknown **authorized** headers
- Optional FT2232H (MPSSE) and/or MCU-driven IO
- Logic capture: **iCE40 (preferred)** or MCU sampling fallback
- Level shift + ESD on every field pin

## Schematic-level blocks (Phase 1 freeze)

```
Cape connector
    │
    ├─ FPGA (iCE40): LA + optional TAP helper
    ├─ FT2232H (optional): dual HS USB serial/MPSSE
    ├─ Level shifters (1.8 / 3.3 / 5 V rails)
    ├─ Series R + TVS to 2.54 mm / 1.27 mm headers
    └─ Vref sense from target
```

Do not route raw target pins into the core MCU.

## Bring-up

Known JTAG pinout on a Nucleo/Discovery; SPI NOR JEDEC ID; compare to OpenOCD / Flashrom.
