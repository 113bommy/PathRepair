n,m,k = map(int,input().split())
f = [[] for _ in range(n)]
g = [[] for _ in range(n)]
for _ in range(m):
    a,b = map(int,input().split())
    a,b = a-1,b-1
    f[a].append(b)
    f[b].append(a)
for _ in range(k):
    c,d = map(int,input().split())
    c,d = c-1,d-1
    g[c].append(d)
    g[d].append(c)
d = {}
parent = [-1]*n
seen = [False]*n
from collections import deque
for i in range(n):
    if seen[i]: continue
    stack = deque()
    d[i] = set([i])
    stack = [i]
    while stack:
        v = stack.pop()
        seen[v] = True
        parent[v]=i
        for nv in f[v]:
            if seen[nv]: continue
            d[i].add(nv)
            stack.append(nv)
ans = [0]*n
for i in range(n):
    group = d[parent[i]]
    sum = len(d[i]) -len(f[i]) - len(set(g[i])&group) -1
    ans[i]=sum
print(*ans)