n, s = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
mod = 998244353
dp = [0] * (s + 1)
dp[0] = 1
for i in a:
    dp2 = [0] * (s + 1)
    for j in range(s + 1):
        dp2[j] = dp[j] * 2
        if j >= i:
            dp2[j] += dp[j - i]
        dp2[j] %= mod
    dp = dp2
print(dp[-1])
