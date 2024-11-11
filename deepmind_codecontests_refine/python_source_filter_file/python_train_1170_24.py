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

t = 1
# t = iinput()

for _ in range(iinput()):
    n,m,x,y=rinput()
    one = x
    two = min(2*x,y)
    mat = []
    for i in range(n):
        mat.append(input())
    ans = 0
    for i in range(n):
        j = 0
        while j<m:
            tiles = 0
            count = 0
            while j<m and mat[i][j]=='.': 
                j+=1
                count+=1
            if count%2==0:
                ans += (count//2)*y
            else:
                ans += (count//2)*y+x
            if count==0:
                j+=1
    print(ans)