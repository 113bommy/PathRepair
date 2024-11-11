S = input()
K = 13
MOD = 10**9 + 7

dp = [0] * K
dp[0] = 1

for s in S:
    newDp = [0] * K
    if s == '?':
        for i in range(10):
            for j in range(K):
                newDp[(j * 10 + i) % K] += dp[j]
    else:
        i = int(s)
        for j in range(K):
            newDp[(j * 10 + i) % K] += dp[j]
    dp = newDp
    for i in range(K):
        dp[i] %= MOD

print(dp[5])
