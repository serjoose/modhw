# Phase 5 — Field testing & iteration (ongoing)

## Legal targets only

Your own IoT, lab gear, and hardware CTF kits sold for practice. See [LEGAL.md](LEGAL.md).

## Compare to reference tools

| Capability | Reference to beat / match |
|------------|---------------------------|
| JTAG / SWD | OpenOCD on the same board |
| Pin scan | JTAGulator (or documented pinout) |
| SPI flash | Flashrom |
| Logic capture | sigrok / PulseView / Saleae |
| Sub-GHz | YARD Stick One / rtl_433 on the same signal |
| NFC | Known PN532 host tools / a card you own |

Record pass/fail in `docs/test-log.md` (create when you have results). Do not check in dumps.

## Out of v1 (do not chase)

- ChipWhisperer-tier SCA / glitch
- Decap
- On-device disassembly
