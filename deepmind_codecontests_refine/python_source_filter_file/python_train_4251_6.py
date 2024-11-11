N,M = list(map(int,input().split()))

MAXN = (10**5)+10
p = 10**9+7
MOD = p
f = [1]
for i in range(MAXN):
    f.append(f[-1] * (i+1) % MOD)
def nCr(n, r, mod=MOD):
    return f[n] * pow(f[r], mod-2, mod) * pow(f[n-r], mod-2, mod) % mod

def prime(X):
    pf={}
    m=X
    for i in range(2,int(m**0.5)+1):
        while m%i==0:
            pf[i]=pf.get(i,0)+1
            m//=i
    if m>1:pf[m]=1
    return pf

pf = prime(M)
powers = list(pf.values())

out = 1
for power in powers:
    out = out*nCr(power+N-1,power)%p

print(out)