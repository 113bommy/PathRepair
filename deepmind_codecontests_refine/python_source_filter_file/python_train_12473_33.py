n=int(input())
h=list(map(int,input(),split()))
dp=[0]*n
dp[1]=abs(h[1]-h[0])
for i in range(2,n,1):
  dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]))
print(dp[n-1])