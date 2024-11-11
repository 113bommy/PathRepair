import itertools

INF = 10**10
N, M, R = map(int, input().split())
*r, = map(int, input().split())
r = [v-1 for v in r]

g = [[INF]*N for _ in range(N)]
for i in range(N):
    g[i][i] = 0

for m in range(M):
    a, b, c = map(int, input().split())
    a -= 1
    b -= 1
    g[a][b] = c
    g[b][a] = c

for i in range(N):
    for j in range(N):
        for k in range(N):
            g[i][j] = min(g[i][j], g[i][k]+g[k][j])

ans = INF
for rs in itertools.permutations(r):
    cost = 0
    for i in range(len(rs)-1):
        cost += g[rs[i]][rs[i+1]]
    if cost < ans:
        ans = cost

print(ans)
