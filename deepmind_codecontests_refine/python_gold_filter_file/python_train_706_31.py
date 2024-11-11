N, K = map(int, input().split())
A = list(map(int, input().split()))

MOD = pow(10, 9) + 7

dp = [[0 for i in range(K+1)] for j in range(N+1)]
dp[0][0] = 1

for i in range(N):
    S = [0] * (K+1)
    S[0] = dp[i][0]
    # 累積和
    for j in range(1, K+1):
        S[j] = (dp[i][j] + S[j - 1]) % MOD

    for j in range(K+1):
        if j-1 >= A[i]:
            dp[i+1][j] = (S[j] - S[j-1-A[i]]) % MOD
        else:
            dp[i+1][j] = S[j]

print(dp[N][K])
