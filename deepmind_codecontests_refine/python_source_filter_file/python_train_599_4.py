n,s=map(int,input().split())
a=list(map(int,input().split()))
dp=[0]*6007
ans=0
for i in range(n):
  for j in range(s,0,-1):dp[a[i]+j]+=dp[j]
  d[a[i]]+=i
  ans+=d[s]
print(ans%998244353)