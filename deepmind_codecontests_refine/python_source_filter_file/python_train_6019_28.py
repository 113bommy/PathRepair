n = int(input())
c = [-1] + [int(input()) for i in range(n)]

count = [0]*(200005)
dp = [0]*(n+1)
dp[0] = 1
mod = 10**9+7
#dp[i]: i番目までの場合の数
for i in range(n):
    dp[i+1] = dp[i]
    if c[i+1] != c[i]:
        dp[i+1] += count[c[i+1]]
        dp[i+1] %= mod
    count[c[i+1]] += dp[i]
    count[c[i+1]] %= mod

print(dp[n]%mod)
