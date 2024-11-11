import sys
read = sys.stdin.read
MOD = 10**9+7

n, *C = map(int, read().split())
dp = [0]*(n+1)
dp[0] = 1
idx = [-1]*(2*10**5+1)
for i, c in enumerate(C, 1):
  dp[i] = dp[i-1]
  if idx[c] != -1 and idx[c] < i-1:
    dp[i] += dp[idx[c]]
    dp[i] %= MOD
  idx[c] = i
print(dp[-1])