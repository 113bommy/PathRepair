mod = 10 ** 9 + 7
class nCr():
    def __init__(self, n):
        self.n = n
        self.fa = [1] * (self.n + 1)
        self.fi = [1] * (self.n + 1)
        for i in range(1, self.n + 1):
            self.fa[i] = self.fa[i - 1] * i % mod
            self.fi[i] = pow(self.fa[i], mod - 2, mod)
    def comb(self, n, r):
        if n < r:return 0
        if n < 0 or r < 0:return 0
        return self.fa[n] * self.fi[r] % mod * self.fi[n - r] % mod
n, m, k = map(int, input().split())
ans = 0
c = nCr(n * m)
for i in range(n):
    ans += i * (n - i) * m * m
    ans %= mod
for i in range(m):
    ans += i * (m - i) * n * n
    ans %= mod
print(ans * c.comb(n * m - 2, k - 2) % mod)