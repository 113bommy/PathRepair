T = int(input())
for i in range(T):
    n, a, b = map(int, input().split())
    s = input()
    dp = [[1000000000000000001 for i in range(2)] for j in range(n+1)]
    dp[0][0] = a + 2*b
    dp[0][1] = 2*a + 3*b
    for i in range(n-1):
        if s[i] == "0":
            if s[i+1] == "1":
                dp[i+1][1] = dp[i][1] + a + 2*b
            else:
                dp[i+1][1] = min(dp[i][1] + a + 2*b, dp[i][0] + 2*a + 2*b)
                dp[i+1][0] = min(dp[i][1] + 2*a + b, dp[i][0] + a + b)
        else:
            if s[i+1] == "1":
                dp[i+1][1] = dp[i][1] + a + 2*b
            else:
                dp[i+1][1] = dp[i][1] + a + 2*b
                dp[i+1][0] = dp[i][1] + 2*a + b
    print(dp[n-1][0])
