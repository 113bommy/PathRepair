import sys
import string

from collections import Counter, defaultdict
from math import fsum, sqrt, gcd, ceil, factorial
from itertools import combinations, permutations

# input = sys.stdin.readline
flush = lambda: sys.stdout.flush
comb = lambda x, y: (factorial(x) // factorial(y)) // factorial(x - y)


# inputs
# ip = lambda : input().rstrip()
ip = lambda: input()
ii = lambda: int(input())
r = lambda: map(int, input().split())
rr = lambda: list(r())


a, b, x, y = r()
arr = []
for i in range(x,a+1):
    for j in range(y,i):
        arr.append([i,j])
        
print(len(arr))
for i in arr:
    print(*i)