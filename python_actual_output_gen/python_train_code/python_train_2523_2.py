for _ in range(int(input())):
    n, a, b = map(int, input().split())
    s = list(map(int, list(input())))
    dp = [[float('inf') for i in range(2)] for i in range(n + 1)]
    dp[0][0] = b
    for i in range(n):
        if s[i] == 0:
            dp[i + 1][0] = min(dp[i][0] + a + b, dp[i][1] + 2*a + b)
            dp[i + 1][1] = min(dp[i][0] + 2 * (a + b), dp[i][1] + a + 2*b)
        else:
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + a + 2*b)

    print(min(dp[n]))