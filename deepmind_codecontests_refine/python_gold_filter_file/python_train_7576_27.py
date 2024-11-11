from fractions import gcd
from functools import reduce

lcm = lambda a, b: b // gcd(a, b) * a
mod = 10 ** 9 + 7

N, *A = map(int, open(0).read().split())

L = reduce(lcm, A) % mod
print(sum(L * pow(a, mod - 2, mod) for a in A) % mod)