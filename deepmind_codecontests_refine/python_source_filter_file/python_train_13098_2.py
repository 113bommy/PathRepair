import heapq

def dijkstra(s, G):
    inf = 1145141919810
    dist = [inf] * n
    dist[s] = 0
    c = [0] * n
    p = []
    heapq.heapify(p)
    heapq.heappush(p, (dist[s], s))
    while p:
        d, u = heapq.heappop(p)
        if dist[u] < d:
            continue
        c[u] = 1
        for g in G[u]:
            if c[g[0]] == 0 and dist[u] + g[1] < dist[g[0]]:
                dist[g[0]] = dist[u] + g[1]
                heapq.heappush(p, (dist[g[0]], g[0]))
    return dist

n, m, s, t = map(int, input().split())
yen = 10 ** 15
G = [[] for _ in range(n)]
H = [[] for _ in range(n)]
for _ in range(m):
    u, v, a, b = map(int, input().split())
    u -= 1
    v -= 1
    G[u].append([v, a])
    G[v].append([u, a])
    H[u].append([v, b])
    H[v].append([u, b])
dist1 = dijkstra(s - 1, G)
dist2 = dijkstra(t - 1, H)
ans = [0] * n
ans[n - 1] = yen - (dist1[n - 1] + dist2[n - 1])
for i in range(n - 2, -1, -1):
    ans[i] = max(ans[i + 1], yen - (dist1[i] + dist2[i]))
for i in ans:
    print(i)