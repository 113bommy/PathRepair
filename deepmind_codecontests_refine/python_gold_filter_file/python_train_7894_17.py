#! /usr/bin/env python3
import math
N, M = map(int, input().split())
n = math.factorial(N)
m = math.factorial(M)
if N == M:
    print(n * m * 2 % (10**9+7))
elif abs(N - M) > 1:
    print(0)
else:
    print(n * m % (10**9+7))