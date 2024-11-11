N, M = map(int, input().split())
edge = [list(map(int, input().split())) for _ in range(M)]
INF = 10 ** 9
g = [[INF] * (N + 1) for _ in range(N + 1)]
for i in range(1, N + 1):
    g[i][i] = 0
for a, b, c in edge:
    g[a][b] = c
    g[b][a] = c
for i in range(1, N + 1):
    for j in range(1, N + 1):
        for k in range(1, N + 1):
            g[i][j] = min(g[i][j], g[i][k] + g[k][j])

ans = 0
for a, b, c in edge:
    if g[a][b] != c:
        ans += 1
print(ans)