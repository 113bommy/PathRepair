mod = 998244353

def comb(n, r):
    if 2 * r > n: return comb(n, n-r)
    return fac[n] * inv[r] * inv[n-r] % mod

n, a, b, k = map(int, input().split())

fac = [1] * (n+2)
inv = [1] * (n+2)
for i in range(2, n+1):
    fac[i] = fac[i-1] * i % mod
inv[n] = pow(fac[n], mod - 2, mod)
for i in range(n-1, 1, -1):
    inv[i] = inv[i + 1] * (i + 1) % mod

ans = 0
for i in range(n+1):
    Num = (k-a*i)
    if (0 <= Num//b) and (Num//b <= n) and (Num%b == 0):
      j = Num//b 
      ans += comb(n, i) * comb(n, j) 
print(ans%mod)