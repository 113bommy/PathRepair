import itertools

N,M,R = map(int,input().split())
r = list(map(lambda x:int(x)-1,input().split()))
ABC = [list(map(int,input().split())) for _ in range(M)]
INF = 10**7
d = [[INF]*N for _ in range(N)]

for A,B,C in ABC:
    d[A-1][B-1] = C
    d[B-1][A-1] = C
for k in range(N):
    for i in range(N):
        for j in range(i+1,N):
            d[i][j] = min(d[i][j],d[i][k]+d[k][j])
            d[j][i] = d[i][j]
ans = INF * M
for r in itertools.permutations(r):
    S = 0
    for i,ri in enumerate(r[:-1]):
        S += d[ri][r[i+1]]
    ans = min(ans,S)
print(ans)