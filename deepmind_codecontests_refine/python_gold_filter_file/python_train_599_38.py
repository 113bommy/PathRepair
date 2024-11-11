n, s = map(int, input().split())
a = list(map(int, input().split()))

dp = [[1 if _2 == 0 else 0 for _2 in range(s + 1)] for _1 in range(n+1)]

MOD = 998244353

for i, ai in enumerate(a):
  for j, v in enumerate(dp[i]):
    dp[i + 1][j] += v
    dp[i + 1][j] %= MOD 
    if j + ai <= s:
      dp[i + 1][j + ai] += v
      dp[i + 1][j + ai] %= MOD


print(sum(dp_i[s] for dp_i in dp) % MOD)
    