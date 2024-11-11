import math
from operator import itemgetter


def get_primes(prime_supr):

    is_prime = [0]*2 + [1]*prime_supr

    for i in range(2,int(math.sqrt(prime_supr)) + 1):
        if is_prime[i]:
            for j in range(i * i, prime_supr + 1, i):
                is_prime[j] = 0

    return is_prime

get_int = lambda: map(int, input().split())

n = int(input())
a = list(get_int())
ans = 0
a.sort()
for i in range(1, n):
    if a[i] <= a[i-1]:
        ans += a[i-1] - a[i] + 1
        a[i] = a[i-1] + 1

print(ans, a)
