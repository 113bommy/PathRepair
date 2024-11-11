N, K = map(int, input().split())
A = list(map(int, input().split()))
MOD = 10**9 + 7

dp = [0] * (K + 1)
dp[0] = 1

for i, a in enumerate(A, start=1):
    accDp = [0] * (K + 2)
    for k in range(1, K + 2):
        accDp[k] = accDp[k - 1] + dp[k - 1]

    for k in range(K + 1):
        dp[k] = (dp[k] + accDp[k] - accDp[max(0, k - a)]) % MOD

print(dp[K] % MOD)
