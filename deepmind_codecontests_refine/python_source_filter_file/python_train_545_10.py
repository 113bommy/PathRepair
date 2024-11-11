import sys

#comment these out later
#sys.stdin = open("in.in", "r")
#sys.stdout = open("out.out", "w")

import operator as op
from functools import reduce


def gcd(x, y):
    """greatest common divisor of x and y"""
    while y:
        x, y = y, x % y
    return x


def chinese_remainder(a, p):
    """returns x s.t. x = a[i] (mod p[i]) where p[i] is prime for all i"""
    prod = reduce(op.mul, p, 1)
    x = [prod // pi for pi in p]
    return sum(a[i] * pow(x[i], p[i] - 2, p[i]) * x[i] for i in range(len(a))) % prod


def extended_gcd(a, b):
    """returns gcd(a, b), s, r s.t. a * s + b * r == gcd(a, b)"""
    s, old_s = 0, 1
    r, old_r = b, a
    while r:
        q = old_r // r
        old_r, r = r, old_r - q * r
        old_s, s = s, old_s - q * s
    return old_r, old_s, (old_r - old_s * a) // b if b else 0


def composite_crt(b, m):
    """returns x s.t. x = b[i] (mod m[i]) for all i"""
    x, m_prod = 0, 1
    for bi, mi in zip(b, m):
        g, s, _ = extended_gcd(m_prod, mi)
        if ((bi - x) % mi) % g:
            return None
        x += m_prod * (s * ((bi - x) % mi) // g)
        m_prod = (m_prod * mi) // gcd(m_prod, mi)
    return x % m_prod


inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1

p = n-1

ar = inp[ii:ii+n]

if n == 1:
	x = ar[0]
	print(1, 1)
	print(0)
	print(1, 1)
	print(0)
	print(1, 1)
	print(-x)
	exit()

#first operation

toprint1 = ["0"]
toprint2 = []


for x in ar[1:]:
	target = composite_crt([x, 0], [n, n-1])
	toadd = target - x

	toprint1.append(str(toadd))
	toprint2.append(str(target))

print(1, n)
print(" ".join(toprint1))

#second operation

print(1, 1)
print(-ar[0])

#third operation

print(2, n)
print(" ".join(toprint2))



