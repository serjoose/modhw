# modhw

Modular portable hardware **lab** tool: a **core board** plus swappable front-end **capes**.

v1 goal: digital buses (JTAG / SPI / I2C / UART) + sub-GHz + NFC/RFID, with FPGA-class logic capture as the high-leverage stretch. Heavy analysis (firmware carving, disassembly) lives on a **laptop companion app**, not on the device.

> Use only on hardware you own or have **explicit authorization** to test. See [docs/LEGAL.md](docs/LEGAL.md).

## Architecture (one sentence)

**Core** (MCU, USB, display, storage, battery, GPIO) + **Module A** (digital bus) + **Module B** (sub-GHz + NFC/RFID) + optional **Module C** (SDR). Side-channel, glitching, and decap are **out of v1**.

```
┌─────────────────────────────────────────────┐
│  Core: MCU/SoC · USB · LCD · µSD · 18650    │
│        GPIO / cape connector                │
└───────────────┬─────────────────────────────┘
                │ common cape interconnect
     ┌──────────┼──────────┬──────────┐
     ▼          ▼          ▼          ▼
  Module A   Module B   Module C   (future)
  Digital    Sub-GHz    SDR        SCA / glitch
  buses      + NFC/LF   (stretch)  (not v1)
```

## Repo map

| Path | What it is |
|------|------------|
| [docs/](docs/) | Scope, architecture, phases, part candidates |
| [hardware/](hardware/) | KiCad placeholders, per-module notes |
| [firmware/](firmware/) | RTOS + pluggable protocol drivers (stubs) |
| [companion/](companion/) | Python host app (stream, log, plugins) |

## Status

**Phase 0 skeleton** — documentation and empty module trees. No schematic spin, no production firmware.

Open decisions (see [docs/02-hardware-selection.md](docs/02-hardware-selection.md)):

- MCU: STM32H7 vs ESP32-S3
- Digital IO: FT2232H vs MCU bit-bang
- Logic capture: iCE40 FPGA vs MCU sampling

## Honest v1 envelope

| | Estimate |
|--|----------|
| Time | 4–8 months as a serious side project (digital + sub-GHz + NFC) |
| Cost | ~$300–800 in parts and PCB spins, before labor |
| Revisions | Budget **2–3** board spins |
| Team | Solo if you already do firmware *and* PCB; faster split EE / FW |

## Quick start (when bring-up exists)

```text
firmware/   — CMake or PlatformIO once an MCU is locked
companion/  — python -m pip install -e ".[dev]" && modhw --help
```

## License

Software (firmware + companion): [MIT](LICENSE). Hardware design files: intended [CERN-OHL-P-2.0](https://ohwr.org/project/cernohl) once real KiCad sources land — see [hardware/LICENSE](hardware/LICENSE).
