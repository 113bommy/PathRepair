def solve(K, D):
    N = len(K)
    MOD = 1_000_000_007
    dp = [[[0] * D for _ in range(2)] for _ in range(N + 1)]
    dp[0][0][0] = 1
    for i in range(N):
        for is_less in range(2):
            for k in range(D):
                for l in range(10 if is_less else K[i] + 1):
                    is_less_ = is_less or l < K[i]
                    k_ = (k + l) % D
                    dp[i + 1][is_less_][k_] += dp[i][is_less][k]
                    dp[i + 1][is_less_][k_] %= MOD
    return dp[N][0][0] + dp[N][1][0] - 1


print(solve(list(map(int, input())), int(input())))
