INF = 10 ** 18

N, M = map(int, input().split())

G = [[] for _ in range(N + 1)]
for _ in range(M):
    L, R, C = map(int, input().split())
    G[L].append([C, R])
    G[R].append([C, L])

for i in range(1, N):
    G[i + 1].append([0, i])

d = [INF] * (N + 1)

def dijkstra(s):
    import heapq
    d[s] = 0
    pque = []
    heapq.heappush(pque, [0, s])
    
    while pque:
        p = heapq.heappop(pque)
        v = p[1]
        if d[v] < p[0]:
            continue
        for i in range(len(G[v])):
            e = G[v][i]
            if d[e[1]] > d[v] + e[0]:
                d[e[1]] = d[v] + e[0]
                heapq.heappush(pque, [d[e[1]], e[1]])

dijkstra(1)

print (-1 if d[-1] == INF else d[-1])