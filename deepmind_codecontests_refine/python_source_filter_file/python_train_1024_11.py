# ABC 051 D
INF = 7+10**9
N, M = map(int,input().split())
P = []
D = [[INF for k in range(N)] for l in range(N)]
for k in range(N):
    D[k][k] = 0
for k in range(M):
    a, b, c = map(int,input().split())
    P.append([a-1,b-1,c])
    D[a-1][b-1] = c
    D[b-1][a-1] = c

# Floyd-Warshall
for k in range(M):
    for l in range(M):
        for m in range(M):
            D[l][m] = min(D[l][m], D[l][k]+D[k][m])

ans = M
for p in P:
    a, b, c = p[0], p[1], p[2]
    for k in range(N):
        if D[a][k] + c == D[b][k]:
            ans -= 1
            break 
print(ans)
