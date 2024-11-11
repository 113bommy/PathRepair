from itertools import permutations as per
n,m,r = map(int,input().split())
v = list(map(int,input().split()))
for i in range(r):
    v[i] -= 1
INF = float("inf")
g = [[INF]*n for _ in range(n)]
for i in range(m):
    a,b,c = map(int,input().split())
    a -= 1
    b -= 1
    g[a][b] = c
    g[b][a] = c
for i in range(n): g[i][i] = 0
for i in range(n):
    for j in range(n):
        for k in range(n):
            g[i][j] = min(g[i][j],g[i][k]+g[k][j])

ans = INF
for l in per(range(r)):
    t = 0
    for i in range(r-1):
        t += g[v[l[i]]][v[l[i+1]]]
    ans = min(ans,t)
print(ans)