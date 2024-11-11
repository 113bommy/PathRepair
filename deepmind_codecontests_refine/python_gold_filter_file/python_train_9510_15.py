import re
import sys
from bisect import bisect, bisect_left, insort, insort_left
from collections import Counter, defaultdict, deque
from copy import deepcopy
from decimal import Decimal
from itertools import (
    accumulate, combinations, combinations_with_replacement, groupby,
    permutations, product)
from math import (acos, asin, atan, ceil, cos, degrees, factorial, gcd, hypot,
                  log2, pi, radians, sin, sqrt, tan)
from operator import itemgetter, mul
from string import ascii_lowercase, ascii_uppercase, digits


def inp():
    return(int(input()))


def inlist():
    return(list(map(int, input().split())))


def instr():
    s = input()
    return(list(s[:len(s)]))


def invr():
    return(map(int, input().split()))


n = inp()

a = inlist()

min1 = 1000000001
min2 = min1+1
ind = 0
for i in range(n):
    if a[i] < min1:
        min1 = a[i]
        ind = i
    elif a[i] < min2 and a[i] >= min1:
        min2 = a[i]
if min1 == min2:
    print("Still Rozdil")
else:
    print(ind + 1)
