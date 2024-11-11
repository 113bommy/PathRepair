h,n=map(int,input().split())
A=[list(map(int,input().split())) for i in range(n)]
ma=max(a for a,b in A)
dp=[0]*(h+ma)
for i in range(h+ma):
  dp[i]=min(dp[i-a]+b for a,b in A)
print(min(dp[h:]))