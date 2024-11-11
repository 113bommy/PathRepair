class ModComb:
    def __init__(self, MAX, mod=10 ** 9 + 7):
        fac = [1, 1]
        finv = [1, 1]
        inv = [0, 1]
        for i in range(2, MAX):
            fac.append(fac[i - 1] * i % mod)
            inv.append(mod - inv[mod % i] * (mod // i) % mod)
            finv.append(finv[i - 1] * inv[i] % mod)
        self.fac, self.finv, self.mod = fac, finv, mod

    def nCk(self, n, k):
        if n < k or n < 0 or k < 0:
            return 0
        fac, finv, mod = self.fac, self.finv, self.mod
        return fac[n] * (finv[k] * finv[n - k] % mod) % mod

mod = 10 ** 9 + 7

r1, c1, r2, c2 = map(int, input().split())

mc = ModComb(r2 + c2 + 10)
def f(i, j):
    return mc.nCk(i + j, i)

print((f(r2 + 1, c2 + 1) - f(r2 + 1, c1) - f(r1, c2 + 1) + f(r1, c1)) % mod)