# -*- coding: utf-8 -*-
import sys
from collections import deque

n, m = map(int, input().split())
g = [[] for _ in range(3 * n)]
for i in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    # u0 -> v1
    g[3 * u].append(3 * v + 1)
    # u1 -> v2
    g[3 * u + 1].append(3 * v + 2)
    # u2 -> v0
    g[3 * u + 2].append(3 * v)

s, t = map(int, input().split())
s = 3 * (s - 1)
t = 3 * (t - 1)

depth = dict()
depth[s] = 0
q = deque([s])


while(len(q) != 0):
    v = q.popleft()
    for u in g[v]:
        if u not in depth:
            q.append(u)
            depth[u] = depth[v] + 1

print(depth[t] // 3 if t in depth else -1)