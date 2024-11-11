N,K = map(int,input().split())
a = [0]*110
a[1:] = list(map(int,input().split()))
MOD = 10**9+7
dp = [[0]*110000 for _ in range(110)]
dp_sum = [[0]*110000 for _ in range(110)]
dp[0][0] = 1
for i in range(K+1):
    dp_sum[0][i] = 1

for i in range(1,N+1):
    for j in range(K+1):
        dp[i][j] = dp_sum[i-1][j]
        if j - a[i]-1 >= 0:
            dp[i][j] -= dp_sum[i-1][j-a[i]-1]

        if j-1 >= 0:
            dp_sum[i][j] = dp_sum[i][j-1] + dp[i][j]
        else:
            dp_sum[i][j] = dp[i][j]
        dp[i][j] %= MOD
        dp_sum[i][j] %= MOD
print(dp[N][K])
# for i in range(N+1):
#     print(dp[i])