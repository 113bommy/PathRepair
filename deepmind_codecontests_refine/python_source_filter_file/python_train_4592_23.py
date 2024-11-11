t = int(input())
N = 1000000
import math

primes = [True] * (N+1)
primes[0] = primes[1] = False

for i in range(2, N+1):
    if primes[i]:
        for j in range(i*i, N+1, i):
            primes[j] = False

def prime(v):
    if v < N:
        return primes[v]
    for i in range(2, 100):
        if v % i == 0:
            return False
    return True

def ok(a, b):
    a1, b1 = a - b, a + b
    if a1 == 1 and prime(b1):
        return True
    return False


for i in range(t):
    a, b = list(map(int, input().split()))
    if ok(a, b):
        print('YES')
    else:
        print('NO')

