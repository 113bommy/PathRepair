N = int(input())
p = list(map(float,input().split()))

dp = [[0]*(N+1) for i in range(N+1)] #dp[投げた枚数][表になった回数] = 確率
dp[0][0] = 1.0

for i in range(N):
  for j in range(i+1):
    dp[i+1][j+1] += dp[i][j]*p[i]
    dp[i+1][j] += dp[i][j]*(1-p[i])

ans = 0
for j in range(N+1):
  if j >= N/2:
    ans += dp[-1][j]
print(ans)