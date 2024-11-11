n = int(input())
a = list(map(int,input().split()))

for i in range(n):
    a[i] = [a[i],i]
l1 = 0
r1 = n-1
l2 = l1
r2 = r1
a.sort(reverse=1)
dp = [[0]*(n+1) for i in range(n+1)]
ans = 0
for i in range(1,n+1):
    dp[i][0] = dp[i-1][0] + a[i-1][0] * abs(a[i-1][1]-i+1)
    dp[0][i] = dp[0][i-1] + a[i-1][0] * abs(n-(a[i-1][1])-i)
    for j in range(1,i):
        dp[j][i-j] = max(dp[j-1][i-j]+a[i-1][0]*abs(a[i-1][1]-j+1),dp[j][i-j-1]+a[i-1][0]*abs(n-(a[i-1][1])-(i-j)))
for i in dp:
    ans = max(ans,max(i))
print(ans)