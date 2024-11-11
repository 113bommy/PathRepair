import sys
input = sys.stdin.readline

N, M = map(int, input().split())
S = list(map(int, input().split()))
T = list(map(int, input().split()))
mod = 10**9+7

dp = [[0 for _ in range(N+1)] for _ in range(M+1)]

for i in range(M):
    for j in range(N):
        if S[j] == T[i]:
            dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] + 1
        else:
            dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j]
        dp[i+1][j+1] %= mod

ans = (dp[M][N] + 1) % mod
print(ans)