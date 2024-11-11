from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
import math
import bisect
import random
from itertools import permutations, accumulate, combinations, product
import sys
import string
from bisect import bisect_left, bisect_right
from math import factorial, ceil, floor, cos, radians, pi, sin
from operator import mul
from functools import reduce
from operator import mul


sys.setrecursionlimit(2147483647)
INF = 10 ** 13
def LI(): return list(map(int, sys.stdin.buffer.readline().split()))
def I(): return int(sys.stdin.buffer.readline())
def LS(): return sys.stdin.buffer.readline().rstrip().decode('utf-8').split()
def S(): return sys.stdin.buffer.readline().rstrip().decode('utf-8')
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def LSR(n): return [LS() for i in range(n)]
def SRL(n): return [list(S()) for i in range(n)]
def MSRL(n): return [[int(j) for j in list(S())] for i in range(n)]
mod = 10 ** 9 + 7

t = I()
for _ in range(t):
    n = I()
    ans = 0
    q1 = []
    q2 = []
    L1 = []
    L2 = []
    for _ in range(n):
        k, l, r = LI()
        if l > r:
            L1 += [(k, l - r)]
        else:
            L2 += [(n - k + 1, r - l)]
        ans += min(l, r)
    L1.sort()
    L2.sort()
    for ki, d in L1:
        heappush(q1, d)
        if len(q1) > ki:
            heappop(q1)
    for ki, d in L2:
        heappush(q2, d)
        if len(q2) > ki:
            heappop(q2)
    ans += sum(q1) + sum(q2)
    print(ans)









