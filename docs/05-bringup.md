# Phase 4 — Bring-up (overlaps Phase 3)

Bring **one subsystem at a time**. Highest value / lowest risk first: **Module A digital buses**.

## Suggested sequence

1. Core: blink, USB enumerate, µSD mount, display hello
2. Cape ID EEPROM / resistor ID
3. UART loopback → SPI flash (known JEDEC ID) → I2C scan (known expander)
4. JTAG against a **dev board with a published pinout**
5. Pin-scan routine vs that same known header (regression: must match datasheet)
6. Logic capture vs a known clock (compare to a Saleae / sigrok dump)
7. Module B: CC1101 / Si4463 register read, then PN532 SAM config, then LF coil
8. Companion: record a session, run a carving plugin on a **public** firmware image

## Golden targets (examples)

- MCU eval board with documented SWD/JTAG
- Commodity SPI NOR with datasheet
- PN532 breakout + a card you own

If it does not match **Flashrom** / **OpenOCD** / vendor tools on those targets, do not trust it on unknown hardware.
