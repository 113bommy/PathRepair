n, a = map(int, input().split())
l = [int(i) for i in input().split()]

dp = [[[0] * 2501 for j in range(51)] for i in range(51)]

dp[0][0][0] = 1

for i in range(n):
    for j in range(51):
        for k in range(2501):
            if k >= l[i] and j >= 1:
                dp[i+1][j][k] = dp[i][j][k] + dp[i][j-1][k-l[i]]
            else:
                dp[i+1][j][k] = dp[i][j][k]

print(sum([dp[n][m][a*m] for m in range(1, n+1)]))