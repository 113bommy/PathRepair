# http://codeforces.com/problemset/problem/478/B
import operator as op
from functools import reduce

def ncr(n, r):
    if n < r:
        return 0.0
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer / denom

n, m = map(int, input().split())

rem = n % m
min_combo = (ncr(n // m, 2) * (m - rem)) + (ncr(n // m + 1, 2) * rem)
max_combo = ncr(n - m + 1, 2)

print(int(min_combo), int(max_combo))