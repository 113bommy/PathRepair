import sys
import string

from collections import Counter, defaultdict
from math import fsum, sqrt, gcd, ceil, factorial
from operator import *
from itertools import accumulate

inf = float("inf")
# input = sys.stdin.readline
flush = lambda: sys.stdout.flush
comb = lambda x, y: (factorial(x) // factorial(y)) // factorial(x - y)


# inputs
# ip = lambda : input().rstrip()
ip = lambda: input()
ii = lambda: int(input())
r = lambda: map(int, input().split())
rr = lambda: list(r())


n, a, b, k = r()
arr = [rr() for _ in range(n)]

k = k / 100
k = 1 - k
brr = []

for i, j in arr:
    x = i * a * k + j * b
    y = j * a * k + b * i
    brr.append(max(x, y))

arr = brr[:]


arr = list(enumerate(arr, 1))
arr.sort(key=lambda x: x[1], reverse=True)

for i, j in arr:
    print(f"{i} {j:.2f}")
