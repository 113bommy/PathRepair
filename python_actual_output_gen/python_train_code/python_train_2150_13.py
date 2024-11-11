INF = float('inf')
def bellmanford(n, edges, r):  # r : start
    d = [INF] * n
    d[r] = 0
    for i in range(n):
        for (u, v, c) in edges:
            if d[u] != INF and d[u] + c < d[v]:
                d[v] = d[u] + c
                if i == n-1 and v == n-1:
                    return 'inf'
    return d[n-1]


N, M = map(int, input().split())
edges = [None] * M
for i in range(M):
    a, b, c = map(int, input().split())
    edges[i] = (a-1, b-1, -c)
ans = bellmanford(N, edges, 0)
print(-ans)