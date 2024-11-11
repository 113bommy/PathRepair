# -*- coding: utf-8 -*-
import math
import sys

n, m = map(int, input().split())

if math.fabs(n - m) == 1:
    k = 1
if n == m:
    k = 2
else:
    k = 0

print(math.factorial(n) % 1000000007 * math.factorial(m) % 1000000007 * k % 1000000007)
