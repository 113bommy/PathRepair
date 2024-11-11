t, k = map(int, input().split())

mod = 10**9 + 7


end = 10**5+1

dp = [1]*(end)



for i in range(k, end):
    dp[i] = dp[i-1] + dp[i-k]
    if dp[i] >= mod:
        dp[i] %= mod
    

for i in range(1, end):
    dp[i] += dp[i-1]
    if dp[i] >= mod:
        dp[i] %= mod

for _ in range(t):
    a, b = map(int, input().split())
    print(dp[b]-dp[a-1])

    



