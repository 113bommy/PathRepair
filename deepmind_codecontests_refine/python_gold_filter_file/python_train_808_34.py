n,*a=map(int,open(0).read().split())
mod=10**9+7
ans=0
for j in range(60):
  cnt=0
  for i in range(n):
    cnt+=a[i]&1
    a[i]=(a[i]>>1)
  ans+=(cnt*(n-cnt)%mod)*pow(2,j,mod)
  ans%=mod
print(ans)