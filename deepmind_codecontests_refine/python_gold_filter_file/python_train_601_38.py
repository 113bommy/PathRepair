mod = int(1e9+7)

n, m = map(int, input().split())
s = list(map(int, input().split()))
t = list(map(int, input().split()))

dp = []
for i in range(len(s)+1):
  dp.append([0] * (len(t)+1))

for i in range(1, len(s)+1):
  for j in range(1, len(t)+1):
    if s[i-1] == t[j-1]:
      dp[i][j] = (1 + dp[i-1][j] + dp[i][j-1]) % mod
    else:
      dp[i][j] = (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]) % mod
ans = dp[-1][-1] + 1 % mod
print(ans)
