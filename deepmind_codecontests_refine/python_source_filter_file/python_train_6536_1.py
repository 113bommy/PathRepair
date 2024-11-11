r1, c1, r2, c2 = map(int, input().split())
mod = int(1e+9) + 7
def inved(x):
  a, b, c, d, k, l = 1, 0, 0, 1, x, mod
  while l != 0:
    a, b, c, d = c, d, a - c * (k // l), b - d * (k // l)
    k, l = l, k & l
  return a % mod
frac = [1]
for i in range(r2 + c2 + 2):
  frac.append(((i+1) * frac[i]) % mod)
fracr2c2 = frac[r2 + c2 + 2]
fracr1c2 = frac[r1 + c2 + 1]
fracr2c1 = frac[r2 + c1 + 1]
fracr1c1 = frac[r1 + c1]
fracr2 = frac[r2 + 1]
fracr1 = frac[r1]
fracc2 = frac[c2 + 1]
fracc1 = frac[c1]
g = 0
g += (fracr2c2 * inved(fracr2) * inved(fracc2)) % mod
g %= mod
g += (fracr1c1 * inved(fracr1) * inved(fracc1)) % mod
g %= mod
g -= (fracr1c2 * inved(fracr1) * inved(fracc2)) % mod
g %= mod
g -= (fracr2c1 * inved(fracr2) * inved(fracc1)) % mod
g %= mod
print(g)