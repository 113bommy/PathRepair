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
s = list(ip())
c = 0
for i in range(n - k):
    if s[i] == s[i + k] != ".":
        c += 1

    if s[i] == s[i + k] == ".":
        s[i] = "0"
        s[i + k] = "1"
    else:
        if s[i] == ".":
            s[i] = "1" if s[i + k] == "0" else "0"
        else:
            s[i + k] = "1" if s[i] == "0" else "0"


if c == n - k:
    print("No")
else:
    s = "".join(s)
    s = s.replace(".", "0")
    print(s)