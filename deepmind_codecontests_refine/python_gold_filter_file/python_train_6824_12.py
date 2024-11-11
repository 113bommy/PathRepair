inf = float('inf')
n = int(input())
c = [int(x) for x in input().split()]
a = []
for i in range(n):
    a.append(input())

dp = [[inf,inf] for i in range(n)]
dp[0][0] = 0
dp[0][1] = c[0]
for i in range(1,n):
    dp[i][0] = min(dp[i-1][0] if a[i]>=a[i-1] else inf,dp[i-1][1] if a[i]>=a[i-1][::-1] else inf)
    dp[i][1] = min((dp[i-1][0] +c[i])if a[i][::-1]>=a[i-1] else inf, (dp[i-1][1]+c[i])if a[i][::-1]>=a[i-1][::-1] else inf)

ans  = min(dp[-1])
print(-1 if ans==inf else ans)




