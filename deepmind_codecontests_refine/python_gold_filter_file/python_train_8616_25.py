# F - Strivore

K = int(input())
S = list(str(input()))
N = len(S)
MOD = 10**9+7

fac = [1, 1]
inv = [0, 1]
finv = [1, 1]

for i in range(2, N+K+1):
    fac.append(fac[-1] * i % MOD)
    inv.append(MOD - inv[MOD%i] * (MOD//i) % MOD)
    finv.append(finv[-1] * inv[-1] % MOD)

def comb_mod(n, r, m):
    if (n<0 or r<0 or n<r): return 0
    r = min(r, n-r)
    return fac[n] * finv[n-r] * finv[r] % m

ans = 0
for i in range(K+1):
    tmp = pow(25, i, MOD)
    tmp *= comb_mod(i+N-1, N-1, MOD)
    tmp *= pow(26, K-i, MOD)
    ans += tmp
    ans %= MOD
print(ans)

