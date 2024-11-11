
from collections import defaultdict
import sys

sys.setrecursionlimit(10**6)


N = int(input())
g = [set() for _ in range(N+1)]

for x, y in [map(int, input().split()) for _ in range(N-1)]:
    g[x].add(y)
    g[y].add(x)

M = 10**9 + 7


def dfs(u, p):
    w = 1
    b = 1
    for v in g[u]:
        if p == v:
            continue
        wn, bn = dfs(v, u)
        w *= wn + bn
        b *= wn
        w %= M
        b %= M
    return w, b
print(sum(dfs(1, -1))%M)
