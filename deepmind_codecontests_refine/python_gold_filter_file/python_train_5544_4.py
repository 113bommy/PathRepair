import sys
from collections import deque

n, m, k = map(int, input().split())
e = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    e[a].append(b)
    e[b].append(a)

def get_root():
    q = deque([1])
    par = [0] * (n+1)
    par[1] = 1
    while q:
        u = q.popleft()
        for v in e[u]:
            if v == par[u]:
                continue
            if par[v] > 0:
                return u
            else:
                par[v] = u
                q.append(v)
    return 1
root = get_root()

def print_cycle(u, v, par):
    up, vp = [], []
    while u != root:
        up.append(u)
        u = par[u]
    while v != root:
        vp.append(v)
        v = par[v]
    cy = up + [root] + list(reversed(vp))
    print(2)
    print(len(cy))
    print(*cy)
    exit()

q = deque([root])
par = [0]*(n+1); par[root] = root
dep = [0]*(n+1); dep[1] = 1
col0, col1 = [], []
while q:
    u = q.popleft()
    if dep[u] % 2:
        col0.append(u)
    else:
        col1.append(u)
    if len(col0) + len(col1) == k:
        break
    for v in e[u]:
        if v == par[u]:
            continue
        if par[v] > 0:
            if dep[u]+dep[v]-1 <= k:
                print_cycle(u, v, par)
        else:                
            par[v] = u
            dep[v] = dep[u] + 1
            q.append(v)
res = col0 if len(col0) >= len(col1) else col1
res = [res[i] for i in range((k+1)//2)]
print(1)
print(*res)
