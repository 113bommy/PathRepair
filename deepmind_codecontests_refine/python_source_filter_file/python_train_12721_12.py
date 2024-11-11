import sys
import itertools
import math
import collections
from collections import Counter

#########################
# imgur.com/Pkt7iIf.png #
#########################

def sieve(n):
    prime = [True for i in range(n + 1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * 2, n + 1, p):
                prime[i] = False
        p += 1
    prime[0] = prime[1] = False
    r = [p for p in range(n + 1) if prime[p]]
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
def ceil(n, k): return n // k + (n % k != 0)
def ii(): return int(input())
def mi(): return map(int, input().split())
def li(): return list(map(int, input().split()))
def lcm(a, b): return abs(a * b) // math.gcd(a, b)
def prr(a, sep=' '): print(sep.join(map(str, a)))
def dd(): return collections.defaultdict(int)

w = [0]*10001
p = []
for i in range(9):
    p.append(3**i)

c = 0
for i in range(1, len(p) + 1):
    for j in list(itertools.combinations(p, i)):
        c += 1
        if sum(j) <= 10000:
            w[sum(j)] = sum(j)
w[10000] = 19683
print(c)

for i in range(9999, -1, -1):
    if w[i] == 0: w[i] = w[i + 1]

t = ii()
for i in range(t):
    n = ii()
    print(w[n])





