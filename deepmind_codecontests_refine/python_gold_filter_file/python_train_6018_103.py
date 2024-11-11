S = input()
MOD = 10**9 + 7

M = 13
dp = [0] * M
dp[0] = 1

for s in S:
    newDp = [0] * M
    if s == '?':
        for s in range(10):
            for m in range(M):
                newDp[(m * 10 + s) % M] += dp[m]
    else:
        s = int(s)
        for m in range(M):
            newDp[(m * 10 + s) % M] += dp[m]
    dp = newDp
    for m in range(M):
        dp[m] %= MOD

print(newDp[5] % MOD)