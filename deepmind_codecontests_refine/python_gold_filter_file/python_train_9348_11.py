n,k = map(int,input().split())
mod = 10**9+7

dp = [[0]*(k+1) for i in range(k+1)]
dp[0][0] = 1

for i in range(1,k+1):
    for j in range(1,i+1):
        dp[i][j] = (dp[i-1][j]*(i+j-1)+dp[i-1][j-1]*(n-k-j+2))//i

for i in range(1,k+1):
    print(dp[-1][i]%mod)
