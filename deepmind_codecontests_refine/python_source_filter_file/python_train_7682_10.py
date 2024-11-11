n,m,k=map(int,input().split())
mod=10**9+7
f=[1]
for i in range(2*10**5+7):f+=[f[-1]*(i+1)%mod]
def comb(a,b):return f[a]*pow(f[b],mod-2,mod)*pow(f[a-b],mod-2,mod)%mod
ans=0
for i in range(1,n):
  ans+=(i*(n-i)*m**2)*(comb(n+m-2,k-2))
  ans%=mod
for i in range(1,m):
  ans+=(i*(m-i)*n**2)*(comb(n+m-2,k-2))
  ans%=mod
print(ans)