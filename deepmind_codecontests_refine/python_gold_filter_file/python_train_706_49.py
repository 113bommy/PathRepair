import sys
readline = sys.stdin.readline

N,K = map(int, readline().split())
A = list(map(int,readline().split()))
DIV = 10 ** 9 + 7

# dp[i][j] : i人目までにj個配るときの場合の数
# 数式変形で以下
# dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - Ai-1 - 1]

dp = [[0] * (K + 1) for i in range(N + 1)]
for i in range(N + 1):
  dp[i][0] = 1 # 0個配る方法は常に1通り
  
for i in range(1, N + 1):
  for j in range(1, K + 1):
    if j - A[i - 1] - 1 >= 0:
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - A[i - 1] - 1]) % DIV
    else:
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % DIV
      
print(dp[N][K])