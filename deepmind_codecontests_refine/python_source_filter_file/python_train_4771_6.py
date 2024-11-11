n=int(input())
l9=list(9**i for i in range(1,3))
l6=list(6**j for j in range(1,8))
l=sorted(l9+l6)
dp=[_ for _ in range(100010)]
for k in l:
    for m in range(k,n+1):
        dp[m]=min(dp[m-k]+1,dp[m])
print(dp[n])