n, m = map(int, input().split())
s = list(map(int, input().split()))
t = list(map(int, input().split()))

M = 10**9+7

dp = [[1]*(m+1) for _ in range(n+1)]

for i in range(n):
  for j in range(m):
    if s[i] == t[j]:
      dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1]
    else:
      dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1] - dp[i][j]
    dp[i+1][j+1] %= M

#print(dp)
print(dp[-1][-1]%M)