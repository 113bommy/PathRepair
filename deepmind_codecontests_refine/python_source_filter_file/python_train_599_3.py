n,s = map(int, input().split())
a = list(map(int, input().split()))
mod = 998244353
dp = [[0] * (s+1) for i in range(n+1)]
for i in range(n):
  dp[i][0] = 1
for i in range(n):
  for j in range(s+1):
    dp[i+1][j] += dp[i][j]
    dp[i+1][j] %= mod
    if j >= a[i]:
      dp[i+1][j] += dp[i][j-a[i]]
      dp[i+1][j] %= mod
ans = list()
for i in dp:
  ans.append(i[-1])
ans = ans[1:]
print(sum(ans))