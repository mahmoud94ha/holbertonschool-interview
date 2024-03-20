#!/usr/bin/python3
"""Island Perimeter"""


def island_perimeter(grid):
    """island_perimeter funcyion."""
    value = 0
    rows = len(grid)
    cols = len(grid[0])

    def is_water(x, y):
        return x < 0 or y < 0 or x >= rows \
            or y >= cols or grid[x][y] == 0

    for col in range(rows):
        for row in range(cols):
            if grid[col][row] == 1:
                value += is_water(col - 1, row)
                value += is_water(col + 1, row)
                value += is_water(col, row + 1)
                value += is_water(col, row - 1)

    return value
