#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""Codeforces Round #598 (Div. 3)

Problem C. Platforms Jumping

:author:         Kitchen Tong
:mail:    kctong529@gmail.com

Please feel free to contact me if you have any question
regarding the implementation below.
"""

__version__ = '0.2'
__date__ = '2019-11-24'


import sys


def solve(n, m, d, c):
    empty_count = m + 1
    platform_area = sum(c)
    empty_area = n - platform_area
    max_step = empty_area // empty_count
    residue = empty_area % empty_count
    if max_step + 1 > d:
        return None
    else:
        if residue > 0 and max_step + 2 > d:
            return None
        else:
            res = [0] * n
            curr = 0
            idx = 1
            while curr < n and idx <= m:
                curr += max_step
                if residue > 0:
                    curr += 1
                    residue -= 1
                for i in range(c[idx-1]):
                    res[curr] = idx
                    curr += 1
                idx += 1
            return res
    return None


def main(argv=None):
    n, m, d = map(int, input().split())
    c = list(map(int, input().split()))
    ans = solve(n, m, d, c)
    if not ans:
        print('NO')
    else:
        print('YES')
        print(' '.join(map(str, ans)))
    return 0


if __name__ == "__main__":
    STATUS = main()
    sys.exit(STATUS)
