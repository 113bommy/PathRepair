n=int(input())
a=[[int(_),0] for _ in input().split()]
for i in range(n): a[i][1]=i
a.sort(reverse=True)
dp=[[0 for _ in range(n)] for __ in range(n)]
for l in range(n):
    for r in range(n):
        if l+r < n:
            if l<n-1:dp[l+1][r]=max(dp[l+1][r], dp[l][r]+a[l+r][0]*abs(a[l+r][1]-l))
            if r<n-1:dp[l][r+1]=max(dp[l][r+1], dp[l][r]+a[l+r][0]*abs(a[l+r][1]-(n-r-1)))
print(max([dp[i][n-i] for i in range(1,n)]))