import heapq

def dijkstra(s):
    inf = pow(10, 9)
    dist = [inf] * (n + 2)
    dist[s] = 0
    c = [0] * (n + 2)
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
    return dist[n + 1]

xs, ys, xt, yt = map(int, input().split())
n = int(input())
s = [list(map(int, input().split())) for _ in range(n)]
s.insert(0, [xs, ys, 0])
s.append([xt, yt, 0])
G = [[] for _ in range(n + 2)]
for i in range(n + 2):
    for j in range(n + 2):
        if not i == j:
            G[i].append([j, max(0, (pow(s[i][0] - s[j][0], 2) + pow(s[i][1] - s[j][1], 2)) ** (1 / 2) - s[i][2] - s[j][2])])
ans = dijkstra(0)
print(ans)