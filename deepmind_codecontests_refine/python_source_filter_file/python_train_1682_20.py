#!/usr/bin/env python3

import sys
from math import gcd

def solve(n, bcap, acap, s):
    loc = 0
    b = bcap
    a = acap
    while loc < n and a + b > 0:
        if a == acap or (a > 0 and s[loc] == 0) or b == 0:
            a -= 1
        else:
            b -= 1
            if s[loc] == 1 and a < acap:
                a += 1
        loc += 1
    return loc

n = 0
m = 0
x = None
p = None
for line in sys.stdin:
    if n == 0:
        n, m = tuple(map(int, line.split()))
    elif x == None:
        x = tuple(map(int, line.split()))
    else:
        p = tuple(map(int, line.split()))
        break

g = x[1] - x[0]
j = 2
while g > 1 and j < len(x):
    g = gcd(g, x[j] - x[j-1])
    j += 1

for j in range(len(p)):
    if g % p[j] == 0:
        print("YES")
        print("%d %d" % (x[0], j))
        break
else:
    print("NO")
