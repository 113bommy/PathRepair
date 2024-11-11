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


arr = "C, C#, D, D#, E, F, F#, G, G#, A, B, H".split(", ")
n = len(arr)

s = ip().split()
s = [arr.index(i) for i in s]
s.sort()
ans = (s[1] - s[0], s[2] - s[1])
# print(ans)
if ans in ((3, 4), (3, 5), (4, 5)):
    print("minor")
elif ans in ((4, 3), (5, 3), (5, 4)):
    print("major")
else:
    print("strange")