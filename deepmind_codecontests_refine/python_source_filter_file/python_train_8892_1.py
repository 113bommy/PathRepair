#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys


def main():
    a, d =map(lambda x: int(float(x) * 10000), input().split(' '))
    ans = []

    for i in range(1, int(input()) + 1):
        t = d * i % (a * 4)
        if t <= a:
            y = 0
            x = t / 10000
        elif t <= a * 2:
            x = a / 10000
            y = (t - a) / 10000
        elif t <= a * 3:
            y = a / 10000
            x = (a - (t - a * 2)) / 10000
        elif t < a * 4:
            x = 0
            y = (a - (t - a * 3)) / 10000
        ans.append('{} {}'.format(x, y))

    print('\n'.join(ans))

if __name__ == '__main__':
    sys.exit(main())
