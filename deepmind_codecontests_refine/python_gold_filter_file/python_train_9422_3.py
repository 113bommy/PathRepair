#!/usr/bin/env python3
import collections, itertools, functools, math

def solve():
    n = int(input())
    p = map(int, input().split())
    pos = [(p, i) for i, p in enumerate(p)]
    pos.sort()

    longest = 1
    seq = 1
    for i in range(1, n):
        if pos[i-1][1] < pos[i][1]:
            seq += 1
        else:
            seq = 1
        longest = max(longest, seq)
    return n - longest


if __name__ == '__main__':
    print(solve())

