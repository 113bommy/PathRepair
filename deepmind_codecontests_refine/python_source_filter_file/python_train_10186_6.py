import itertools


N,M,R = map(int,input().split())
rs = list(map(lambda x:int(x)-1,input().split()))
cost=[[10**9]*N for i in range(N)]
for i in range(M):
    a,b,c = map(int,input().split())
    cost[a-1][b-1] = c
    cost[b-1][a-1] = c

for k in range(N):
    for i in range(N):
        for j in range(i):  # j<i
            cost[i][j] =  min(cost[i][j],cost[i][k] + cost[k][j])
            cost[j][i] = cost[i][j]

ans = 10**9
for roads in itertools.permutations(rs):
    co = 0
    p = roads[0]
    for r in roads[1:]:
        co += cost[p][r]
        p = r
    ans = min(ans,co)
print(ans)
