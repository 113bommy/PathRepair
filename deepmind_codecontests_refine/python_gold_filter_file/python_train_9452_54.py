N, M, P = map(int,input().split())
dist = [0] + [float('inf')] * (N - 1)

a = []
b = []
c = []

for i in range(M):
    i,j,k = map(int,input().split())
    a.append(i)
    b.append(j)
    c.append(-1*(k - P))

INF = float('inf')

for i in range(N-1):
    for j in range(M):
        if dist[a[j] - 1] == INF: continue
        if dist[b[j] - 1] > dist[a[j] - 1] + c[j]:
            dist[b[j] - 1] = dist[a[j] - 1] + c[j]
        
ans = dist[N -1]

negative = [False] * N

for i in range(N):
    for j in range(M):
        if dist[a[j] - 1] == INF: continue
        if dist[b[j] - 1] > dist[a[j] - 1] + c[j]:
            dist[b[j] - 1] = dist[a[j] - 1] + c[j]
            negative[b[j] - 1] = True

        if negative[a[j] - 1] == True:
            negative[b[j] - 1] = True

if negative[N - 1]:
    print(-1)
else:
    print(max(-1 * ans, 0))
