from operator import itemgetter
from collections import deque


class UnionFind:
    def __init__(self, n):
        self.parent = [-1] * n
        self.cnt = n

    def root(self, x):
        """頂点xの根を求める"""
        if self.parent[x] < 0:
            return x
        else:
            self.parent[x] = self.root(self.parent[x])
            return self.parent[x]

    def merge(self, x, y):
        """頂点xを含む集合と頂点y含む集合を結合する"""
        x = self.root(x)
        y = self.root(y)
        if x != y:
            if self.parent[x] > self.parent[y]:
                x, y = y, x
            self.parent[x] += self.parent[y]
            self.parent[y] = x
            self.cnt -= 1

    def is_same(self, x, y):
        """頂点xと頂点yが同じ集合に属するかどうかを返す"""
        return self.root(x) == self.root(y)

    def get_size(self, x):
        return -self.parent[self.root(x)]


n, m = map(int, input().split())
x = list(map(int, input().split()))
info = [list(map(int, input().split()))+[i] for i in range(m)]

graph = [[] for i in range(n)]
for i in range(m):
    a, b, cost, j = info[i]
    a -= 1
    b -= 1
    graph[a].append((b, cost, j))
    graph[b].append((a, cost, j))

uf = UnionFind(n)
for i in range(n):
    uf.parent[i] = -x[i]

candidate = set([])
info = sorted(info, key = itemgetter(2))
for i in range(m):
    a, b, cost, j = info[i]
    a -= 1
    b -= 1
    if not uf.is_same(a, b):
        uf.merge(a, b)
    if uf.get_size(a) > cost:
        candidate.add(j)

ans = 0
used = [False] * m
info = sorted(info, key = itemgetter(2), reverse = True)
for i in range(m):
    a, b, cost, j = info[i]
    a -= 1
    b -= 1
    if used[j]:
        continue
    if j in candidate:
        used[j] = True
        q = deque([a, b])
        while q:
            pos = q.pop()
            for next_pos, tmp_cost, k in graph[pos]:
                if not used[k] and tmp_cost <= cost:
                    used[k] = True
                    q.append(next_pos)
    else:
        ans += 1

print(ans)
