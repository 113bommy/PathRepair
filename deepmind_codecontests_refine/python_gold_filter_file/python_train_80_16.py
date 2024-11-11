n,m = map(int,input().split())
a = set([int(input()) for _ in range(m)])
dp=[0]*(n+1)
dp[0]=1
dp[1]=0 if 1 in a else 1
for i in range(2,n+1):
  dp[i]=(dp[i-1]+dp[i-2])%(10**9+7)
  if i in a: dp[i]=0

print(dp[n])