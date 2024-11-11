for _ in range(int(input())):
    n, coins, k = map(int, input().split())
    a = sorted(map(int, input().split()))
    dp = [float('inf')] * (n + 1)
    dp[0] = 0
    for i in range(1, n + 1):
        dp[i] = a[i - 1] + dp[i - 1]
        if i - k >= 0:
            dp[i] = min(dp[i], a[i - 1] + dp[i - k])
    ret = 0
    for i in range(n + 1):
        if dp[i] <= coins:
            ret = i
        else:
            break
    print(ret)
