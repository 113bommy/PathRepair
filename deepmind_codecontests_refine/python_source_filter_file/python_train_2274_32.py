from math import gcd
from functools import reduce

N, K = map(int, input().split())
A = list(map(int, input().split()))

d = reduce(gcd, A)
print('POSSIBLE' if K <= max(A) and K % d == 0 else 'IMPOSSIBLE')
