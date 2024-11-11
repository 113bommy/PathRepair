n = int(input())
p = list(map(float,input().split()))
dp = [[0 for x in range(n+1)] for x in range(n+1)]
dp[0][0] = 1
for y in range(n):
    for x in range(n):
        dp[y+1][x] += dp[y][x]*(1-p[y])
        dp[y+1][x+1] += dp[y][x]*p[y]
print(sum(dp[n][n//2+1:n+1]))
