N,K = map(int, input().split())
A = list(map(int, input().split()))
MOD = 1000000007

dp = [[0] * (K+10) for _ in range(N+1)]
dp[0][0] = 1
for i in range(min(N,50)):
    for j in range(K,-1,-1):
        dp[i+1][j] += dp[i][j]
        dp[i+1][j] %= MOD
        if j + A[i] + 1 <= K+1:
            dp[i+1][j+A[i]+1] = (dp[i+1][j+A[i]+1] - dp[i][j] + MOD) % MOD
    
    for j in range(K+1):
        dp[i+1][j+1] += dp[i+1][j]
        dp[i+1][j+1] %= MOD

print(dp[N][K])
