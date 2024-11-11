def COMinit():
    fac[0] = fac[1] = 1
    finv[0] = finv[1] = 1
    inv[1] = 1
    for i in range(2,max):
        fac[i] = fac[i-1]*i%mod
        inv[i] = mod - inv[mod%i]*(mod//i)%mod
        finv[i] = finv[i-1]*inv[i]%mod

def COM(n,k):
    if n < k:
        return 0
    if n < 0 or k < 0:
        return 0
    return fac[n] * (finv[k]*finv[n-k]%mod)%mod

mod = 10**9+7

K = int(input())
S = input()
N = len(S)
max = N+K
fac = [0] * max
finv = [0] * max
inv = [0] * max
COMinit()

ans = 0
for i in range(K+1):
    x = COM(N+K-i-1,N-1)
    y = mod(26,i,mod)
    z = mod(25,K-i,mod)
    xyz = ((x*y%mod)*z)%mod
    ans = (ans+xyz)%mod
print(ans)
