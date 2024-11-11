mod = 10**9 + 7

N,M = map(int,input().split())
S = input().split()
T = input().split()

dp = [[-1]*(M+1) for _ in range(N+1)]
dp[0][0] = 1
for i in range(1,N+1):
    dp[i][0] = 1
for j in range(1,M+1):
    dp[0][j] = 1

for i in range(1,N+1):
    for j in range(1,M+1):
        if S[i-1] == T[j-1]:
            dp[i][j] = dp[i][j-1] + dp[i-1][j]
        else:
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1]
        dp[i][j] %= mod

ans = dp[N][M]
print(ans)