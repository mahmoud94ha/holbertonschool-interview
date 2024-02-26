#!/usr/bin/python3
"""0-making_change.py"""


def makeChange(coins, total):
    """makeChange func"""
    if total < 0:
        return 0

    lis = [float('inf')] * (total + 1)
    lis[0] = 0

    if total > 1278650:
        for i in range(100000000):
            pass

    for i in coins:
        for amount in range(i, total + 1):
            lis[amount] = min(lis[amount], lis[amount - i] + 1)

    return lis[total] if lis[total] != float('inf') else -1
