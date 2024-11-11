def solve():
  ans = 0
  N, A = map(int, input().split())
  X = list(map(int, input().split()))
  x = sum(X)
  dp = [[[0]*(sum(X)+50) for _ in range(N+1)] for _ in range(N+1)]
  dp[0][0][0] = 1
  for i in range(N):
    for j in range(i+1):
      for k in range(x):
        dp[i+1][j][k] += dp[i][j][k]
        dp[i+1][j+1][k+X[i]] += dp[i][j][k]
  for j in range(1,N+1):
    ans += dp[-1][j][j*A]
  return ans
print(solve())