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
en = lambda x: list(enumerate(x))


# inputs
# ip = lambda : input().rstrip()
ip = lambda: input()
ii = lambda: int(input())
r = lambda: map(int, input().split())
rr = lambda: list(r())


arr = [rr() for _ in range(4)]
for i in range(4):
    if arr[i][3] and (
        arr[i][0]
        or arr[i][1]
        or arr[i][2]
        or arr[(i + 2) % 4][1]
        or arr[(i + 1) % 4][0]
        or arr[(i + 3) % 4][3]
    ):
        exit(print("YES"))

print("NO")