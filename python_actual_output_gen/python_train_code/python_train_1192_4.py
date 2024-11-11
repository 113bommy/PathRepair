n, k = map(int, input().split())
mod = 998244353
g1 = [1, 1]
g2 = [1, 1]
inv = [0, 1]
for i in range(2, n+1):
    g1.append((g1[-1] * i) % mod)
    inv.append((-inv[mod%i] * (mod//i)) % mod)
    g2.append((g2[-1] * inv[-1]) % mod)

def comb(n, r):
    if r<0 or r>n:
        return 0
    return g1[n] * g2[r] * g2[n-r] % mod

ans = 0
for i in range(1, n+1):
    ans += comb(n//i-1, k-1)
print(ans)