"""Hook for firmware carving. Call Binwalk (or similar) from the host; do not reimplement it here."""

PLUGIN_NAME = "carve"


def carve(_path: str) -> None:
    raise NotImplementedError(
        "Wire this plugin to an installed carver (e.g. binwalk) on the host"
    )
