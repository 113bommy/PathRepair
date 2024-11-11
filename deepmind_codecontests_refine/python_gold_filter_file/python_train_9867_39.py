a, b, c, d = [int(x) for x in input().split()]
dp = [[0 for i in range(d + 1)] for j in range(c + 1)]
for i in range(a+1):
    for j in range(b+1):
        dp[i][j]=1
for i in range(a, c + 1):
    for j in range(b, d + 1):
        if i == a and j == b:
            continue
        if i - 1 >= a:
            dp[i][j] += (dp[i - 1][j] * j)
        if j - 1 >= b:
            dp[i][j] += (dp[i][j - 1] * i)
        if (i - 1) >= a and (j - 1) >= b:
            dp[i][j] -= dp[i-1][j-1]*(i-1)*(j-1)
        dp[i][j] %= 998244353

print(dp[c][d])
