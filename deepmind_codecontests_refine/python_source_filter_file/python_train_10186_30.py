import itertools

N, M, R = map(int, input().split())
r = [int(x) - 1 for x in input().split()]

dist = [[float('inf')] * N for _ in range(N)]
for _ in range(M):
	a, b, c = map(int, input().split())
	a -= 1
	b -= 1
	dist[a][b] = dist[b][a] = c

for k in range(N):
	for i in range(N):
		for j in range(N):
			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

ans = float('inf')
k = list(itertools.permutations(r))
for i in k:
	sumDist = 0
	for j in range(len(i) - 1):
		sumDist += dist[i[j]][i[j+1]]
	ans = min(ans, sumDist)
print(ans)