import sys
input = sys.stdin.readline
inputi = lambda: map(int, input().split())
from math import *
from bisect import *
from functools import reduce, lru_cache
from collections import Counter, defaultdict


k = int(input())
if k == 0:
    print(1)
    print(1)
else:
    d = k.bit_length()
    t = (1 << d + 1) - 1
    l = [[t, k, 0], [1 << d, t, k]]
    t = 1 << d + 1
    print(2, 3)
    print(*l[0])
    print(*l[1])





