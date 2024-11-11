H, W = map(int, input().split())
M = [input() for i in range(H)]
dp = [[0 for i in range(W)] for j in range(H)]
dp[0][0] = 1

for i in range(H):
  for j in range(W):
    if i+1 < H and M[i+1][j] == ".":
      dp[i+1][j] = dp[i][j]
    if j+1 < W and M[i][j+1] == ".":
      dp[i][j+1] += dp[i][j]

print(dp[H-1][W-1] % (10**9+7))
