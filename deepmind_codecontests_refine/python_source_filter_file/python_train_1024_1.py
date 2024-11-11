N, M = map(int, input().split())
to = [[float("INF")] * N for i in range(N)]
aa = []

for i in range(M):
    a, b, c = map(int, input().split())
    to[a-1][b-1] = c
    to[b-1][a-1] = c
    aa.append([a-1, b-1, c])

for i in range(N):
    to[i][i] = 0

for k in range(N):
    for i in range(N):
        for j in range(N):
            to[i][j] = min(to[i][j], to[i][k] + to[k][j])

print(to)

c = 0
for i in range(M):
    for j in range(N):
        if to[j][aa[i][1]] == to[j][aa[i][0]] + aa[i][2]:
            c += 1
            break


print(M - c)