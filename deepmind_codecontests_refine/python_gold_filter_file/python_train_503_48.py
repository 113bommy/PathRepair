if __name__ == '__main__':
    N, A = map(int, input().split())
    x = list(map(int, input().split()))

    x.insert(0, 0)

    dp = [[[0 for _ in range(N * A + 1)] for _ in range(N + 1)] for _ in range(N + 1)]
    for i in range(N + 1):
        dp[i][0][0] = 1

    for i in range(1, N + 1):
        for j in range(1, i + 1):
            for k in range(1, N * A + 1):
                dp[i][j][k] = dp[i - 1][j][k]
                if k >= x[i]:
                    dp[i][j][k] += dp[i - 1][j - 1][k - x[i]]

    ans = 0
    for j in range(1, N + 1):
        ans += dp[N][j][A * j]

    print(ans)
