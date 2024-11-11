mod = 10 ** 9 + 7

N, K, *A = map(int, open(0).read().split())

dp = [1] + [0] * (K + 1)
for a in A:
    for i in range(1, K + 1):
        dp[i] += dp[i - 1]
    for i in reversed(range(1, K + 1)):
        dp[i] -= dp[max(0, i - a) - 1]
        dp[i] %= mod

print(dp[K])