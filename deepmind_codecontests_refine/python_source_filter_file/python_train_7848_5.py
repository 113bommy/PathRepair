#!/usr/bin/python3

import sys
from fractions import Fraction

n = int(sys.stdin.readline())
a = [int(x) for x in sys.stdin.readline().strip().split()]

s1 = sum(a)
p = [0 for i in range(n)]
c = [1 for i in range(n)]
for i in range(1, n):
    p[i] = (a[i] - a[i-1]) * c[i-1] + p[i-1]
    c[i] += c[i-1]
s2 = 2*sum(p)

ans = Fraction(s1 + s2, n)
print("{0} {1}".format(ans.numerator, ans.denominator))
