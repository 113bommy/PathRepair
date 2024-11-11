N, K = map(int, input().split())
MOD = 10**9 + 7

num = []
now = N + 1
i = 1
while True:
  r = N // (i+1) + 1
  if r == now:
    break
  num.append(now - r)
  now = r
  i += 1
  
num += [1] * (N - sum(num))
n = len(num)
dp = [[0]*n for i in range(K)]
for _n in range(n):
  dp[0][_n] = num[_n]

for i in range(1, K):
  s = 0
  for _n in range(n):
    j = n - 1 - _n
    s += dp[i-1][j] % MOD
    s %= MOD
    dp[i][_n] = s * num[_n] % MOD

ans = sum(dp[-1])
print(ans % MOD)