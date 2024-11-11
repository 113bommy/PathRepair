N, = map(int, input().split())
M = 10**9+7
d = [set() for _ in range(N+1)]
from collections import deque
for _ in range(N-1):
    a, b = map(int, input().split())
    d[a].add(b)
    d[b].add(a)


stack = deque([1])
leafs = set()
p = [0 for _ in range(N+1)]
vs = set([1])
vv = list()
while stack:
    v = stack.popleft()
    vv.append(v)
    for u in d[v]:
        if u in vs:
            continue
        p[u] = v
        vs.add(u)
        stack.append(u)

dp1 = [-1 for _ in range(N+1)]
dp2 = [-1 for _ in range(N+1)]
for v in vv[::-1]:
    if len(d[v]) == 1 and v != 1:
        dp1[v] = 1
        dp2[v] = 1
        continue
    xx=yy=1
    for u in d[v]:
        if p[v] == u:
            continue
        xx = (xx * dp2[u])%M
        yy = (yy * (dp1[u] + dp2[u]))%M
    dp1[v] = xx
    dp2[v] = yy
print(dp1[1]+dp2[1])
