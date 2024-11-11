# -*- coding: utf-8 -*-
mod = 10 ** 9 + 7
n, m, k = map(int, input().split())
nm = n * m
fact = [1] * (nm + 1)

for i in range(1, nm + 1):
    fact[i] = fact[i - 1] * i


def C(n, k):
    x = fact[n]
    x *= pow(fact[n-k], mod - 2, mod)
    x %= mod
    x *= pow(fact[k], mod - 2, mod)
    x %= mod
    return x


def F(x):
    s1 = x * x * (x + 1) // 2
    s2 = x * (x + 1) * (2 * x + 1) // 6
    return (s1 - s2) % mod


res = (m ** 2 % mod * F(n) % mod + n ** 2 * F(m) % mod) % mod
res *= C(n * m - 2, k - 2)
res %= mod
print(res)
