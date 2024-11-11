# Aizu Problem 00150: Twin Prime
#
import sys, math, os, bisect

# read input:
PYDEV = os.environ.get('PYDEV')
if PYDEV=="True":
    sys.stdin = open("sample-input.txt", "rt")


def primes2(n):
    """ Input n>=6, Returns a list of primes, 2 <= p < n """
    n, correction = n-n%6+6, 2-(n%6>1)
    sieve = [True] * (n//3)
    for i in range(1,int(n**0.5)//3+1):
      if sieve[i]:
        k=3*i+1|1
        sieve[      k*k//3      ::2*k] = [False] * ((n//6-k*k//6-1)//k+1)
        sieve[k*(k-2*(i&1)+4)//3::2*k] = [False] * ((n//6-k*(k-2*(i&1)+4)//6-1)//k+1)
    return [2,3] + [3*i+1|1 for i in range(1,n//3-correction) if sieve[i]]

primes = primes2(10000)

while True:
    n = int(input())
    if n == 0:
        break
    idx = bisect.bisect_left(primes, n)
    while True:
        if idx == len(primes):
            idx -= 1
        if primes[idx] >= n:
            idx -= 1
        if primes[idx] - primes[idx - 1] == 2:
            print(primes[idx - 1], primes[idx])
            break
        idx -= 1