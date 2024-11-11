N,M = map(int, input().split())
Ss = list(map(int, input().split()))
Ts = list(map(int, input().split()))
mod = 10**9 + 7

x = 2160
dp = [[0]*x for i in range(x)]
for i in range(N):
    for j in range(M):
        if Ss[i] == Ts[j]:
            dp[i+1][j+1] = (dp[i][j+1] + dp[i+1][j] + 1) % mod
        else:
            dp[i+1][j+1] = (dp[i][j+1] + dp[i+1][j] - dp[i][j])%mod

print((dp[N][M]+1)%mod)