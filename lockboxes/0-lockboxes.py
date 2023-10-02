#!/usr/bin/python3
"""a method that determines if all the boxes can be opened"""


def canUnlockAll(boxes):
    """a method that determines if all the boxes can be opened"""
    complete = []
    keys = [0]

    for key in keys:
        if key not in complete:
            complete.append(key)
            for box in boxes[key]:
                if box < len(boxes) and box not in keys:
                    keys.append(box)

    if len(complete) == len(boxes):
        return True
    else:
        return False
