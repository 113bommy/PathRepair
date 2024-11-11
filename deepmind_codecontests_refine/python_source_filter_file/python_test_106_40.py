import itertools
from math import floor, log, log2, ceil, sqrt
from itertools import groupby
from decimal import Decimal,getcontext
import sys
from collections import deque
 

primes = set()
maxN = 1000001
def generatePrimes():
  used = [False] * maxN
  for i in range(2, maxN):
    if not used[i]:
      primes.add(i)
      for j in range(i, maxN, i):
        used[j] = True
def isPrime(n):
  if n < 2:
    return True
  x = 2
  while x * x <= n:
    if n % x == 0:
      return False
    x += 1
  return True

t = int(input())
res = []
# generatePrimes()
for _ in range(t):
  n = int(input())
  # [n, e] = list(map(int, input().split()))
  ans = " ".join(map(str, range(2, n + 2)))
  print(ans)
  
  # print(" ".join(map(str, ans)))
  # print(ans)
  res.append(ans)
 
for i in range(t):
  print(res[i])