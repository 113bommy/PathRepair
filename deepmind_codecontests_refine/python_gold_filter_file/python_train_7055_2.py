n,m = map(int,input().split())

dp = [0] * n
mod = 10**9 + 7


if n == 1:
    print((m-n) * m % mod)
elif n == 2:
    ans = (m - n)**2 + (m - n + 1)
    for i in range(2):
        ans *= (m - i)
        ans %= mod
    print(ans)
else:
    dp[0] = m - n
    dp[1] = (m - n)**2 + (m - n + 1)


    for i in range(2, n):
        dp[i] = (dp[i-1] + dp[i-2]) * i + dp[i-1] * (m - n)
        dp[i] %= mod

    ans = dp[-1]

    for i in range(n):
        ans *= (m - i)
        ans %= mod

    print(ans)
