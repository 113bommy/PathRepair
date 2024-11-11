N, A = map(int, input().split())
X = list(map(lambda x: int(x)-A, input().split()))
X_MAX = max(max(X), -min(X))
NX = N * X_MAX
dp = [[0] * (X_MAX * (N+1) * 2 + 1)  for i in range(N+1)]
dp [0][0] = 1
for i in range(1, N+1):
    for j in range(NX*2+1):
        dp[i][j] += dp[i-1][j]
        dp[i][j] += dp[i-1][j-X[i-1]]

print(dp[N][NX]-1)