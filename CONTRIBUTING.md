# Contributing

modhw is in **Phase 0**: docs + empty module trees. Useful PRs:

1. Fill the **decision log** in `docs/02-hardware-selection.md` with a justified MCU/cape choice
2. Host-sim firmware drivers that compile (`firmware/`)
3. Companion USB framing (once a document exists)
4. KiCad **after** pinout freeze — not before

## Rules

- Authorized-use only; see `docs/LEGAL.md`
- No dumps, captures, credentials, or exploit write-ups in the repo
- One protocol per firmware file; no monolithic `everything.c`
- Side-channel, glitch, and decap stay out of v1

## Git

Conventional, short messages. Do not skip hooks unless a maintainer asks.
