N, M = map(int, input().split())
mod = 10**9 + 7

def comb(n, r, mod):
    if r<0 or r>n:
        return 0
    r = min(r, n-r)
    return fac[n] * (finv[r] * finv[n-r] % mod) % mod

def perm(n, r, mod):
    if r<0 or r>n:
        return 0
    return (fac[n] * finv[n-r]) % mod

fac = [1, 1]
finv = [1, 1]
inv = [0, 1]
for i in range(2, max(N + 1, M + 1)):
    fac.append((fac[-1] * i) % mod)
    inv.append((-inv[mod%i] * (mod//i)) % mod)
    finv.append((finv[-1] * inv[-1]) % mod)
for i in range(N+1):
    ans += (-1)**i * ((comb(N, i, mod) * perm(M, i, mod))%mod * (perm(M-i, N-i, mod)**2)%mod)%mod
    ans %= mod
print(ans)