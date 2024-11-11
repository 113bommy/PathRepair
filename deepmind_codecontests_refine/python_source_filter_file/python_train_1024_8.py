N, M = (int(x) for x in input().split())
graph = [[1000] * N for _ in range(N)]
before = []
for _ in range(M):
    a,b,c = (int(x) for x in input().split())
    before.append((a-1,b-1,c))
    graph[a-1][b-1] = c
    graph[b-1][a-1] = c

for i in range(N):
    graph[i][i] = 0

for i in range(N):
    for j in range(N):
        for k in range(N):
            graph[j][i] = graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j])

ans = 0
for x in before:
    if graph[x[0]][x[1]] != x[2]:
        ans += 1
print(ans)