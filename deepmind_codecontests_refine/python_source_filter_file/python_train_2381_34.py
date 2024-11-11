# -*- coding: utf-8 -*-

import sys
import os


for s in sys.stdin:
    a, b, c, d, e, f = list(map(int, s.split()))

    delta = a * e - b * d
    if delta == 0:
        break
    else:
        x = 1 / delta * (e * c - b * f)
        y = 1 / delta * (-d * c + a * f)
        print('{:.3f} {:.3f}'.format(x, y))