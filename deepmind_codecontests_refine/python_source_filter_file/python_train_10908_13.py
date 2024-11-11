N,K = map(int, input().split())
dp = [0]*(K+1)
MOD = 10**9+7
ans = 0
for X in range(K,0,-1):
  m = (K//X)**N%MOD
  x = 2*X
  while x<=K:
    m -= dp[x]
    m %= MOD
    x += X
  ans += X*m
  ans %= MOD
  dp[X] = m
print(ans)
  