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
mod = 1000000007


class LCA:
    def __init__(self,v,Edges,root=0):
        self.v=v
        self.Edges=Edges
        self.maxLog=18
        self.Parent=[[-1]*v for _ in range(self.maxLog+1)]
        self.Depth=[0]*v
        self.__bfs(root)
        for i in range(self.maxLog):
            for j in range(v):
                if self.Parent[i][j]!=-1:
                    self.Parent[i+1][j]=self.Parent[i][self.Parent[i][j]]
    def __bfs(self,root):
        Visited=[False]*self.v
        Visited[root]=True
        q=deque([root])
        while q:
            fr=q.pop()
            for to in self.Edges[fr]:
                if Visited[to]:
                    continue
                self.Parent[0][to]=fr
                self.Depth[to]=self.Depth[fr]+1
                Visited[to]=True
                q.append(to)
    def lca(self,a,b):
        if self.Depth[a]>self.Depth[b]:
            a,b=b,a
        for i in range(self.maxLog):
            if (self.Depth[b]-self.Depth[a])&(1<<i):
                b=self.Parent[i][b]
        if a==b:
            return b
        for i in reversed(range(self.maxLog-1)):
            if self.Parent[i][a]!=self.Parent[i][b]:
                a=self.Parent[i][a]
                b=self.Parent[i][b]
        return self.Parent[0][a]

# query先読みで、頂点ごとに、どの色の長さを求めるのか。
n, q = LI()
edge_dict = [{} for _ in range(n)]
for u, v, c, d in LIR(n - 1):
    edge_dict[u - 1][v - 1] = (c, d)
    edge_dict[v - 1][u - 1] = (c, d)

lca = LCA(n, edge_dict)
query = [[] for _ in range(n)]
for q_idx, (x, y, u, v) in enumerate(LIR(q)):
    query[u - 1] += [(q_idx, x, y, 1)]
    query[v - 1] += [(q_idx, x, y, 1)]
    query[lca.lca(u - 1, v - 1)] += [(q_idx, x, y, 0)]

def euler_tour(G, root=0):
    n = len(G)
    euler = []
    depth = [-1] * n
    depth[root] = 0
    dq = deque([root])
    dq2 = deque()
    visited = [0] * n
    while dq:
        u = dq.pop()
        euler += [(depth[u], u)]
        if visited[u]:
            continue
        for v in G[u]:
            if visited[v]:
                dq += [v]
            # [親頂点、子頂点、子頂点、。。。]と入れていく.その後連結
            else:
                depth[v] = depth[u] + 1
                dq += [v]
        dq.extend(dq2)
        dq2 = deque()
        visited[u] = 1
    return euler

dist = 0
color_len = [0] * n
color_cnt = [0] * n
ans = [0] * q
euler = euler_tour(edge_dict)
for i in range(1, len(euler)):
    dep = euler[i][0]
    c, d = edge_dict[euler[i - 1][1]][euler[i][1]]
    if euler[i - 1][0] < euler[i][0]:
        dist += d
        color_len[c] += d
        color_cnt[c] += 1
        for q_idx, x, y, flag in query[euler[i][1]]:
            if flag:
                ans[q_idx] += dist - color_len[x] + color_cnt[x] * y
            else:
                ans[q_idx] -= (dist - color_len[x] + color_cnt[x] * y) * 2
    else:
        dist -= d
        color_len[c] -= d
        color_cnt[c] -= 1


print(*ans, sep='\n')