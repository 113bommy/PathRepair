from math import gcd, sqrt


def prime_factor(n):
    factors = []
    for i in range(2, int(sqrt(n))+1):
        if n % i == 0:
            factors.append(i)
            while n % i == 0:
                n //= i
    if n != 1:
        factors.append(n)
    return factors


def count_multiples(n, primes):
    n -= 1
    count = 0
    for bits in range(1, 1 << len(primes)):
        x = 1
        c = 0
        for i in range(len(primes)):
            if bits >> i & 1:
                c += 1
                x *= primes[i]
        count += (n // x) * (-1)**(c+1)
    return count


T = int(input())
for _ in range(T):
    a, m = map(int, input().split())
    g = gcd(a, m)
    primes = prime_factor(m//g)
    print(m//g-count_multiples((a+m)//g, primes)+count_multiples(a//g, primes))
