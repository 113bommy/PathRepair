MOD = 10**9+7
MAXN = 5*(10**5)+5
f = [1]
for i in range(MAXN):
    f.append(f[-1] * (i+1) % MOD)
def nCr(n, r, mod=MOD):
    return f[n] * pow(f[r], mod-2, mod) * pow(f[n-r], mod-2, mod) % mod

def nPr(n, r, mod=MOD):
    return f[n] * pow(f[n-r], mod-2, mod) % mod

n, m = map(int, input().split())
ans = 0
for k in range(n+1):
    tmp = nPr(m-k, n-k)
    tmp *= tmp
    tmp %= MOD
    tmp *= nPr(m, k)
    tmp %= MOD
    tmp *= nCr(n,k)
    tmp %= MOD
    if k%2:
        ans -= tmp
    else:
        ans += tmp
ans += MOD
ans %= MOD
print(ans)