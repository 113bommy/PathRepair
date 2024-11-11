n, s = map(int, input().split())
A = list(map(int, input().split()))
MOD = 998244353
dp = [0]*(s+1)
dp[0] = pow(2, n, MOD)
inv_2 = pow(2, MOD-2, MOD)
for a in A:
    for j in reversed(range(s+1)):
        if s < j+a:
            continue
        dp[j+a] += dp[j]*inv_2 % MOD

print(dp[-1] % MOD)