mod = 998244353
N, S = map(int, input().split())
A = list(map(int, input().split()))
dp = [[0]*(S+1) for _ in range(N+1)]
dp[0][0] = 1
for i in range(1,N+1):
    dp[i][0] = dp[i-1][0]*2%mod

for i in range(1,N+1):
    for j in range(1,S+1):
        dp[i][j] = dp[i-1][j]*2%mod
        if j>=A[i-1]:
            dp[i][j] += dp[i-1][j-A[i-1]]

ans = dp[-1][-1]%mod
print(ans)
