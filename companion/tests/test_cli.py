from modhw_companion.cli import main


def test_plugins_lists_carve():
    assert main(["plugins"]) == 0
