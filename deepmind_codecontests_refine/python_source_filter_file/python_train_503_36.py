n,a=map(int,input().split())
X=list(map(int,input().split()))
dp=[[[0]*52 for _ in range(2505)] for _ in range(52)]
ans=0
dp[0][0][0]=1
for i in range(n):
    for j in range(52+50*i):
        for k in range(i+1):
            ni=i+1
            nj=j+X[i]
            nk=k+1
            dp[ni][nj][nk]+=dp[i][j][k]
            dp[ni][j][k]+=dp[i][j][k]
ans=0
for i in range(1,n+1):
    ans+=dp[n][i*a][i]
print(ans)