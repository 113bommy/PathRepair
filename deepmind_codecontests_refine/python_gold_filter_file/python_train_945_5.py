from math import sqrt

n = int(input())

def prime_factors(n):
    factors = set()
    while n % 2 == 0:
        factors.add(2)
        n = n / 2

    for i in range(3,int(sqrt(n))+1,2):
        while n % i== 0:
            factors.add(i)
            n = n / i

    if n > 2:
        factors.add(n)

    return factors


a, b = tuple(map(int, input().split()))
factors = prime_factors(a).union(prime_factors(b))
for i in range(n-1):
    a, b = tuple(map(int, input().split()))
    if factors:
        new_factors = set()
        for f in factors:
            if a % f == 0 or b % f == 0:
                new_factors.add(f)
        factors = new_factors

print(int(factors.pop()) if factors else -1)
