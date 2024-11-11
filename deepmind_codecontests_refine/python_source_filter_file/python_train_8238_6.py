if __name__ == '__main__':
    n, x = map(int, input().split())
    arr = [int(x) for x in input().split()]
    dp = [[0 for i in range(3)] for j in range(n)]
    for i in range(n):
        dp[i][0] = max(0, arr[i])
        dp[i][1] = max(0, arr[i])
        dp[i][2] = max(0, arr[i] * x)
        if i == 0:
            continue
        dp[i][0] = max(dp[i][0], arr[i] + dp[i - 1][0])
        dp[i][1] = max(dp[i][1], arr[i] + dp[i - 1][1], arr[i] + dp[i - 1][2])
        dp[i][2] = max(dp[i][2], dp[i - 1][2] + (arr[i] * x), dp[i - 2][0] + (arr[i] * x))
    ans = 0
    for i in range(n):
        ans = max(ans, dp[i][0], dp[i][1], dp[i][2])
    print(ans)
