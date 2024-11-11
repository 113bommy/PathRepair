from itertools import permutations
N, M, R = map(int, input().split())
r = list(map(int, input().split()))
G = [[10**6]*(N+1) for _ in range(N+1)]
for _ in range(M):
    a, b, c = map(int, input().split())
    G[a][b] = c
    G[b][a] = c

for k in range(1, N+1):
    for i in range(1, N+1):
        for j in range(1, N+1):
            if G[i][k]+G[k][j] < G[i][j]:
                G[i][j] = G[i][k] + G[k][j]


ans = 10**10
for elem in permutations(r):
    res = 0
    for i in range(R-1):
        res += G[elem[i]][elem[i+1]]
    ans = min(ans, res)
print(ans)
