n,a,b,k=map(int,input().split())
mod=998244353
ans=0
p=[1]*(n+1)
for i in range(n):
    p[i+1]=((i+1)*p[i])%mod
for ai in range(n+1):
    if k-a*ai>=0 and (k-a*ai)%b==0:
        bi=(k-a*ai)//b
        if bi<=n:
            ans+=p[n]*pow(p[ai],mod-2,mod)*pow(p[n-ai],mod-2,mod)*p[n]*pow(p[bi],mod-2,mod)*pow(p[n-bi],mod-2,mod)
            ans%=mod
print(ans)
