from __future__ import annotations

import argparse
import sys

from modhw_companion import __version__
from modhw_companion.plugins import list_plugins


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(
        prog="modhw",
        description="Companion CLI for the modhw core (skeleton).",
    )
    parser.add_argument("--version", action="version", version=__version__)
    sub = parser.add_subparsers(dest="cmd")

    sub.add_parser("plugins", help="List analysis plugins")
    ping = sub.add_parser("ping", help="Ping device over USB (not implemented)")
    ping.add_argument("--port", default="", help="Serial/USB path")

    args = parser.parse_args(argv)

    if args.cmd == "plugins":
        for name in list_plugins():
            print(name)
        return 0
    if args.cmd == "ping":
        print("ping: USB transport not implemented (skeleton)", file=sys.stderr)
        return 2

    parser.print_help()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
