n,k=map(int,input().split())
mod=10**9+7
f=[1]
for i in range(2*n):f+=[f[-1]*(i+1)%mod]
def comb(a,b):return f[a]*pow(f[b],mod-2,mod)*pow(f[a-b],mod-2,mod)%mod
ans=comb(2*n-1,n-1)
for i in range(n-1,k,-1):ans=(ans-comb(n,n-i)*comb(n-1,i))%mod
print(ans)
