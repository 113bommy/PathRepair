for _ in range(int(input())):
    _ = int(input())
    # n *= 2
    *t, = map(int, input().split())
    t.sort()
    # dp[idx][time]
    inf = float('inf')
    n = max(t) * 2 + 10
    dp = [[inf] * (n) for _ in range(len(t) + 1)]
    for i in range(n):
        dp[0][i] = 0

    for i in range(len(t)):
        for prev_t in range(n):
            for next_t in range(prev_t + 1, n):
                if dp[i][prev_t] != inf:
                    dp[i + 1][next_t] = min(dp[i + 1][next_t], dp[i][prev_t] + abs(next_t - t[i]))
    # print(t)
    # print(dp)
    print(min(dp[len(t)]))


