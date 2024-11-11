N,M = map(int,input().split())

a = [0]*M
b = [0]*M
c = [0]*M

for i in range(M):
    a[i],b[i],c[i] = map(int,input().split())
    a[i] -= 1
    b[i] -= 1
    

d = [[float("inf")]*N for i in range(N)]

for i in range(M):
    d[a[i]][b[i]] = c[i]
    d[b[i]][a[i]] = c[i]
    
for i in range(N):
    d[i][i] = 0

for i in range(N):
    for j in range(N):
        for s in range(N):
            d[i][j] = min(d[i][j], d[i][s]+d[s][j])

count = 0
for i in range(M):
    if d[a[i]][b[i]] < c[i]:
        count += 1
print(count)