N,M = map(int, input().split())
a = set([int(input()) for _ in range(M)])
dp = [0]*(N+1)
dp[0] = 1
dp[1] =0 if 1 in a else 1
for i in range(2, N+1):
  dp[i] = (dp[i-1] + dp[i-2])%(10**9+7) if i not in a else 0
print(dp[N])