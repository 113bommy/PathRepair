def cmb(n, r, mod):
    if (r < 0) or (n < r):
        return 0
    r = min(r, n - r)
    return fact[n] * factinv[r] * factinv[n-r] % mod
mod = 10**9 + 7
fact = [1, 1]
factinv = [1, 1]
inv = [0,1]

k = int(input())
s = input()
t = len(s)
n = k + t
for i in range(2,n+1):
    fact.append((fact[-1] * i) % mod)
    inv.append((inv[mod % i] * (mod - (mod // i))) % mod)
    factinv.append((factinv[-1] * inv[-1]) % mod)
ans = 0
for i in range(k+1):
    ans += (cmb(k-i+t-1,t-1,mod)*pow(25,k-i,mod)*pow(26,i,mod))%mod
    ans %= mod
print(ans)