class Factorial:
    def __init__(self, n, mod):
        self.f = [1]
        self.mod = mod
        for j in range(1, n + 1):
            self.f.append(self.f[-1] * j % mod)
        self.i = [pow(self.f[-1], mod - 2, mod)]
        for j in range(n, 0, -1):
            self.i.append(self.i[-1] * j % mod)
        self.i.reverse()
    def factorial(self, j):
        return self.f[j]
    def ifactorial(self, j):
        return self.i[j]
    def comb(self, n, k):
        return self.f[n] * self.i[n - k] % self.mod * self.i[k] % self.mod if n >= k else 0


N, A, B, K = map(int, input().split())
MOD = 998244353

c = Factorial(N + 1, MOD).comb

def calc(a, b):
    return (c(N, a) * c(N, b)) % MOD

ans = 0
for a in range(N + 1):
    b = (K - (A * a)) // B
    if A * a + B * b == K and b <= N:
        ans += calc(a, b)
        ans %= MOD

print (ans)
