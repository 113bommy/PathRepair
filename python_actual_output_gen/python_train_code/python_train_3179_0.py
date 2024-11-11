n,k=map(int,input().split())
mod=10**9+7
f=[1]
for i in range(n):
    f+=[f[-1]*(i+1)%mod]
print(f)
def combination(a,b):
    return f[a]*pow(f[b],mod-2,mod)*pow(f[a-b],mod-2,mod)%mod

a=list(map(int,input().split()))
a.sort()
b=a[::-1]
ans=0
for i in range(k-1,n):
    ans+=((a[i]-b[i])*(combination(i,k-1)))%(10**9+7)
print(ans%(10**9+7))