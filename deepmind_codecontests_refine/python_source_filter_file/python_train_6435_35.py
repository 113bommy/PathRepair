K, = map(int, input().split())
D, = map(int, input().split())
N = len(str(K))
M = 10**9+7
dp = [[0]*D for _ in range(N+1)]
dp2 = [[0]*D for _ in range(N+1)]
dp[0][0] = 1
dp2[0][0] = 1
for i in range(1, N+1):
    Ki = K%10
    K //= 10
    for j in range(D):
        for k in range(10):
            dp[i][(j+k)%D] = (dp[i][(j+k)%D] + dp[i-1][j])%M
        for k in range(Ki):
            dp2[i][(j+k)%D] = (dp2[i][(j+k)%D] + dp[i-1][j])%M
        dp2[i][(j+Ki)%D] = (dp2[i][(j+Ki)%D] + dp2[i-1][j])%M
print(dp2[N][0]-1)