n,*c=map(int,open(0).readlines())
l=[-1]*2**18
b=[]
for i in range(n):
  b.append(l[c[i]])
  l[c[i]]=i
dp=[1]+[0]*n
for i in range(1,n):
  dp[i]=dp[i-1]
  if c[i]!=c[i-1]and b[i]>-1:
    dp[i]=(dp[i]+dp[b[i]])%(10**9+7)
print(dp[-2])