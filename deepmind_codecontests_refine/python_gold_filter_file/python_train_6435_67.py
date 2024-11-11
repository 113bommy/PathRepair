K = input()
D = int(input())
L = len(K)
MOD = 10**9+7
dp = [[[0]*D for j in range(2)] for i in range(L+1)] #dp[i][less][modD]
dp[0][0][0] = 1
for i,c in enumerate(K):
    for less in range(2):
        lim = 9 if less else int(c)
        for r in range(D):
            for d in range(lim+1):
                dp[i+1][less or d < lim][(r+d)%D] += dp[i][less][r]
                dp[i+1][less or d < lim][(r+d)%D] %= MOD

print((dp[-1][0][0] + dp[-1][1][0] - 1) % MOD)