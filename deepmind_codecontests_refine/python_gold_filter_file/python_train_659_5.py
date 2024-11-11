import sys
INF = 10**20
MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))
from math import gcd
from math import ceil
from collections import defaultdict as dd, Counter
from bisect import bisect_left as bl, bisect_right as br


"""
Facts and Data representation
Constructive? Top bottom up down
"""
y, k, n = I()
if y == n:
  print(-1)
else:
  x = k - y % k
  if x == 0:
    x += k
  if x + y > n:
    print(-1)
  else:
    while x + y <= n:
      print(x, end = ' ')
      x += k