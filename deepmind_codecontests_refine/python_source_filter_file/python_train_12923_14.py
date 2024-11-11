#!/usr/bin/env python3

from math import sqrt, floor

n, b = map(int, input().split())

def find(n, factors):
    cnt = {}
    for k in factors:
        cnt[k] = 0
        i = k
        while n // i >= 1:
            cnt[k] += n // i
            i *= k
    return cnt

def factorize(n):
    factors = {}

    while n % 2 == 0:
        factors[2] = factors.get(2)+1 if factors.get(2) else 1
        n /= 2

    for i in range(3, floor(sqrt(n))+1, 2):
        while n % i == 0:
            factors[i] = factors.get(i)+1 if factors.get(i) else 1
            n /= i

    if n > 2:
        factors[int(n)] = 1

    return factors

if __name__ == "__main__":
    fk = factorize(b)
    fn = find(n, fk)
    m = 2**18

    for i in fk.keys():
        if not fn.get(i):
            print(0)
            exit(0)
        else:
            m = min(m, fn[i]//fk[i])

    print(m)
