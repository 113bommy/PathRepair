n,k=map(int,input().split())
mod=10**9+7
k=min(k,n-1)
ans=1
g=1
h=1
for i in range(k):
    g*=(n-i)*pow(i+1,mod-2,mod)
    g%=mod
    h*=(n-1-i)*pow(i+1,mod-2,mod)
    h%=mod
    ans+=g*h%mod
    ans%=mod
print(ans)
