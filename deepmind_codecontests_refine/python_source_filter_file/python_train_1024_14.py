n,m = map(int,input().split())
INF = 10**18
d = [[INF]*n for _ in range(n)]
for i in range(n): d[i][i] = 0
a = [0]*m
b = [0]*m
c = [0]*m
for i in range(m):
    a,b,c = map(int,input().split())
    a -= 1
    b -= 1
    a[i] = a
    b[i] = b
    c[i] = c
    d[a][b] = c
    d[b][a] = c

for k in range(n):
    for i in range(n):
        for j in range(n):
            d[i][j] = min(d[i][j], d[i][k]+d[k][j])

ans = 0
for i in range(m):
    if d[a[i]][b[i]] < c[i]: ans += 1
print(ans)