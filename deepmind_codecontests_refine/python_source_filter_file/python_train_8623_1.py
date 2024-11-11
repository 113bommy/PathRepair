from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
import math
import bisect
import random
from itertools import permutations, accumulate, combinations, product
import sys
from pprint import pprint
from copy import deepcopy
import string
from bisect import bisect_left, bisect_right
from math import factorial, ceil, floor
from operator import mul
from functools import reduce
from pprint import pprint


sys.setrecursionlimit(2147483647)
INF = 10 ** 20
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
mod = 1000000007


class Segtree:
    def __init__(self, A, ide_ele, segfunc, initialize=True):
        self.n = len(A)
        self.size = 2 ** (self.n - 1).bit_length()
        self.ide_ele = ide_ele
        self.segfunc = segfunc
        if initialize:
            self.data = [ide_ele] * self.size + A + [ide_ele] * (self.size - self.n)
            for i in range(self.size - 1, 0, -1):
                self.data[i] = self.segfunc(self.data[2 * i], self.data[2 * i + 1])
        else:
            self.data = [ide_ele] * (2 * self.size)

    def update(self, k, x):
        k += self.size
        self.data[k] = x
        while k > 0:
            k = k >> 1
            self.data[k] = self.segfunc(self.data[2 * k], self.data[2 * k + 1])

    def query(self, l, r):
        L, R = l + self.size, r + self.size
        s = self.ide_ele
        while L < R:
            if R & 1:
                R -= 1
                s = self.segfunc(s, self.data[R])
            if L & 1:
                s = self.segfunc(s, self.data[L])
                L += 1
            L >>= 1
            R >>= 1
        return s

n = I()
P = LI()
D = {P[i]: i for i in range(n)}
p_even = [P[i] if not i & 1 else INF for i in range(n)]
p_odd = [P[i] if i & 1 else INF for i in range(n)]
st_even = Segtree(p_even, INF, min)
st_odd = Segtree(p_odd, INF, min)
hq = [(st_even.query(0, n), 0, n)]
ans = []
for i in range(n // 2):
    v1, l, r = heappop(hq)
    p1 = D[v1]
    if not l & 1:
        st1, st2 = st_odd, st_even
    else:
        st1, st2 = st_even, st_odd
    v2 = st1.query(p1, r)
    p2 = D[v2]
    st2.update(p1, INF)
    st1.update(p2, INF)
    if l != p1:
        heappush(hq, (st2.query(l, p1), l, p1))
    if p1 + 1 != p2:
        heappush(hq, (st1.query(p1 + 1, p2), p1 + 1, p2))
    if p2 + 1 != r:
        heappush(hq, (st2.query(p2 + 1, r), p2 + 1, r))
    ans += [v1, v2]


print(*ans)


