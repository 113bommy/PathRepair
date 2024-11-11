def solve():
  N = int(input())
  s = input()
  mod = 10**9+7
  dp = [[0]*N for _ in range(N)]
  dp[-1][0]=1
  for i in range(N-2,-1,-1):
    if s[i]=='>':
      for j in range(N-i-2,-1,-1):
        dp[i][j] = dp[i][j+1]+dp[i+1][j]
        dp[i][j]%mod
    else:
      for j in range(1,N-i):
        dp[i][j] = dp[i][j-1]+dp[i+1][j-1]
        dp[i][j]%mod
  ans = sum(dp[0])%mod
  return ans
print(solve())