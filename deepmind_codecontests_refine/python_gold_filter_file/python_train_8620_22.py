def solve():
    MOD = 10**9 + 7

    N = int(input())
    Ass = [tuple(map(int, input().split())) for _ in range(N)]

    dp = [[0]*(1<<N) for _ in range(N+1)]
    dp[0][0] = 1
    for iM in range(N):
        for S in range(1<<N):
            if dp[iM][S]:
                dp[iM][S] %= MOD
                for iW in range(N):
                    if S & (1<<iW) == 0 and Ass[iM][iW]:
                        S2 = S ^ (1<<iW)
                        dp[iM+1][S2] += dp[iM][S]

    print(dp[-1][-1] % MOD)


solve()
