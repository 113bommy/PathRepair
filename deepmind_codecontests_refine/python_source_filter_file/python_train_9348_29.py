from math import factorial

N, K = map(int, input().split())
mod = 10**9 + 1

def cmb(n, r):
    if n >= r:
        return int(factorial(n) // (factorial(r) * factorial(n-r)))
    else:
        return 0

for i in range(1, K+1):
    print(cmb(N-K+1, i) * cmb(K-1, i-1) % mod)