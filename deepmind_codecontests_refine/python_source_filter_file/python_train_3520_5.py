n = int(input())
a = list(map(int, input().split()))


dp = [[0]*(n+1) for i in range(n+1)]

a_accum = [0]
for i in range(n):
    a_accum.append(a_accum[-1] + a[i])

for k in range(2, n+1):
    for i in range(n-k+1):
        mini = 10**10
        for j in range(i+1, i+k):
            mini = min(dp[i][j] + dp[j][i+k], mini)
        dp[i][i+k] = mini + a_accum[i+k]-a_accum[i]
print(dp[0][n])

