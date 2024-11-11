import sys
input = sys.stdin.readline
MOD = 10**9+7

n, k = map(int, input().split())
A = list(map(int, input().split()))
dp = [[0]*(k+1) for _ in range(n+1)]
dp[0][0] = 1
for i, a in enumerate(A):
  for j in range(k+1):
    if j == 0:
      dp[i+1][j] = 1
    elif j <= a:
      dp[i+1][j] = dp[i+1][j-1] + dp[i][j]
    else:
      dp[i+1][j] = dp[i+1][j-1] + dp[i][j] - dp[i][j-a-1]
    dp[i+1][j] %= MOD
ans = dp[n][k]
print(ans)