import sys
import string

from collections import Counter, defaultdict
from math import fsum, sqrt, gcd, ceil, factorial
from operator import add

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


n, k = r()
arr = rr()
brr = rr()

arr = arr[::-1]
brr = brr[::-1]

i = j = c = 0

while i < n and j < k:
    if brr[j] >= arr[i]:
        i += 1
        j += 1
    else:
        c += 1
        i +=1
        
print(c)