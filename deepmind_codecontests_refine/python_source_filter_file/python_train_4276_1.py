import sys
import collections

class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n+1)]
        self.rank = [0] * (n+1)

    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if self.rank[x] < self.rank[y]:
            self.par[x] = y
        else:
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def are_same(self, x, y):
        return self.find(x) == self.find(y)

Edge = collections.namedtuple('Edge', ['s', 't', 'cost'])
    
V, E = map(int, sys.stdin.readline().split())
edges = sorted([Edge(*map(int, line.split())) for line in sys.stdin], key=lambda e: e.cost)
uf = UnionFind(V)
min_cost = 0
for edge in edges:
    if not uf.are_same(edge.s, edge.t):
        uf.union(edge.s, edge.t)
        min_cost += edge.cost
min_cost
