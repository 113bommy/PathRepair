n,s = map(int,input().split())
a = list(map(int,input().split()))
dp = [[0 for i in range(s+1)] for j in range(n+1)]
dp[0][0] = 1
mod = 10**9+7
for i in range(1,n+1):
  x = a[i-1]
  for j in range(s+1):
    dp[i][j] += dp[i-1][j]*2
    dp[i][j] %= mod
  for j in range(x,s+1):
    dp[i][j] += dp[i-1][j-x]
    dp[i][j] %= mod
print(dp[-1][-1])