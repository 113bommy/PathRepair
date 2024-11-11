n,k,*p=map(int,open(0).read().split())
s=[p[0]]*n
for i in range(1,n):
  s[i]=s[i-1]+p[i]
ans=0
for i in range(n-k):
  ans=max(ans,s[i+k]-s[i])
print((ans+k)/2)