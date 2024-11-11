"""
Codeforces Round #331  (Div. 2)

Problem 596 B Wilbur and Array

@author yamaton
@date 2015-11-15
"""

import itertools as it
import functools
import operator
import collections
import math
import sys


def solve(xs, n):
    return xs[0] + sum(abs(b-a) for (a, b) in zip(xs, xs[1:]))


# def p(*args, **kwargs):
#     return print(*args, file=sys.stderr, **kwargs)


def main():
    n = int(input())
    xs = [int(_c) for _c in input().strip().split()]
    assert len(xs) == n

    result = solve(xs, n)
    print(result)


if __name__ == '__main__':
    main()
