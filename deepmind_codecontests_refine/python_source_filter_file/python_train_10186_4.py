from itertools import permutations

INF=1145141919810

N,M,R=map(int,input().split())
r=map(int,input().split())

road=[[0 if x==y else INF for y in range(N+1)] for x in range(N+1)]

for _ in range(M):
	a,b,c=map(int,input().split())
	road[a][b] = road[b][a] = c

for k in range(N+1):
	for i in range(N+1):
		for j in range(N+1):
			road[i][j] = min(road[i][j], road[i][k] + road[k][j])

print(min(sum(road[p[i-1]][p[i]] for i in range(1, R)) for p in permutations(r)))
