import sys
import math
import itertools
import collections


def ii(): return int(input())
def mi(): return map(int, input().split())
def li(): return list(map(int, input().split()))
def lcm(a, b): return abs(a * b) // math.gcd(a, b)
def wr(arr): return ' '.join(map(str, arr))
def revn(n): return str(n)[::-1]
def dd(): return collections.defaultdict(int)
def ddl(): return collections.defaultdict(list)
def sieve(n):
    if n < 2: return list()
    prime = [True for _ in range(n + 1)]
    p = 3
    while p * p <= n:
        if prime[p]:
            for i in range(p * 2, n + 1, p):
                prime[i] = False
        p += 2
    r = [2]
    for p in range(3, n + 1, 2):
        if prime[p]:
            r.append(p)
    return r
def divs(n, start=1):
    r = []
    for i in range(start, int(math.sqrt(n) + 1)):
        if (n % i == 0):
            if (n / i == i):
                r.append(i)
            else:
                r.extend([i, n // i])
    return r
def divn(n, primes):
    divs_number = 1
    for i in primes:
        if n == 1:
            return divs_number
        t = 1
        while n % i == 0:
            t += 1
            n //= i
        divs_number *= t
def prime(n):
    if n == 2: return True
    if n % 2 == 0 or n <= 1: return False
    sqr = int(math.sqrt(n)) + 1
    for d in range(3, sqr, 2):
        if n % d == 0: return False
    return True
def convn(number, base):
    newnumber = 0
    while number > 0:
        newnumber += number % base
        number //= base
    return newnumber
def cdiv(n, k): return n // k + (n % k != 0)


n = ii()
a = li()
if a[-1] > 5 * 10 ** 5 and a[0] <= 5 * 10 ** 5:
    i = 0
    l, r = 1, 10 ** 6
    while i < n:
        if a[i] <= 5 * 10 ** 5:
            l = a[i]
        i += 1
    i = n - 1
    while i > 0:
        if a[i] > 5 * 10 ** 5:
            r = a[i]
        i -= 1
    print(max(l - 1, 10 ** 6 - r))
elif a[-1] < 5 * 10 ** 5:
    print(a[-1] - 1)
else:
    print(10 ** 6 - a[0])
