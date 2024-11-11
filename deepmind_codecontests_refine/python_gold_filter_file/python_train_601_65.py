mod = 10**9+7
from bisect import bisect
from collections import defaultdict
N,M = map(int,input().split())
S = list(map(int,input().split()))
T = list(map(int,input().split()))

dp = [[0]*(M+1) for _ in range(N+1)]

for n in range(N):
    for m in range(M):
        dp[n][m] = dp[n-1][m]+dp[n][m-1]-dp[n-1][m-1]
        if S[n]==T[m]:
            dp[n][m] += dp[n-1][m-1]+1
        dp[n][m] %= mod

print(dp[N-1][M-1]+1)