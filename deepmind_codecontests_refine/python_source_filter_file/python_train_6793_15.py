import sys
import math
from math import factorial, inf, gcd, sqrt
from heapq import *
from functools import *
from itertools import *
from collections import *
from typing import *
from bisect import *
import random
sys.setrecursionlimit(10**5)


def rarray():
    return [int(i) for i in input().split()]


t = 1
# t = int(input())
for ii in range(t):
    n, p = rarray()
    a = rarray()
    a.sort()
    al, ar = a[0], a[p - 1] - 1
    for i in range(n):
        l, r = al + i, ar + i
        if i + p < n:
            r = min(r, a[i + p] - 1)
        if i + 1 < n:
            l = max(l, a[i + 1] - 1)
        al = max(al, l - i)
        ar = min(ar, r - i)
    if al > ar:
        print(0)
        print()
        continue
    print(ar - al + 1)
    for i in range(al, ar + 1):
        print(i, end=' ')
    print()