import sys
input = sys.stdin.readline

N, M = map(int, input().split())
S = list(map(int, input().split()))
T = list(map(int, input().split()))
mod = 10**9 + 7

dp = [[0] * (M+1) for _ in range(N+1)]
for i in range(N+1):
    for j in range(M+1):
        if i == 0 or j == 0:
            dp[i][j] = 1
        elif S[i-1] == T[j-1]:
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod
        else:
            dp[i][j] = (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]) % mod
print(dp[-1][-1])