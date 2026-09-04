# Phase 2 — Firmware / software architecture

**Timebox:** 4–6 weeks for the *shape* of the stack (can overlap hardware).

## Core runtime

- **FreeRTOS** on the core MCU (default). Bare-metal only if the MCU choice is tiny and capture is 100% FPGA.
- Tasks (draft): `ui`, `usb`, `storage`, `cape`, `protocol`, `capture`.

## Protocol engine

Pluggable drivers. Each protocol is a separate compilation unit + registration table:

| Module | Files (stubs) |
|--------|----------------|
| UART | `firmware/src/protocols/uart.c` |
| SPI | `firmware/src/protocols/spi.c` |
| I2C | `firmware/src/protocols/i2c.c` |
| JTAG | `firmware/src/protocols/jtag.c` |
| Pin scan | `firmware/src/protocols/pin_scan.c` |
| Sub-GHz | `firmware/src/protocols/subghz.c` |
| NFC | `firmware/src/protocols/nfc.c` |

Do not grow a single `everything.c`.

## Pin scan (JTAGulator-class)

Runs against an **unknown header on an authorized target**: iterate candidate pin roles, look for valid TAP / UART / I2C ACKs. Results go to display + companion. No assumption that a lock or secret will be recovered — identity of **pins**, not “bypass.”

## Companion (desktop)

- Python backend, CLI first, GUI later if needed
- Stream capture / dumps over USB
- Plugins for **Binwalk-style carving** and hand-off to existing RE tools
- **Do not** run Ghidra-class analysis on the MCU

Package: `companion/` (`modhw` CLI).

## On-device scripting

Lua **or** MicroPython for glue (GreatFET / Bus Pirate-style). Stub hook: `firmware/src/scripts/`. Pick one language in Phase 2 so the REPL and sandbox exist before a pile of one-off C tools.

## USB protocol (draft)

Versioned framed packets: `sync | ver | type | len | payload | crc`. Types: ping, cape inventory, protocol ioctl, capture start/stop, file on µSD, script eval. Freeze this before writing a GUI.
