n = int(input())
s = input()
 
res = 0
dp = [[0]* (1+n) for _ in range(n+1)]
for i in range(n-1, -1, -1):
    for j in range(i+1, n):
        if s[i] == s[j]:
            dp[i][j] = dp[i+1][j+1] + (j - i > dp[i+1][j+1])
            res = max(res, dp[i][j]
print(res)