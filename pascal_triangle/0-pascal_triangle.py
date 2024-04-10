#!/usr/bin/python3
"""Pascal's Triangle code"""


def pascal_triangle(n):
    """returns a list of lists of integers
        representing the Pascal’s triangle of n"""
    if n <= 0:
        return []

    tri = []
    for i in range(n):
        _row = [1]
        if tri:
            last_row = tri[-1]
            _row.extend([sum(pair) for pair in zip(last_row, last_row[1:])])
            _row.append(1)
        tri.append(_row)

    return tri
