n,k=map(int,input().split())
a=[int(i) for i in input().split()]
dp=[np.inf]*n
dp[0]=0
dp[1]=abs(a[1]-a[0])

for i in range(2,n):
    for j in range(max(0,i-k),i):
        dp[i]=min(dp[j]+abs(a[i]-a[j]),dp[i])
print(dp[-1])