# Companion app

Python host for USB sessions, capture logs, and **plugins** (firmware carving, metadata). Disassembly and heavy RE stay here (or in Ghidra/Binwalk), never on the MCU.

```bash
cd companion
python -m pip install -e ".[dev]"
modhw --help
modhw plugins
```

## Layout

| Module | Role |
|--------|------|
| `transport` | USB framed packets (stub) |
| `plugins.carve` | Binwalk-style carving hook (stub; call out to real tools) |

USB framing: see [docs/03-firmware.md](../docs/03-firmware.md).
