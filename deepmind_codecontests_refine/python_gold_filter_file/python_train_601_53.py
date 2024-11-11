MOD = 10 ** 9 + 7
n, m = map(int, input().split())
s = list(map(int, input().split()))
t = list(map(int, input().split()))

dp = [0] * n
ndp = [0] * n
for tj in t:
    for i in range(n):
        ndp[i] = 0
    acc = 0
    for i, si in enumerate(s):
        if si == tj:
            ndp[i] = (dp[i] + acc + 1) % MOD
        else:
            ndp[i] = dp[i]
        acc = (acc + dp[i]) % MOD
    dp, ndp = ndp, dp
print((sum(dp) + 1) % MOD)
