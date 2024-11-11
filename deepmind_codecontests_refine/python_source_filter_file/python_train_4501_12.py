#!/usr/bin/env python3

import sys
from math import *
from collections import defaultdict
from queue import deque                # Queues
from heapq import heappush, heappop    # Priority Queues
M = 998244353
invcache = {}

# parse
lines = [line.strip() for line in sys.stdin.readlines()]
n, m = list(map(int, lines[0].split()))

# precompute
facts = [1]
pows = [1]
for i in range(1, m+1):
  facts += [facts[-1] * i % M]
  pows += [pows[-1] * 2 % M]

# mod inv
def gcdext(a, b):
  if a == 0:
    return b, 0, 1
  gcd, x, y = gcdext(b % a, a)
  return gcd, y - (b//a) * x, x

def modinv(a):
  if a in invcache:
    return invcache[a]
  
  g, x, y = gcdext(a, M)
  assert(g == 1)
  x %= M
  invcache[a] = x
  return x

def choose(a, b):
  if a < b:
    return 0
  if b == 0:
    return 1
  if b == 1:
    return a
  return facts[a] * modinv(facts[b]) % M * modinv(facts[a-b]) % M

ret = 0
for k in range(n-1, m+1):
  ret = (ret + choose(k-1, 1) * choose(k-2, n-3) % M * pows[n-3]) % M
print(ret)
