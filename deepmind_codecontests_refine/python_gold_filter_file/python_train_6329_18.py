n,k=map(int,input().split())
a=list(map(int,input().split()))
mod=10**9+7
srt=sorted(a)
b=[]
for i in range(n):
  b.append(srt.index(a[i]))
ans=0
for j in range(n):
  ans+=((b[j]+b[j]*k)*k//2)%mod
res=0
for ii in range(n):
  for ij in range(ii+1):
    if a[ii]>a[ij]:
      res+=1
print((ans-res*k)%mod)