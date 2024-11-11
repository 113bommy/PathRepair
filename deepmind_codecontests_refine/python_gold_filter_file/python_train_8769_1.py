from fractions import Fraction
import bisect
import os
from collections import Counter
import bisect
from collections import defaultdict
import math
import random
import heapq as hq
from math import sqrt
import sys
from functools import reduce, cmp_to_key
from collections import deque
import threading
from itertools import combinations
from io import BytesIO, IOBase
from itertools import accumulate


# sys.setrecursionlimit(200000)
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


def input():
    return sys.stdin.readline().strip()


def iinput():
    return int(input())


def tinput():
    return input().split()


def rinput():
    return map(int, tinput())


def rlinput():
    return list(rinput())


mod = int(1e9)+7


def factors(n):
    return set(reduce(list.__add__,
                      ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))


# ----------------------------------------------------
# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')
# mx=2*int(1e9)+1
# fact = [0]*(mx+1)
t = 1
# t = iinput()


def ss(n):
    return n*(n+1)//2


for _ in range(t):
    n, x = rinput()
    a = rlinput()
    a = 2*a
    ans = 0
    pref = list(accumulate(a))
    prefn = [0]*(2*n)
    prefn[0] = a[0]*(a[0]+1)//2
    for i in range(1, 2*n):
        prefn[i] = prefn[i-1]+a[i]*(a[i]+1)//2
    # print(pref)
    # print(prefn)
    for i in range(n, 2*n):
        if a[i] >= x:
            ans = max(ans, ss(a[i])-ss(a[i]-x))
            # print(i, ans, 'up')
        else:
            val = pref[i]-x
            newans = 0
            idx = bisect.bisect(pref, val)
            newans += prefn[i]-prefn[idx]
            want = x-pref[i]+pref[idx]
            # print(a[idx],a[idx]-want)
            newans += ss(a[idx])-ss(a[idx]-want)
            ans = max(ans, newans)
            # print(i, idx, ans, 'down')
    print(ans)
