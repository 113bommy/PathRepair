from heapq import heappop, heappush

N, M = map(int, input().split())
adj = [[] for _ in range(N)]

for i in range(N-1):
    adj[i+1].append((i,0))

for i in range(M):
    L, R, C = map(int, input().split())
    adj[L-1].append((R-1,C))

q = [] # 始点のコストとindex
heappush(q,0)
INF = 10**12
d = [INF] * N
d[0] = 0

while len(q) > 0:
    u = heappop(q)
    for v in adj[u]:
        tmp = d[u] + v[1]
        if tmp < d[v[0]]:
            d[v[0]] = tmp
            heappush(q, v[0])

print(d[N-1]) if d[N-1] < INF else print(-1)