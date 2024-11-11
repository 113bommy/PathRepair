MOD = 998244353
n, s = map(int, input().split())
A = map(int, input().split())
dp = [0]*(s+1)
dp[0] = 1
inv_2 = (MOD+1)//2
for a in A:
    for j in reversed(range(s+1)):
        if j-a < 0:
            continue
        dp[j] += dp[j-a]*inv_2
        dp[j] %= MOD

print(dp[-1]*pow(2, n, MOD) % MOD)
