#!/usr/bin/python3
""" utf8_validation """


def validUTF8(data):
    """ determines if a given data set represents
    a valid UTF-8 encoding """
    _bytes = 0

    for b in data:
        if _bytes == 0:
            if (b & 0x80) == 0:
                continue

            elif (b & 0xE0) == 0xC0:
                _bytes = 1
            elif (b & 0xF0) == 0xE0:
                _bytes = 2
            elif (b & 0xF8) == 0xF0:
                _bytes = 3
            else:
                return False

        else:
            if (b & 0xC0) != 0x80:
                return False
            _bytes -= 1

    return _bytes == 0
