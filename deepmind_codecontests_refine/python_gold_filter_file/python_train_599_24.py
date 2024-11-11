n, s = map(int, input().split())
a = list(map(int, input().split()))

MOD = 998244353

dp = [[0 for _ in range(s + 1)] for _ in range(n + 1)]

ans = 0

for i, x in enumerate(a):
    if x < s:
        dp[i+1][x] = i + 1
    if x == s:
        ans = (ans + (n-i) * (i+1)) % MOD
    for j in range(1, s):
        if dp[i][j] > 0:
            dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD
            if j + x < s:
                dp[i+1][j+x] = (dp[i+1][j+x] + dp[i][j]) % MOD
            elif j + x == s:
                ans = (ans + dp[i][j] * (n-i)) % MOD

print(ans)