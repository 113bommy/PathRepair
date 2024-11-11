N, W = map(int, input().split())
MV = (10**3)*N+1
MV = 100
dp = [[0] + [10**18]*(MV-1) for _ in range(N+1)]
dp[0][0] = 0
for i in range(1, N+1):
    w, v = map(int, input().split())
    for j in range(1, MV):
        dp[i][j] = min(dp[i-1][j], dp[i-1][max(0, j-v)]+w)
for i in range(MV):
    if dp[N][MV-i-1] <= W:
        print(MV-i-1)
        break
#print(dp[N][W])
