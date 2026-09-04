# Hardware

KiCad projects will live in `kicad/` (core board + one project per cape).

Until a pinout is frozen, do **not** start a combined PCB. Bring up ICs on breakouts (`prototypes/`).

| Cape | Directory | v1 |
|------|-----------|----|
| Core | [core/](core/) | yes |
| A Digital bus | [modules/a-digital-bus/](modules/a-digital-bus/) | yes |
| B Sub-GHz + NFC/LF | [modules/b-rf/](modules/b-rf/) | yes |
| C SDR | [modules/c-sdr/](modules/c-sdr/) | stretch |
| SCA / glitch | — | not v1 |
