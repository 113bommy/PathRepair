from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
import math
import bisect
import random
from itertools import permutations, accumulate, combinations, product
import sys
import string
from bisect import bisect_left, bisect_right
from math import factorial, ceil, floor
from operator import mul
from functools import reduce


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

class Dinic():
    def __init__(self, source, sink):
        self.G = defaultdict(lambda:defaultdict(int))
        self.sink = sink
        self.source = source

    def add_edge(self, u, v, cap):
        self.G[u][v] = cap
        self.G[v][u] = 0

    def bfs(self):
        level = defaultdict(int)
        q = [self.source]
        level[self.source] = 1
        d = 1
        while q:
            if level[self.sink]:
                break
            qq = []
            d += 1
            for u in q:
                for v, cap in self.G[u].items():
                    if cap == 0:
                        continue
                    if level[v]:
                        continue
                    level[v] = d
                    qq += [v]
            q = qq
        self.level = level

    def dfs(self, u, f):
        if u == self.sink:
            return f
        for v, cap in self.iter[u]:
            if cap == 0 or self.level[v] != self.level[u] + 1:
                continue
            d = self.dfs(v, min(f, cap))
            if d:
                self.G[u][v] -= d
                self.G[v][u] += d
                return d
        return 0

    def max_flow(self):
        flow = 0
        while True:
            self.bfs()
            if self.level[self.sink] == 0:
                break
            self.iter = {u: iter(self.G[u].items()) for u in self.G}
            while True:
                f = self.dfs(self.source, INF)
                if f == 0:
                    break
                flow += f
        return flow

n = I()
A = LI()
score = 0
s = 0
t = n + 1
dinic = Dinic(s, t)
for i in range(1, n + 1):
    if A[i - 1] > 0:
        score += A[i - 1]
        dinic.add_edge(s, i, 0)
        dinic.add_edge(i, t, A[i - 1])
    else:
        dinic.add_edge(s, i, -A[i - 1])
        dinic.add_edge(i, t, 0)
    ret = i
    while ret <= n:
        ret += i
        dinic.add_edge(i, ret, INF)

print(score - dinic.max_flow())

