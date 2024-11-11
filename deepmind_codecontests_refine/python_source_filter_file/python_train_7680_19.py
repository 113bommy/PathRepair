import sys
from functools import lru_cache

sys.setrecursionlimit(10 ** 7)

MOD = 10 ** 9 + 7

@lru_cache
def combination(n, k):
    if k == 0:
        return 1
    else:
        return ((combination(n, k-1) * (n-k+1) % MOD) * pow(k, MOD-2, MOD)) % MOD

n, k = map(int, input().split())

s = 0
for m in range(0, min(k+1, n)):
    s += combination(n, min(m, n - m)) * combination(n - 1, min(m, n - m - 1))
    s %= MOD

print(s)