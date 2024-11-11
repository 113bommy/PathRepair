H, W, K = map(int, input().split())
MOD = (10 ** 9) + 7

dp = [[0] * W for _ in range(H+1)]
dp[0][K-1] = 1

multi = [
  1, # 0
  2, # 1
  3, # 2
  5, # 3
  8, # 4
  13,# 5
  20 # 6
]

def f(num, l, r):
  left = max(0, l)
  right = num-1 - min(r, num-1)
  return multi[left] * multi[right]

for h in range(1, H+1):
  for w in range(W):
    dp[h][w] += dp[h-1][w] * f(W, w-1, w+1)
    if w > 0:
      dp[h][w] += dp[h-1][w-1] * f(W, w-2, w+1)
    if w < W - 1:
      dp[h][w] += dp[h-1][w+1] * f(W, w-1, w+2)
    dp[h][w] %= MOD

print(dp[H][0])