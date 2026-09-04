# System architecture

## Physical split

```
                    USB 2.0 (host / CDC + optional HS)
                         │
┌────────────────────────┴─────────────────────────┐
│ CORE                                             │
│  MCU ──┬── Display + encoder/touch               │
│        ├── microSD                               │
│        ├── PMIC / 18650 charge + boost           │
│        ├── Cape connector (power, SPI, I2C,      │
│        │     high-speed parallel, interrupts)    │
│        └── Optional: onboard USB PHY / HS mux    │
└────────┬───────────────┬───────────────┬─────────┘
         │               │               │
    ┌────▼────┐     ┌────▼────┐     ┌────▼────┐
    │ Mod A   │     │ Mod B   │     │ Mod C   │
    │ Digital │     │ RF      │     │ SDR     │
    │ + FPGA  │     │ CC1101/ │     │ stretch │
    │ capture │     │ Si4463  │     │         │
    │         │     │ PN532   │     │         │
    │         │     │ LF coil │     │         │
    └─────────┘     └─────────┘     └─────────┘
```

## Cape interconnect (draft — not a pinout yet)

Minimum signals to freeze **before** schematic:

- 3V3 / 5V / GND / cape detect ID (I2C EEPROM or resistor ID)
- Shared I2C (UI expanders, ID, slow sensors)
- SPI or QSPI to FPGA / RF
- UART debug from core
- Several GPIO with 5 V-tolerant or level-shifted field IO **only on Module A**
- High-speed: FPGA → MCU parallel or LVDS for capture streaming
- RF modules: keep analog/RF ground strategy on the cape, not across the whole core

Do **not** run unbuffered JTAG/SPI field pins through the core MCU without protection (ESD, series R, optional buffers).

## Software split

| Where | Responsibility |
|-------|----------------|
| Core firmware | RTOS, UI, storage, USB gadget, cape discovery, capture DMA |
| Protocol modules | One driver per bus/RF family; no god-object firmware |
| FPGA bitstream | Logic analyzer + optional JTAG TAP assist |
| Companion | Session logs, firmware carving plugins, hand-off to Ghidra/Binwalk-class tools |

## Data path (capture)

1. Pins → protection → FPGA (or MCU TIM/DMA fallback)
2. FPGA packs samples → USB HS or µSD
3. Companion records `.sr` / raw + metadata (sigrok-friendly target)

## Pin identity scan (Module A)

A **JTAGulator-equivalent** routine is a first-class firmware feature: brute-force assignment of unknown header pins against a known protocol set, on **authorized** targets only. Implementation lives under `firmware/src/protocols/`; it is not a substitute for reading the datasheet.
