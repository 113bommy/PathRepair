def main():
    MOD = 10 ** 9 + 7
    N, K = list(map(int, input().split(' ')))
    A = list(map(int, input().split(' ')))
    dp = [[0 for _ in range(K + 1)] for _ in range(N + 1)]
    for n in range(N + 1):
        dp[n][0] = 1
    for n in range(1, N + 1):
        dp_left = dp[n][0]  # dp[n][k - 1]
        for k in range(1, K + 1):
            val = dp_left + dp[n - 1][k]
            kk = k - A[n - 1] - 1
            if kk >= 0:
                val -= dp[n - 1][kk]
            val %= MOD
            dp[n][k] = val
            dp_left = val
    print(dp[N][K])


if __name__ == '__main__':
    main()