s = int(input())
MOD = 10000007
MAXN = 1000
dp = [[1] + [0 for i in range(MAXN)] for j in range(MAXN + 1)]
for i in range(1, MAXN + 1):
    for j in range(1, i + 1):
        dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD
ans = 1
acum = 0
for i in range(s):
    x = int(input())
    ans = (ans * dp[acum + x - 1][x - 1]) % MOD
    acum += x
print(ans)