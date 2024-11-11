import heapq as hp
import collections
import bisect
import math
import re


def unpack(func=int):
    return map(func, input().split())


def l_unpack(func=int):
    """list unpack"""
    return list(map(func, input().split()))


def s_unpack(func=int):
    """sorted list unpack"""
    return sorted(map(func, input().split()))


def ml_unpack(n):  # multiple line unpack
    """list of n integers passed on n line, one on each"""
    return [int(input()) for i in range(n)]


def range_n():
    return range(int(input()))


def getint():
    return int(input())


def counter(a):
    d = {}
    for x in a:
        if x in d:
            d[x] += 1
        else:
            d[x] = 1
    return d


def main():
    #    MAX =
    # => MAX = 77459 (<100000)

    cards = lambda height: (3 * height + 1) * height // 2
    height = lambda card: int((math.sqrt(1 + 24 * card) - 1) / 2)
    for _ in range_n():
        n = getint()
        ans = 0
        while n > 1:
            n -= cards(height(n))
            ans += 1
        print(ans)


main()
