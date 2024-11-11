import sys
import math

def primes(n):
    sieve = [1] * (n + 1)
    rt = int(math.sqrt(n))
    sieve[0] = sieve[1] = 0
    for p in range(2, rt + 1):
        if sieve[p] == 0:
            continue
        k = p * 2
        while k <= n:
            sieve[k] = 0
            k += p
    r = []
    for p in range(2, n + 1):
        if sieve[p] == 1:
            r.append(p)
    return r

def goldbach(prime, n):
    c = 0
    for p in prime:
        if p <= n - p and n - p in prime:
            c += 1
    return c

p = primes(2**14)
for line in sys.stdin:
    n = int(line)
    if n == 0:
        break
    c = goldbach(p, n)
    print(c)
