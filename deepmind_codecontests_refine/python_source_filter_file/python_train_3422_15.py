# -*- coding: utf-8 -*-

import sys
import os
from math import sin, cos
import math

alphabet = 'abcdefghijklmnopqrstuvwxyz'


def rotate_char(c, num):
    if c == ' ' or c == '.' or c == '\n':
        return c

    n = ord(c) + num
    if n > 122:
        n -= 26
    return chr(n)

def rotate_string(s, num):
    ret = []
    for c in s:
        new_c = rotate_char(c, num)
        ret.append(new_c)
    return ''.join(ret)

for s in sys.stdin:
    for i in range(1, 26):
        rotated = rotate_string(s, i)
        if 'the' in rotated or 'this' in rotated or 'that' in rotated:
            print(rotated, end='')
            break