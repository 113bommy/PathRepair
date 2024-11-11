import sys
import math
import bisect
from sys import stdin, stdout
from math import gcd, floor, sqrt, log
from collections import defaultdict as dd
from bisect import bisect_left as bl, bisect_right as br
from collections import Counter
from collections import defaultdict as dd

# sys.setrecursionlimit(100000000)

flush = lambda: stdout.flush()
stdstr = lambda: stdin.readline()
stdint = lambda: int(stdin.readline())
stdpr = lambda x: stdout.write(str(x))
stdmap = lambda: map(int, stdstr().split())
stdarr = lambda: list(map(int, stdstr().split()))

mod = 1000000007

def sieve(n):

    prime = [True for _ in range(n+1)]
    p = 2

    while(p*p <= n):
        if(prime[p] == True):

            for i in range(p*p, n+1, p):
                prime[i] = False

        p += 1

    return prime


# for _ in range(stdint()):
n,k = stdmap()

all = sieve(n)

# print(all)

primes = []

for i in range(1, len(all)):
    if(all[i] == True):
        primes.append(i)

s = Counter(primes)

res = 0

for i in range(len(primes)-1):
    toCheck = primes[i]+primes[i+1]+1

    if(toCheck in s):
        res += 1

if(res == k):
    print("YES")
else:
    print("NO")
