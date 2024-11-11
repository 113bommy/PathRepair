r1, c1, r2, c2 = map(int, input().split())
MOD = 10 ** 9 + 7

g1 = [1, 1]
g2 = [1, 1]
inverse = [0, 1]

def func(r, c):
    if c == 0:
        return r + 1
    return comb(r + c + 2, c + 1, MOD)

def comb(n, r, mod):
    return (g1[n] * g2[r] * g2[n - r]) % mod

for i in range(2, r2 + c2 + 10):
  g1.append((g1[-1] * i) % MOD)
  inverse.append((-inverse[MOD % i] * (MOD // i) ) % MOD)
  g2.append((g2[-1] * inverse[-1]) % MOD)

print((func(r2, c2) - func(r1 - 1, c2) - func(r2, c1 - 1) + func(r1 - 1, c1 - 1)) % MOD)