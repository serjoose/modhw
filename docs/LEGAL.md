# Legal & intended use

modhw is a **lab instrument** for people working on **their own** electronics, classroom kits, and **authorized** security research.

## In scope

- Devices you own
- Hardware you have written permission to test
- Public CTF / lab kits sold for that purpose
- Comparing your tool’s output to reference tools on **known-good** boards (dev kits, flash chips you bought)

## Out of scope (do not use this project for)

- Accessing systems or radios you are not authorized to use
- Bypassing locks, payment systems, vehicle immobilizers, or access control you do not own
- Unlicensed RF transmission outside what your local regulator allows
- Anything that would be unauthorized interception, fraud, or computer misuse under your jurisdiction

Firmware and companion **stubs** in this repo are placeholders. They are not an attack playbook.

## RF

Sub-GHz, NFC, and any future SDR cape must be used in accordance with local spectrum rules (power, band, duty cycle, licensed vs unlicensed). Default firmware should prefer **receive / analyze** and tightly gated, standards-compliant transmit where legally required.

## Data

Do not commit dumps, captures, or credentials from real products to git. `.gitignore` already excludes `captures/` and `dumps/`.
