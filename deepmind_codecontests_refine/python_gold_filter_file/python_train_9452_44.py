N, M, P = map(int, input().split())
E = dict()
for i in range(M):
    a, b, c = map(int, input().split())
    E[(i, a, b)] = c-P
INF = float('inf')

dist = {i: -INF for i in range(1, N+1)}
dist[1] = 0
ans = 0
for i in range(N*2):
    for iuv, c in E.items():
        _, u, v = iuv
        if dist[v] < dist[u] + c:
            dist[v] = dist[u] + c
            if i >= N:
                dist[v] = INF
    if i == N-1:
        ans = dist[N]

print(max(0, dist[N]) if ans == dist[N] else -1)
