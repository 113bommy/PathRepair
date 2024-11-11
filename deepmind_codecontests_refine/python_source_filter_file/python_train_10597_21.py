n,m=map(int,input().split())
a,c=[],[]
for _ in range(m):
  a.append(list(map(int,input().split()))[0])
  c.append(sum((1<<(int(i)-1)) for i in input().split()))
inf=float('inf')
dp=[inf]*(1<<n)
dp[0]=0
for i in range(2**n):
  for j in range(m):
    dp[i|c[j]]=min(dp[i|c[j]],dp[i]+a[j])
print(dp[-1] if inf!=dp[-1] else-1)
