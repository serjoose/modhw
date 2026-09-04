# Phase 0 — Scope

**Timebox:** 1–2 weeks (decision, not implementation).

Cramming RF + JTAG + side-channel + decap onto one PCB is how these projects die. v1 is a **modular core + capes**.

## In for v1

| Piece | Role |
|-------|------|
| Core | MCU/SoC, USB, display, µSD, battery, GPIO / cape connector |
| Module A | Digital buses: JTAG, SPI, I2C, UART (Bus Pirate / JTAGulator / Shikra-class) |
| Module B | Sub-GHz transceiver + NFC/RFID (HF) + LF coil path (Flipper / YARD Stick / Proxmark-lite class) |
| Logic capture | Prefer dedicated FPGA (Saleae-class bandwidth); MCU sampling is a fallback |
| Companion app | Stream logs/dumps to a laptop; carving / analysis plugins |
| On-device scripting | Lua or MicroPython for custom protocol glue |

## Stretch (v1 only if Module A/B are real)

| Piece | Role |
|-------|------|
| Module C | Wideband SDR frontend (HackRF-lite class) |

## Explicitly out of v1

| Topic | Why |
|-------|-----|
| Side-channel / glitching | Different analog discipline (ChipWhisperer-class). Later cape, not the first PCB. |
| Decapsulation | Chemistry and optics, not a portable electronics box. Never “in the product.” |
| On-device IDA/Ghidra-class RE | Runs on the companion (or existing desktop tools), not the MCU. |

## Architecture decision (locked)

**Modular over monolithic.** Shared core, pluggable front-ends (Flipper-style GPIO expansion, or BeagleBone-style capes).
