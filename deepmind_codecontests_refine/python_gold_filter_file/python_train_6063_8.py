from heapq import heappush, heappop
import sys
readline = sys.stdin.readline

n, k = map(int, input().split())
adj = [[] for _ in range(n)]
deg = [0]*n

for u, v in (map(int, readline().split()) for _ in range(n-1)):
    adj[u-1].append(v-1)
    adj[v-1].append(u-1)
    deg[u-1] += 1
    deg[v-1] += 1

parent = [0]*n
subtree = [0]*n
nest = [0] + [-1]*(n-1)
order = []
stack = [0]

while stack:
    v = stack.pop()
    order.append(v)
    for dest in adj[v]:
        if nest[dest] > -1:
            continue
        parent[dest] = v
        nest[dest] = nest[v]+1
        stack.append(dest)

for v in reversed(order[1:]):
    subtree[parent[v]] += subtree[v] + 1

hq = sorted(((-nest[i], i) for i in range(1, n) if deg[i] == 1))
ans = 0
visited = [0]*n

for _ in range(k):
    happiness, v = heappop(hq)
    while visited[v]:
        happiness, v = heappop(hq)
    visited[v] = 1
    ans += -happiness
    par = parent[v]
    heappush(hq, (-(nest[par]-subtree[par]), par))

print(ans)
