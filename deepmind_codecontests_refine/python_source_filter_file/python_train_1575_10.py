MOD = 998244353

def bpow(a, b):
    sol = 1
    while b:
        if b&1:
            sol*=a
            if sol>=MOD:
                sol%=MOD
        a*=a
        if a>=MOD:
            a%=MOD
        b>>=1
    return sol

fac = []
fac += [1]
for i in range(1,2001):
    fac.append(fac[i-1]*i%MOD)

ifac = []
for i in range(0,2001):
    ifac.append(bpow(fac[i],MOD-2))

def nCr(a, b):
    return fac[a]*ifac[a-b]*ifac[b]%MOD




n,m,k = map(int,input().split())

print (nCr(n+k-2,k)*m*bpow(m-1,k)%MOD)