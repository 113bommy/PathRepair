#!/usr/bin/env python3
def solve():
    grid = [list(get(str)) for i in range(10)]

    s2 = set(list(map(tuple, '.XXXX X.XXX XX.XX XXX.X XXXX.'.split())))
    for i in range(10):
        for j in range(10):
            s = set()
            r, d, d1, d2 = None, None, None, None

            if j + 4 < 10:
                r = tuple([grid[i][j+x] for x in range(5)])

            if i + 4 < 10:
                d = tuple([grid[i+x][j] for x in range(5)])

            if i + 4 < 10 and j + 4 < 10:
                d1 = tuple([grid[i+x][j+x] for x in range(5)])

            if i - 4 >= 0 and j + 4 < 10:
                d2 = tuple([grid[i-x][j+x] for x in range(5)])

            s.add(r)
            s.add(d)
            s.add(d1)
            s.add(d2)

            if len(s2 & s) > 0:
                return 'YES'
    return 'NO'










_testcases = """
XX.XX.....
.....OOOO.
..........
..........
..........
..........
..........
..........
..........
..........

YES

XXOXX.....
OO.O......
..........
..........
..........
..........
..........
..........
..........
..........

NO

....X.....
...X......
..........
.X........
X.........
..........
..........
..........
..........
..........

YES

X.........
.X........
..X.......
..........
....X.....
..........
..........
..........
..........
..........

YES
""".strip()

# ======================= B O I L E R P L A T E ======================= #
# Practicality beats purity

import re
import sys
import math
import heapq
from heapq import heapify, heappop, heappush
import bisect
from bisect import bisect_left, bisect_right
import operator
from operator import itemgetter, attrgetter
import itertools
import collections

inf = float('inf')
sys.setrecursionlimit(10000)


def tree():
    return collections.defaultdict(tree)


def cache(func):  # Decorator for memoizing a function
    cache_dict = {}

    def _cached_func(*args, _get_cache=False):
        if _get_cache:
            return cache_dict
        if args in cache_dict:
            return cache_dict[args]
        cache_dict[args] = func(*args)
        return cache_dict[args]
    return _cached_func


def equal(x, y, epsilon=1e-6):
    # https://code.google.com/codejam/kickstart/resources/faq#real-number-behavior
    if -epsilon <= x - y <= epsilon:
        return True
    if -epsilon <= x <= epsilon or -epsilon <= y <= epsilon:
        return False
    return (-epsilon <= (x - y) / x <= epsilon or -epsilon <= (x - y) / y <= epsilon)


def get(_type):  # For easy input
    if type(_type) == list:
        if len(_type) == 1:
            _type = _type[0]
            return list(map(_type, input().strip().split()))
        else:
            return [_type[i](inp) for i, inp in enumerate(input().strip().split())]
    else:
        return _type(input().strip())

if __name__ == '__main__':
    print(solve())