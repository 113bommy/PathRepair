from itertools import groupby
from functools import reduce
from operator import xor

s = input()
k = int(input())
r = len(s) * k // 2
a = [reduce(xor, (1 for _ in g)) for _, g in groupby(s)]
if len(a) > 1:
  r -= sum(a) * k // 2
  if s[0] == s[-1] and a[0] & a[-1]:
    r += k - 1
print(r)
