n=int(input())
a=list(map(float, input().split()))
dp=[[0]*(n+1) for i in range(n+1)]
dp[0][0]=1
for i in range(n):
    for j in range(n):
        if dp[i][j]==0:continue
        dp[i+1][j+1]+=dp[i][j]*a[i]
        dp[i+1][j]+=dp[i][j]*(1-a[i])
print(sum(dp[-1][n//2+1:]))