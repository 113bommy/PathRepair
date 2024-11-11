#配るDP
n,k=map(int,input().split())
l=[0]*k
r=[0]*k
for j in range(k):
  l[j],r[j] = map(int,input().split())
p=998244353
dp=[0]*(n+100)
dp[1]=1
dp[2]=-1
for i in range(1,n+1):
  dp[i] += dp[i-1]
  dp[i] %= p
  
  for lj,rj in zip(l,r):
    dp[i+lj] += dp[i]
    dp[i+lj] %= p
    dp[i+rj+1] -= dp[i]
    dp[i+rj+1] %= p
print(dp[n])