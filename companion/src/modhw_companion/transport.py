"""USB framed transport. Versioned packets: sync | ver | type | len | payload | crc."""

from __future__ import annotations


class TransportError(RuntimeError):
    pass


def open_device(_path: str | None = None) -> None:
    raise TransportError("USB transport is a Phase 2 stub")
