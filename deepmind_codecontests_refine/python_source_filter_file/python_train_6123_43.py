from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
from bisect import bisect_right, bisect_left
import random
from itertools import permutations, accumulate, combinations, product
import sys
import string
from bisect import bisect_left, bisect_right
from math import factorial, ceil, floor, gamma, log
from operator import mul
from functools import reduce
from copy import deepcopy

sys.setrecursionlimit(2147483647)
INF = 10 ** 20
def LI(): return list(map(int, sys.stdin.readline().split()))
def I(): return int(sys.stdin.readline())
def LS(): return sys.stdin.buffer.readline().rstrip().split()
def S(): return sys.stdin.buffer.readline().rstrip().decode('utf-8')
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): pass
def LSR(n): return [LS() for i in range(n)]
def SRL(n): return [list(S()) for i in range(n)]
def MSRL(n): return [[int(j) for j in list(S())] for i in range(n)]
mod = 10 ** 9 + 7

n = I()
G = [[] for _ in range(n)]
for _ in range(n - 1):
    x, y = LI()
    G[x - 1] += [y - 1]
    G[y - 1] += [x - 1]


par = [-1] * n
def f(u):
    b, w = 1, 1
    for v in G[u]:
        if v == par[u]:
            continue
        par[v] = u
        cb, cw = f(v)
        b = b * cw % mod
        w = w * (cw + cb)
    return b, w

bb, ww = f(0)
print((bb + ww) % mod)