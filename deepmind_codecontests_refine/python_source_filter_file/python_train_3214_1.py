n, c = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
MOD = 10**9 + 7

dp = [[0]*(c+1) for i in range(n+1)]
dp[0][0] = 1

ruiseki = [[0] * (402) for _ in range(c+1)]
for i in range(c + 1):
    for j in range(400):
        ruiseki[i][j + 1] = ruiseki[i][j] + pow(j, i, MOD)
        ruiseki[i][j + 1] %= MOD
  
for i in range(n):
    for all_num in range(c + 1):
        for j in range(all_num + 1):
            # i番目の子供に、j個の飴を配る
            dp[i+1][all_num] += (ruiseki[j][b[i]+1] - ruiseki[j][a[i]]) * dp[i][all_num - j]
            dp[i+1][all_num] %= MOD
print(dp[-1][-1])