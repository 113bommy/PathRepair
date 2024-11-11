# coding: utf-8
from functools import lru_cache

import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

@lru_cache(maxsize = None)
def f(v):
    if not arc[v]:
        return(0)
    return(max(f(nv) for nv in arc[v]) + 1)

n, m = map(int, input().split()) # 2 <= n <= 10^5, 1 <= m <= 10^5
arc = [[] for _ in range(n)]
for _ in range(m):
    x, y = map(int, input().split())
    arc[x - 1].append(y - 1)
print(max(f(v) for v in range(n)))
