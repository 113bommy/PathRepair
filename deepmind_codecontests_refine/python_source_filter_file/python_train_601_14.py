n,m=map(int,input().split())
s=list(map(int,input().split()))
t=list(map(int,input().split()))
dp=[(m+1)*[1]for _ in range(n+1)]
for i in range(n):
  for j in range(m):
    dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j]
    if s[i]!=t[j]:dp[i+1][j+1]-=dp[i][j]
    dp[i+1][j+1]%(10**9+7)
print(dp[-1][-1])