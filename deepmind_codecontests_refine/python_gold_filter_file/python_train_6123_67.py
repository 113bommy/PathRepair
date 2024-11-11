from collections import deque

n = int(input())
mod = 10 ** 9 + 7
graph = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

start = 1

que = deque([1])
par = [-1] * (n + 1)
topo = []
while que:
    v = que.popleft()
    topo.append(v)
    for u in graph[v]:
        if par[v] == u:
            continue
        par[u] = v
        que.append(u)

dpb = [0] * (n + 1)
dpw = [0] * (n + 1)

for i in topo[::-1]:
    dpb[i] = 1
    dpw[i] = 1
    for j in graph[i]:
        if j == par[i]:
            continue
        dpb[i] *= dpw[j]
        dpw[i] *= dpb[j] + dpw[j]
    dpw[i] %= mod
    dpb[i] %= mod

print((dpw[1] + dpb[1]) % mod)
