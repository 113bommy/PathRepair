n = int(input())
A = list(map(int, input().split()))

if n == 1:
    print(1)
    exit()

dp = [[0]*4 for i in range(n)]
if A[0] == 1:
    dp[0][0] += 1
    dp[0][2] += 1
else:
    dp[0][1] += 1
    dp[0][3] += 1
for i in range(1, n):
    if A[i] == 1:
        dp[i][0] = dp[i-1][0]+1
        dp[i][1] = max(dp[i-1][1], dp[i-1][0])
        dp[i][2] = max(dp[i-1][1]+1, dp[i-1][2]+1)
        dp[i][3] = max(dp[i-1][3], dp[i-1][2])
    else:
        dp[i][0] = dp[i-1][0]
        dp[i][1] = max(dp[i-1][0]+1, dp[i-1][1]+1)
        dp[i][2] = max(dp[i-1][2], dp[i-1][1])
        dp[i][3] = max(dp[i-1][2]+1, dp[i-1][3]+1)
print(max(dp[n-1]))
