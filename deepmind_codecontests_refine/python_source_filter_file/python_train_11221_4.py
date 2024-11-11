f=lambda:map(int,input().split())
h,n=f()
dp=[0]+[10**9]*h
for i in range(n):
  a,b=f()
  for j in range(h+1): dp[j]=min(dp[j],dp[j-a]+b)
print(dp[h])