def solve():
    MOD = 10**9 + 7

    N = int(input())
    Ass = [tuple(map(int, input().split())) for _ in range(N)]

    dp = [0] * (1<<N)
    dp[0] = 1
    for S in range(1, 1<<N):
        iM = bin(S).count('1') - 1
        for iW in range(N):
            if S & (1<<iW) and Ass[iM][iW]:
                S0 = S ^ (1<<iW)
                dp[S] += dp[S0]
        dp[S] %= MOD

    print(dp[-1])


solve()
