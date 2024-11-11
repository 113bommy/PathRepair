#!/usr/bin/env python3
from sys import stdin
import bisect


def solve(tc):
    n, k, l = map(int, stdin.readline().split())
    li = list(map(int, stdin.readline().split()))
    li.sort()

    p = bisect.bisect_right(li, li[0] + l)
    if p < n:
        print(0)
        return

    res = 0
    pp = 0
    rem = p - n
    while pp < p:
        res += li[pp]
        if rem > 0:
            mod = min(k-1, rem)
            pp += mod
            rem -= mod
        pp += 1
    print(res)


tc = 1
solve(tc)