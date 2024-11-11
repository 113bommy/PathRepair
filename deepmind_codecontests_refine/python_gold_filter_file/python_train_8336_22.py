#!/usr/bin/env python3
import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf') ;mod = 10**9+7
mans = inf ;ans = 0 ;count = 0 ;pro = 1

n = int(input())
A = list(map(int,input().split()))
beki = []
two_beki = 1
while two_beki<=3 * 10**9:
  beki.append(two_beki)
  two_beki *= 2
C = collections.Counter(A)
for i,ai in enumerate(A):
  for candi in beki:
    if C[candi-ai] - int(candi-ai == ai):
      break
  else:count += 1
print(count)