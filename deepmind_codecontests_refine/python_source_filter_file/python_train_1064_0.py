
from collections import deque
El = []
Er = []
En = []
# g = defaultdict(lambda: [])
# N = int(input())
N = 10**5
g = [[] for _ in range(N+1)]
dist = [2**20 for _ in range(N+1)]
visited = [0] * (N+1)
# print(time.time() - start)
for num in range(N-1):
    # u, v = list(map(int, input().split()))
    u, v = num+1, num+2
    g[u].append(v)
    g[v].append(u)
    El.append(v)
    Er.append(u)
    En.append(num)
    # E.append( [v, u, num] )
# print(time.time() - start)

order = []
# dst(1)
s = deque([1])
while s:
    v = s.pop()
    visited[v] = 1
    order.append(v)
    for i in g[v]:
        if not visited[i]:
            s.append(i)
# print(time.time() - start)

for u in reversed(order):
    if len(g[u]) == 1:
        dist[u] = 0
    else:
        dist[u] = min([dist[u]] + [dist[v]+1 for v in g[u]])

# print(time.time() - start)
for u in order:
    if len(g[u]) == 1:
        dist[u] = 0
    else:
        prdist = dist[u]
        dist[u] = min([dist[u]] + [dist[v]+1 for v in g[u]])
        if dist[u] == prdist:
            break
# print(time.time() - start)

keys = [dist[el]+dist[er] for el, er in zip(El, Er)]
X = [(e, n) for n, e in enumerate(sorted(En, key=lambda x: keys[x]))]

# print(time.time() - start)

print('\n'.join([str(i) for _, i in sorted(X)]))
