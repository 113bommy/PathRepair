N, K = map(int, input().split())
H = [0] + list(map(int, input().split()))
dp = [[10 ** 100] * (N-K+1) for _ in range(N+1)]
dp[0][0] = 0
for x in range(1, N+1):
    for y in range(1, min(x+1, N-K+1)):
        dp[x][y] = min([dp[i][y-1] + max(0, H[x] - H[i]) for i in range(x)])
print(min([dp[i][N-K] for i in range(1, N+1)]))