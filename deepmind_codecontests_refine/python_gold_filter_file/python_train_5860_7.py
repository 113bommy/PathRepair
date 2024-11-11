
import math
# import sys
from collections import Counter, defaultdict, deque
MAX_N = 2000
MOD = 10**9 + 7
def modInverse(a, p):
    # Fermat's little theorem, a**(p-1) = 1 mod p
    # assert a % p != 0
    return pow(a, p - 2, p)


# Precompute all factorials: i!
fact = [1]
for i in range(1, MAX_N + 1):
    fact.append((fact[-1] * i) % MOD)

# Precompute all inverse factorials: 1 / (i!)
invFact = [0] * (MAX_N + 1)
invFact[MAX_N] = modInverse(fact[MAX_N], MOD)
for i in range(MAX_N - 1, -1, -1):
    invFact[i] = (invFact[i + 1] * (i + 1)) % MOD
    # assert fact[i] * invFact[i] % MOD == 1

# Precompute all inverses, 1 / i == (i - 1)! / i!
inv = [0] * (MAX_N + 1)
for i in range(1, MAX_N + 1):
    inv[i] = fact[i - 1] * invFact[i] % MOD
    # assert inv[i] * i % MOD == 1


def nCr(n, r):  # mod'd
    if n < r:
        return 0
    return (fact[n] * invFact[r] * invFact[n - r]) % MOD

def f(n, x, pos):
    cnts = 0
    cntb = 0
    left = 0
    right = n
    while(left < right):
        #print(left, right)
        middle = (left + right) // 2
        if middle > pos:
           cntb += 1
        if middle < pos:
            cnts += 1 
        if middle <= pos:
            left = middle + 1
        else:
            right = middle

    ans = (nCr(x-1, cnts) * nCr(n-x, cntb) * fact[n-cnts-cntb-1] * fact[cnts] * fact[cntb]) % MOD

    return ans


    

p = 10**9 + 7
t = 1
result = []
for i in range(t):
    n, x, pos = list(map(int, input().split()))
    result.append(f(n, x, pos))
for i in range(t):
    print(result[i])
