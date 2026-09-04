# Phase 1 — Hardware selection

**Timebox:** 2–3 weeks. Lock MCU + Module A path before drawing the core schematic.

## Candidates

| Subsystem | Candidates | Notes |
|-----------|------------|--------|
| MCU | STM32H7 **or** ESP32-S3 | H7: speed + peripherals. S3: radio + cost. Pick one for v1 core; don’t dual-support at spin 1. |
| Digital bus IO | FT2232H **or** MCU bit-bang | FT2232H: dual high-speed, known MPSSE. Bit-bang: fewer chips, more firmware. |
| Logic capture | iCE40 FPGA **or** MCU + sigrok sampling | FPGA is the highest-leverage v1 add if the goal is Saleae-class bandwidth. |
| Sub-GHz | CC1101 **or** Si4463 | Same families as YARD Stick One-class tools. |
| NFC / RFID | PN532 + custom LF (125 kHz) coil | HF NFC + LF. Proxmark-class LF is a cape problem, not a core problem. |
| SDR (stretch) | RTL-SDR **or** MAX2837 + MAX5864 | Only after A/B work. |
| Storage | microSD | Dumps, capture logs. |
| Display / UX | Small color LCD + encoder **or** touch | Field use matters; encoder is easier in gloves. |
| Power | 18650 + charge / boost | Portable. Size the boost for FPGA + RF peaks. |

## Decision log (fill in)

| Decision | Choice | Date | Rationale |
|----------|--------|------|-----------|
| MCU | _TBD_ | | |
| Digital IO | _TBD_ | | |
| Capture | _TBD_ | | |
| Sub-GHz IC | _TBD_ | | |
| Display | _TBD_ | | |
| Cape connector | _TBD_ (pin count, stacking?) | | |

## Recommendation bias (not locked)

If the differentiator is **capture bandwidth**, prefer **H7 + iCE40 + FT2232H or FPGA-hosted TAP**, and treat ESP32 Wi-Fi as a later core revision — not a requirement for Module A.

## Prototype before PCB

Bring each IC up on vendor breakouts (FTDI, CC1101, PN532, iCE40HX/UP) before a combined spin. See [04-pcb.md](04-pcb.md).
