from math import gcd
from itertools import accumulate

input()
a = list(map(int, input().split()))
b = list(accumulate(a, gcd))
c = list(accumulate(reversed(a), gcd))
print(max(b[-2], c[-2], *map(gcd, b[:-2], c[-3::-1])))
