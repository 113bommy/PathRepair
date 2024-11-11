from collections import deque
INF = 10**9

N, M = map(int,input().split())

G = [[] for _ in range(3*N)]
for _ in range(M):
    u, v = map(int,input().split())
    u, v = u-1, v-1

    G[u].append(v+N)
    G[u+N].append(v+2*N)
    G[u+2*N].append(v)

s, t = map(int,input().split())
s, t = s-1, t-1

dist = [INF] * (3*N)
dist[s] = 0

Q = deque([s])
while len(Q) > 0:
    u = Q.pop()
    for v in G[u]:
        if dist[v] == INF:
            dist[v] = dist[u] + 1
            Q.append(v)

if dist[t] == INF:
    print(-1)
else: 
    print(dist[t] // 3)