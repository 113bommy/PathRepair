mod = 10**9+7
n, k = map(int, input().strip().split())
dp = [[0 for i in range(n)] for i in range(k)]
for i in range(n):
    dp[0][i] = 1

for i in range(k-1):
    for j in range(n):
        for p in range(j+1, n+1, j+1):
            dp[i+1][p-1] = (dp[i+1][p-1] + dp[i][j])%mod
# print('----')
# for i in dp:
#     print(i)
print(sum(dp[-1])%mod)

