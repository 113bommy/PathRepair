n = int(input())
a = list(map(int, input().split()))
ai = [[a_, i] for i, a_ in enumerate(a)]
ai.sort(reverse=True)

# dp[i][j] 左端からi個、右端からj個を入れた場合の最適
dp = [[0]*(n+1) for _ in range(n+1)]

for i in range(n):
    for j in range(n-i):
        dp[i+1][j] = max(dp[i+1][j], dp[i][j] + ai[i+j][0] * (ai[i+j][1] - i))
        dp[i][j+1] = max(dp[i][j+1], dp[i][j] + ai[i+j][0] * ((n-1-j) - ai[i+j][1]))
ans = 0    
for i in range(n):
    ans = max(ans, dp[i][n-i])
print(ans)