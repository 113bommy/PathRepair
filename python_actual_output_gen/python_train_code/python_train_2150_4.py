N,M = map(int,input().split())
ABC = [tuple(map(int,input().split())) for i in range(M)]

INF = float('inf')
dist = [INF] * N
dist[0] = 0
for i in range(N):
    for a,b,c in ABC:
        a,b,c = a-1,b-1,-c
        if dist[b] > dist[a] + c:
            dist[b] = dist[a] + c
            if i==N-1 and to == N-1:
                print('inf')
                exit()
print(-dist[-1])