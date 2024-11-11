from os import path
import sys, time
# mod = int(1e9 + 7)
# import re
from math import ceil, floor, gcd, log, log2, factorial, sqrt
from collections import defaultdict, Counter, OrderedDict, deque
from itertools import combinations, accumulate
# from string import ascii_lowercase ,ascii_uppercase
from bisect import *
from functools import reduce
from operator import mul

star = lambda x: print(' '.join(map(str, x)))
grid = lambda r: [lint() for i in range(r)]
INF = float('inf')
if (path.exists('input.txt')):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
import sys
from sys import stdin, stdout
from collections import *
from math import gcd, floor, ceil


def st():
    return list(stdin.readline().strip())


def inp():
    return int(stdin.readline())


def inlt():
    return list(map(int, stdin.readline().split()))


def invr():
    return map(int, stdin.readline().split())


def solve():
    n = inp()
    a = inlt()
    a.sort()
    if len(set(a)) == n:
        print('NO')
        return
    d = Counter(a)
    for i, j in d.items():
        if j % 2 == 0:
            print('YES')
            return
    print('NO')


t = 1
t = inp()
for _ in range(t):
    solve()
