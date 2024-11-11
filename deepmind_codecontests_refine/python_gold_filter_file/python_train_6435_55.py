import sys
input = sys.stdin.readline
K = list(map(int, list(input())[: -1]))
D = int(input())
mod = 10 ** 9 + 7
dp = [[0] * D for _ in range(len(K) + 1)]
dplim = [[0] * D for _ in range(len(K) + 1)]
dplim[0][0] = 1
for i in range(len(K)):
  for j in range(D):
    dplim[i + 1][(j + K[i]) % D] += dplim[i][j]
    for k in range(10):
      if k < K[i]:
        dp[i + 1][(j + k) % D] += dplim[i][j]
      dp[i + 1][(j + k) % D] += dp[i][j]
      dp[i + 1][(j + k) % D] %= mod
print((dp[-1][0] + dplim[-1][0] - 1) % mod)