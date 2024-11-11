from math import factorial as f
mod = 998244353

n,m,k = map(int,input().split())

ans=1
for i in range(1,k+1):
    ans=(ans*i)%mod

ans=(ans*m)%mod

val = f(n-1)//(f(k)*f(n-1-k))

ans=(ans*val)%mod

print(ans)