#!/usr/bin/python3
""" utf8_validation """


def validUTF8(data):
    """ determines if a given data set represents
    a valid UTF-8 encoding """
    _bytes = 0

    for b in data:
        if _bytes == 0:
            if (b >> 7) == 0:
                continue

            elif (b >> 5) == 0b110:
                _bytes = 1
            elif (b >> 4) == 0b1110:
                _bytes = 2
            elif (b >> 3) == 0b11110:
                _bytes = 3
            else:
                return False

        else:
            if (b >> 6) != 0b10:
                return False

            _bytes -= 1

    return _bytes == 0
