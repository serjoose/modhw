# Module B — Sub-GHz + NFC/RFID

Replacement class: Flipper / YARD Stick / Proxmark-**lite** (portable, not a full Proxmark desktop).

## Blocks

- Sub-GHz: CC1101 **or** Si4463
- HF NFC: PN532 (or successor) over SPI/I2C/UART
- LF (~125 kHz): discrete coil + frontend (do not pretend this is a full Proxmark analog front end on spin 1)

## Layout

RF is its own cape. Keep matching networks, ground stitching, and PA/LNA away from Module A switching.

## Regulatory

Transmit only as allowed in your region. Prefer RX and standards-compliant NFC listener/reader modes in default firmware.
