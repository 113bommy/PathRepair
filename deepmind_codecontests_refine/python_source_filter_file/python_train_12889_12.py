n, W = map(int,input().split())
dp = [W+1]*(10**5 + 1)
maxv=0
for i in range(n):
  w,v= map(int,input().split())
  for j in range(10**5-v,-1,-1):
  	cw=w+dp[j]
  	if cw<=W:
  		dp[j+v]=min(dp[j+v],cw)
  		maxv=max(maxv,j+v)
print(maxv)