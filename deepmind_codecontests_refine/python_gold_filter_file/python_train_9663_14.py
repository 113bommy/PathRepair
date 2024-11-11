S = input()
N = len(S)
MOD = 10 ** 9 + 7

dp = [0, 0, 0, 0]
dp[0] = 1

for s in S:
    factor = 3 if s == '?' else 1
    for j, c in zip([2, 1, 0], 'CBA'):
        dp[j + 1] = dp[j + 1] * factor % MOD
        if s == c or s == '?':
            dp[j + 1] += dp[j]
    if s == '?':
        dp[0] = (dp[0] * 3) % MOD

ans = dp[-1] % MOD

print(ans)