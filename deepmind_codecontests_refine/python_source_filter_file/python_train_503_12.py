def main():
    N, A = map(int, input().split())
    x = [0].extend(list(map(int, input().split())))

    dp = [[[0 for _ in range(N * A + 1)] for _ in range(N + 1)] for _ in range(N + 1)]
    for i in range(N + 1):
        dp[i][0][0] = 1

    for i in range(1, N + 1):
        for j in range(1, i + 1):
            for k in range(1, N * A + 1):
                if k < x[k]:
                    dp[i][j][k] = dp[i - 1][j][k]
                else:
                    dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k - x[i]]

    ans = 0
    for j in range(1, N + 1):
        ans += dp[N][j][A * j]

    print(ans)


if __name__ == '__main__':
    main()
