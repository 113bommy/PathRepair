mod = 998244353
n, s = map(int, input().split())
a = list(map(int, input().split()))
dp = [0] * (s + 1)
ans = 0
for i in range(n):
    dp[0] += 1
    for j in range(a[i], s + 1)[::-1]:
        dp[j] += dp[j - a[i]]
        dp[j] %= mod
    ans += dp[-1]
    ans %= mod
print(ans)