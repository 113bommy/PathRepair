N, K = list(map(int, input().split()))
dp = [[1] + [0 for i in range(K)] for j in range(N+1)]

for i in range(1, N+1):
    for j in range(1, K+1):
        dp[i][j] = dp[i-1][j] + dp[i-1][j-1]

for i in range(1, K+1):
    print((dp[N-K+1][i] * dp[K-1][i-1]) % (10**9+7))