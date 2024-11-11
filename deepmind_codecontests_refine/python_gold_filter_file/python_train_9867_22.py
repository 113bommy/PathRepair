A,B,C,D=map(int,input().split())
mod=998244353

dp=[[0]*D for _ in range(C)]

dp[A-1][B-1]=1

for i in range(A-1,C):
    for j in range(B-1,D):
        if i==A-1 and j==B-1:
            continue
        if i>A-1:
            dp[i][j]+=dp[i-1][j]*(j+1)
        if j>B-1:
            dp[i][j]+=dp[i][j-1]*(i+1)
        if i>A-1 and j>B-1:
            dp[i][j]-=dp[i-1][j-1]*(j)*(i)
        dp[i][j]%=mod

print(dp[C-1][D-1]%mod)
