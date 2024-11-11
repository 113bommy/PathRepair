n = int(input())
c = [int(input()) for _ in range(n)]
MOD = 10 ** 9 + 7

dp = [0] * (n + 1)
dp[0] = 1
prev = [-1] * (10 ** 6)
for i, x in enumerate(c):
    dp[i + 1] = dp[i]
    if 0 <= prev[x] < i:
        dp[i + 1] += dp[prev[x]]
        dp[i + 1] %= MOD
    prev[x] = i + 1
print(dp[n])
