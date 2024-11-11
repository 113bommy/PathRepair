S = input()
n = len(S)

MOD = 10 ** 9 + 7

# dp[i][j] i桁までで、あまりjの個数
dp = [[0] * 13 for _ in range(n + 1)]
dp[0][0] = 1

for i, s in enumerate(S):
  if s == "?":
    c = -1
  else:
    c = int(s)
  for j in range(10):
    if c != -1 and c != j:
      continue
    for k in range(13):
      dp[i + 1][(k * 10 + j) % 13] += dp[i][k]
  for k in range(13):
    dp[i][k] %= MOD
print(dp[n][5])