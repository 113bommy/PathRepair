N = int(input())
p = list(map(float,input().split()))

dp = [[0]*(N+1) for _ in range(N+1)]
dp[0][0] = 1
#dp[i][j] i枚投げた時 j枚 表が出る確率
for i in range(1,N+1):
    for j in range(i+1):
        dp[i][j] = dp[i-1][j-1]*p[i-1] + dp[i-1][j]*(1-p[i-1])
print(sum(dp[N][(N+1)//2:]))