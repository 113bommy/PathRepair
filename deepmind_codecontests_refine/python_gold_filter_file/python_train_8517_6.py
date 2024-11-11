N = int(input())

MOD = 10**9+7
fac = [1,1] + [0]*N
finv = [1,1] + [0]*N
inv = [0,1] + [0]*N
for i in range(2,N+2):
    fac[i] = fac[i-1] * i % MOD
    inv[i] = -inv[MOD%i] * (MOD // i) % MOD
    finv[i] = finv[i-1] * inv[i] % MOD

def ncr(n,r):
    if n < r: return 0
    if n < 0 or r < 0: return 0
    return fac[n] * (finv[r] * finv[n-r] % MOD) % MOD

ans = 0
prev = 0
for k in range((N+1)//2, N):
    tmp = ncr(k-1, N-1-k) * fac[k] * fac[N-1-k]
    tmp %= MOD
    ans += (tmp - prev) * k
    ans %= MOD
    prev = tmp
print(ans)