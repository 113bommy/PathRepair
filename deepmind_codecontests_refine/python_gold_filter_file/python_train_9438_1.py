[n, k] = [int(x) for x in input().split()]
sum = [int(x) for x in input().split()]
for i in range(1, n):
    sum[i] += sum[i - 1]

def check(mask, all):
    dp = [[False for j in range(n)] for i in range(k)]
    for i in range(n):
        dp[0][i] = ((sum[i] & all & mask) == mask)
    for i in range(1, k):
        for j in range(n):
            dp[i][j] = any(dp[i - 1][p] and ((sum[j] - sum[p]) & all & mask) == mask for p in range(0, j))
    return dp[k - 1][n - 1]
    

ans = 0
for i in range(60, -1, -1):
    if(check(ans | (1 << i), ~((1 << i) - 1))):
       ans |= 1 << i
print(ans)

