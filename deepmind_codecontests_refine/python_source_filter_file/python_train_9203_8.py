import operator as op
import re
import sys
from bisect import bisect, bisect_left, insort, insort_left
from collections import Counter, defaultdict, deque
from copy import deepcopy
from decimal import Decimal
from functools import reduce
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


def def_value():
    return 0


# For getting input from input.txt file
#sys.stdin = open('input.txt', 'r')
# Printing the Output to output.txt file
# sys.stdout = open('output.txt', 'w')
n = inp()
a = []
for i in range(4):
    a.append(inlist()+[i+1])

a = sorted(a, key=lambda d: min(d[0], d[1]+min(d[2], d[3])))

b = a[0]

if min(b[0], b[1]) + min(b[2], b[3]) > n:
    print(-1)
else:
    c1 = min(b[0], b[1])
    c2 = n - c1
    print(b[4], c1, c2)
