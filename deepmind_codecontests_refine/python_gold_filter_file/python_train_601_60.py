n,m=map(int, input().split())
s=list(map(int, input().split()))
t=list(map(int, input().split()))
dp=[[0]*(n+1) for _ in range(m+1)]
for i in range(m+1):
    dp[i][0]=1
for i in range(n+1):
    dp[0][i]=1
for i in range(m):
    for j in range(n):
        if s[j]==t[i]:
            dp[i+1][j+1]=(dp[i][j+1]+dp[i+1][j])%(10**9+7)
        else:
            dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j]-dp[i][j]
print(dp[-1][-1]%(10**9+7))