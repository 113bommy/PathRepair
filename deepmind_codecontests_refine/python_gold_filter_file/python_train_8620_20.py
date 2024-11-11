def solve():
    MOD = 10**9 + 7

    N = int(input())
    Ass = [tuple(map(int, input().split())) for _ in range(N)]

    dp = [0] * (1<<N)
    dp[0] = 1
    for S in range((1<<N)-1):
        dp[S] %= MOD
        iM = bin(S).count('1')
        for iW in range(N):
            if S & (1<<iW) == 0 and Ass[iM][iW]:
                S2 = S ^ (1<<iW)
                dp[S2] += dp[S]

    print(dp[-1] % MOD)


solve()
