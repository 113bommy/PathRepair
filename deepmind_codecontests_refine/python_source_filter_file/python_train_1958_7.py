import sys
sys.setrecursionlimit(10000000)
input = sys.stdin.readline
from math import log
from collections import deque

def solve():
    N, Q = map(int, input().split())
    es = [[] for i in range(N+1)]
    for i in range(N-1):
        u, v, c, d = map(int, input().split())
        es[u].append([v, c, d])
        es[v].append([u, c, d])
    LOG_N = int(log(N, 2))
    parent = [[-1] * (N+1) for i in range(LOG_N)]
    level = [None] * (N+1)
    level[1] = 0
    dq = deque()
    dq.append(1)
    while dq:
        v = dq.popleft()
        p = parent[0][v]
        lv = level[v]
        for u, c, d in es[v]:
            if u != p:
                parent[0][u] = v
                level[u] = lv + 1
                dq.append(u)
    for k in range(LOG_N-1):
        parentk = parent[k]
        for v in range(1, N+1):
            if parentk[v] < 0:
                parent[k+1][v] = -1
            else:
                parent[k+1][v] = parentk[parentk[v]]

    def lca(u, v):
        if level[u] > level[v]:
            u, v = v, u
        for k in range(LOG_N)[::-1]:
            if (level[v] - level[u]) >> k & 1:
                v = parent[k][v]
        if u == v:
            return u
        for k in range(LOG_N)[::-1]:
            if parent[k][u] != parent[k][v]:
                u, v = parent[k][u], parent[k][v]
        return parent[0][u]

    qs = [[] for i in range(N+1)]
    for i in range(Q):
        x, y, u, v = map(int, input().split())
        qs[u].append([i, x, y, 1])
        qs[v].append([i, x, y, 1])
        a = lca(u, v)
        qs[a].append([i, x, y, -2])
    ds = [0] * N
    cnt = [0] * N
    query = [0] * Q

    def EulerTour(v, p, d):
        for id, col, y, f in qs[v]:
            query[id] += f * (d + y * cnt[col] - ds[col])
        for u, c, _d in es[v]:
            if u != p:
                ds[c] += _d
                cnt[c] += 1
                EulerTour(u, v, d + _d)
                ds[c] -= _d
                cnt[c] -= 1

    EulerTour(1, -1, 0)
    for res in query:
        print(res)

if __name__ == '__main__':
    solve()
