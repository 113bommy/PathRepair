n,k,p=map(int,input().split()),998244353
r=range
f=[1]
for i in r(k):f+=[-~i*f[i]]
print(sum(f[-1]*pow(f[i]*f[-1-i],-1,p)for i in r(n-1,k))%p)