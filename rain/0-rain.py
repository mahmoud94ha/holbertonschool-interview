#!/usr/bin/python3
"""
Useless comment
"""


def rain(walls):
    """
    Useless comment
    :param walls: Walls
    :return: Water
    """
    if len(walls) == 0:
        return 0

    left_max = [walls[0]] + [max(walls[: i + 1]) for i in range(1, len(walls))]
    right_max = [max(walls[i:]) for i in range(len(walls) - 2, -1, -1)][::-1]
    right_max += [walls[-1]]

    water = 0
    for i, height in enumerate(walls):
        water += min(left_max[i], right_max[i]) - height

    return water