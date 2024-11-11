N, S = map(int, input().split())
A = list(map(int, input().split()))
MOD = 998244353

dp = [0] * (S + 1)
ans = 0
for a in A:
    dp[0] += 1
    for s in range(S + 1)[::-1]:
        if a + s <= S:
            dp[a + s] = (dp[a + s] + dp[s]) % MOD
    ans += dp[S]
    ans %= MOD

print(ans)
