#!/usr/bin/env python3
"""
Codeforces Round #317 (Div. 2)

Problem 572 A. Arrays

@author yamaton
@date 2015-08-23
"""

import itertools as it
import functools
import operator
import collections
import math
import sys


def solve(xs, ys, k, m):
    return max(xs[-k:]) < min(ys[:m])


def print_stderr(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def tf_to_yn(tf):
    return 'YES' if tf else 'NO'


def main():
    [na, nb] = [int(i) for i in input().strip().split()]
    [k, m] = [int(i) for i in input().strip().split()]    
    xs = [int(i) for i in input().strip().split()]
    ys = [int(i) for i in input().strip().split()]
    assert len(xs) == na
    assert len(ys) == nb

    result = tf_to_yn(solve(xs, ys, k, m))
    print(result)


if __name__ == '__main__':
    main()
