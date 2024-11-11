n,m=map(int,input().split())
a=[int(input()) for i in range(m)]
mod=10**9+7
d=[mod]*(n+1)
d[0]=1;d[1]=1
for i in a:
  d[a]=0
for i in range(2,n+1):
  d[i]=min(d[i],(d[i-1]+d[i-2])%mod)
print(d[n])