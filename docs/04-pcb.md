# Phase 3 — PCB design & prototyping

**Timebox:** 4–8 weeks per serious spin, after breakout bring-up.

## Tooling

- **KiCad** for schematic + layout (free, fine at this scale)
- JLCPCB / PCBWay for small batches
- Expect **2–3 hardware revisions** minimum; budget money and calendar for that

## Order of operations

1. Breakout / breadboard **per subsystem** (MCU nucleo/devkit, FT2232H, CC1101, PN532, FPGA)
2. Cape connector pinout freeze + dummy “loopback cape”
3. Core schematic (power first, then MCU, then connector)
4. Module A schematic (IO protection + FPGA + optional FT2232H)
5. Module B schematic (RF layout as its own board; do not mix with digital IO on v1)
6. Layout: RF keep-outs, USB HS, FPGA, battery safety
7. Fab + assembly (or hand-stuff first proto)

## Design rules to remember

- ESD and series protection on every field-facing pin
- Level shifting explicit (1.8 / 3.3 / 5 V targets)
- 18650: protection IC, temperature, USB-C CC if you use USB-C
- FPGA I/O banks vs 5 V — never assume
- Module B: 50 Ω, ground vias, keep digital clocks off the RF section

KiCad projects will live under `hardware/kicad/` once they exist. This skeleton only has module READMEs.
