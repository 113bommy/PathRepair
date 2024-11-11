n, k = map(int, input().split())
mod = 10 ** 9 + 7
def comb(n, r):
    if n < r:return 0
    if n < 0 or k < 0:return 0
    return fa[n] * fi[r] % mod * fi[n - r] % mod
fa = [1] * (n + 1)
fi = [1] * (n + 1)
for i in range(1, n + 1):
    fa[i] = fa[i - 1] * i % mod
    fi[i] = pow(fa[i], mod - 2, mod)
ans = 0
for i in range(min(k, n - 1) + 1):
    ans += comb(n, i) * comb(n - 1, i) % mod
print(ans % mod)