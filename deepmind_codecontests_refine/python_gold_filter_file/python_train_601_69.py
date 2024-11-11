import sys
input = sys.stdin.readline
MOD = 10**9+7

n, m = map(int, input().split())
S = list(map(int, input().split()))
T = list(map(int, input().split()))
dp = [[0]*(m+1) for _ in range(n+1)]
for i in range(n+1):
  for j in range(m+1):
    if i == 0 or j == 0:
      dp[i][j] = 1
    else:
      dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1]
      if S[i-1] == T[j-1]:
        dp[i][j] += dp[i-1][j-1]
      dp[i][j] %= MOD
ans = dp[n][m]
print(ans)