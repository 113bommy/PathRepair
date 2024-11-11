#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""Codeforces Educational Round #63 (Div. 2)

Problem C. Alarm Clocks Everywhere

:author:         Kitchen Tong
:mail:    kctong529@gmail.com

Please feel free to contact me if you have any question
regarding the implementation below.
"""

__version__ = '0.3'
__date__ = '2019-04-23'

import sys


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def solve(n, m, x, p):
    y = x[:]
    for i in range(1, n):
        y[i] -= x[i-1]
    alarm_gcd = x[1]
    for i in range(2, n):
        alarm_gcd = gcd(alarm_gcd, y[i])
        if alarm_gcd == 1:
            break
    for j in range(m):
        if alarm_gcd % p[j] == 0:
            return j+1
    return -1

def main(argv=None):
    n, m = map(int, input().split())
    x = list(map(int, input().split()))
    p = list(map(int, input().split()))
    answer = solve(n, m, x, p)
    if answer > 0:
        print('YES')
        print('{0} {1}'.format(x[0], answer))
    else:
        print('NO')
    return 0

if __name__ == "__main__":
    STATUS = main()
    sys.exit(STATUS)

