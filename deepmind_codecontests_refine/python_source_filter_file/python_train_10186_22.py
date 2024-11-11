N,M,R=map(int, input().split())
r=map(lambda x:int(x)-1, input().split())
dp=[[10**9]*N for _ in range(N)]
for _ in range(M):
    A,B,C=map(int, input().split())
    A-=1
    B-=1
    dp[A][B]=C
    dp[B][A]=C
for z in range(N):
    for x in range(N):
        for y in range(N):
            dp[x][y]=min(dp[x][y], dp[x][z]+dp[z][y])

import itertools
ans=10**9
for p in itertools.permutations(range(R)):
    t=0
    rp=[r[i] for i in p]
    for i in range(R-1):
        t+=dp[rp[i]][rp[i+1]]
    ans=min(ans,t)
print(ans)