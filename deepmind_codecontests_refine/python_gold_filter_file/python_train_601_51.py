N,M = map(int,input().split())
S = list(map(int,input().split()))
T = list(map(int,input().split()))
mod = 10**9+7

dp = [[0]*(M+1) for i in range(N+1)]
dps = [[0]*(M+1) for i in range(N+1)]
for n in range(N):
    for m in range(M):
        if S[n] == T[m]:
            dp[n+1][m+1] = (dps[n][m]+1)%mod
        dps[n+1][m+1] = (dp[n+1][m+1]+dps[n+1][m]+dps[n][m+1]-dps[n][m])%mod

print(dps[-1][-1]+1)
