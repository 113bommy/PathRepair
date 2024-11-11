from collections import defaultdict
import os,io
from sys import stdout
import math
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from fractions import Fraction
from decimal import *

def choose(n, k):
    """
    A fast way to calculate binomial coefficients by Andrew Dalke (contrib).
    """
    if 0 <= k <= n:
        ntok = 1
        ktok = 1
        for t in range(1, min(k, n - k) + 1):
            ntok *= n
            ktok *= t
            n -= 1
        return ntok // ktok
    else:
        return 0

def choose2(n, k):
    n = Decimal(n)
    k = Decimal(k)
    return Decimal(math.factorial(n)) / (Decimal(math.factorial(k)) * Decimal(math.factorial(n-k)))

n, m, t = list(map(int, input().split()))
s = 0
for i in range(1, m+1):
    fc = choose(m, i)
    boysToTake = t - i
    if boysToTake < 4 or boysToTake > n:
        continue
    bc = choose(n, boysToTake)
    s += fc * bc
print(s)
