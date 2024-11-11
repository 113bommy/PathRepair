# Link: http://codeforces.com/contest/1006/problem/C
# py3

from __future__ import print_function
import sys
import math
import os.path
import random
from copy import deepcopy
from functools import reduce


from collections import Counter, ChainMap, defaultdict
from itertools import cycle, chain
from queue import Queue, PriorityQueue
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, nlargest, nsmallest
import bisect

from statistics import mean, mode, median, median_low, median_high


# CONFIG
sys.setrecursionlimit(10**9)

# LOG 
def log(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


# INPUT
def ni():
    return map(int, input().split())


def nio(offset):
    return map(lambda x: int(x) + offset, input().split())


def nia():
    return list(map(int, input().split()))


# CONVERT
def toString(aList, sep=" "):
    return sep.join(str(x) for x in aList)


def toMapInvertIndex(aList):
    return {k: v for v, k in enumerate(aList)}


# SORT
def sortId(arr):
    return sorted(range(len(arr)), key=lambda k: arr[k])


# MAIN

n, = ni()
d = [0] + nia() + [0]

sleft = [0]*(n+2)
for i in range(1,n+1):
    sleft[i] = d[i] + sleft[i-1]

sright = [0]*(n+2)
for i in range(n,0,-1):
    sright[i] = d[i] + sright[i+1]

log(sleft)
log(sright)

def testR(ix):
    sR = sright[ix]
    pos = bisect.bisect_left(sleft,sR,0,ix)
    return sleft[pos] == sR

x = 0
for i in range(1, n+2):
    if testR(i):
        x = i
        break
print(sright[x])