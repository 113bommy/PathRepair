fac = [1] * 500
finv = [1] * 500
p2 = [1] * 500

n, MOD = map(int, input().split())

for i in range(len(fac) - 1):
    fac[i + 1] = fac[i] * (i + 1) % MOD
    finv[i + 1] = pow(fac[i + 1], MOD - 2, MOD)
    p2[i + 1] = p2[i] * 2 % MOD

ans = 0
dp = [[0] * (n // 2 + 1) for _ in range(n + 2)]
dp[0][0] = 1
for i in range(n):
    for j in range(i + 2, n + 2):
        for k in range(n // 2):
            dp[j][k + 1] += dp[i][k] % MOD * finv[j - i - 1] * p2[j - i - 2]
ans = 0
for i in range(1, n // 2 + 1):
    ans += dp[n + 1][i] * fac[n - i + 1]
print(ans % MOD)