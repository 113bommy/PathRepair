N, M = map(int, input().split())
S = list(input().split())
T = list(input().split())
MOD = 10**9+7
dp = [[0] * (M+1) for _ in range(N+1)]
sum = [[0] * (M+1) for _ in range(N+1)]
dp[0][0] = 1
for i in range(N+1):
    sum[i][0] = 1
for j in range(M+1):
    sum[0][j] = 1
for i in range(N):
    for j in range(M):
        dp[i+1][j+1] = (S[i] == T[j]) * sum[i][j]
        sum[i+1][j+1] = (sum[i+1][j] + sum[i][j+1] - sum[i][j] + dp[i+1][j+1]) % MOD
print(sum[N][M])