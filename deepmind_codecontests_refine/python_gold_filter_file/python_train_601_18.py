N, M = map(int,input().split())
S = list(map(int,input().split()))
T = list(map(int,input().split()))

MOD = 10**9 + 7

# dp[i+1][j+1] : S_iまで，T_jまでで作ることのできる共通部分列の数
dp = [[0] * 2010 for _ in range(2010)]
dp[0][0] = 1

for i in range(N+1):
    for j in range(M+1):
        if i > 0: dp[i][j] += dp[i-1][j]
        if j > 0: dp[i][j] += dp[i][j-1]
        if i > 0 and j > 0:
            dp[i][j] -= dp[i-1][j-1]
            if S[i-1] == T[j-1]: dp[i][j] += dp[i-1][j-1]
        dp[i][j] = (dp[i][j] + MOD) % MOD

print(dp[N][M])