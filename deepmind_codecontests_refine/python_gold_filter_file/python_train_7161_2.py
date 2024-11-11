N, T = map(int, input().split())
X = [list(map(int, input().split())) for _ in range(N)]
X.sort()
dp = [-1 for _ in range(T+X[-1][0]+10)]
dp[0] = 0
for i in range(N):
  for j in range(T, 0, -1):
    if dp[j-1] != -1:
      dp[j-1+X[i][0]] = max(dp[j-1+X[i][0]], dp[j-1] + X[i][1])
print(max(dp))
