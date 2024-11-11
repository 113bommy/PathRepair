r1,c1,r2,c2 = map(int,input().split())

# 二項係数 mod P

mod = 10**9+7

m = r2+c2 +10 
fac = [1]*m
ninv = [1]*m
finv = [1]*m
for i in range(2,m):
    fac[i] = fac[i-1]*i%mod
    ninv[i] = (-(mod//i)*ninv[mod%i])%mod
    finv[i] = finv[i-1]*ninv[i]%mod

def comb(n,k):
    return (fac[n]*finv[k]%mod)*finv[n-k]%mod


def g(r,c):
    ret = 0
    for i in range(0,r+1):
        ret += comb(i+c+1,i+1)
        ret %= mod
    return ret

ans = g(r2,c2) - g(r1-1,c2) - g(r2,c1-1) + g(r1-1,c1-1)
print(ans)