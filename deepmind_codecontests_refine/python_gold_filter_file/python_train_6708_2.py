table = []

n, m = list(map(int, input().split()))

for i in range(n):
    painters = list(map(int, input().split()))
    table.append(painters)

dp = [[table[0][0]]]
result = []

for i in range(n):
    for j in range(m):
        if i == 0 and j > 0:
            dp[i].append(table[i][j] + dp[i][j-1])
        elif i > 0 and j == 0:
            dp.append([table[i][j] + dp[i-1][j]])
        elif i > 0 and j > 0:
            max_time = max(dp[i-1][j], dp[i][j-1])
            dp[i].append(table[i][j] + max_time)
        if j == (m - 1): result.append(str(dp[i][j]))

print(" ".join(result))